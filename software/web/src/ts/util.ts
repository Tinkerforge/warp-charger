import $ from "jquery";


declare function __(s: string): string;

/* Helper interface to silence typescript error about the data member of server sent events not existing.
   Use like this:
   eventSource.addEventListener('eventName', function (e: SSE) {
       console.log(e.data);
   }, false);
*/
export interface SSE extends Event{
    data: string;
}

export function reboot() {
    $.ajax({
        url: '/reboot',
        method: 'PUT',
        contentType: 'application/json',
        data: JSON.stringify(null),
        success: () => postReboot(__("util.reboot_title"), __("util.reboot_text"))
    });
}

export function update_button_group(button_group_id: string, index_to_select: number, text_replacement?: string) {
    let buttons = $("#" + button_group_id + " :button");
    let color_suffixes = Array(buttons.length);
    for (let i = 0; i < buttons.length; ++i) {
        let classes = buttons[i].classList;
        for (let j = 0; j < classes.length; ++j) {
            if (classes[j].substring(0, 4) != "btn-")
                continue
            let splt = classes[j].split("-");
            color_suffixes[i] = splt[splt.length - 1];
        }
    }

    for (let i = 0; i < buttons.length; ++i) {
        buttons[i].classList.remove("btn-" + color_suffixes[i]);
        buttons[i].classList.add("btn-outline-" + color_suffixes[i]);
    }

    buttons[index_to_select].classList.remove("btn-outline-" + color_suffixes[index_to_select]);
    buttons[index_to_select].classList.add("btn-" + color_suffixes[index_to_select]);
    if (text_replacement != null)
        buttons[index_to_select].innerHTML = text_replacement;
}

export function show_alert(cls: string, title: string, text: string) {
    $('#alert_placeholder').html(`<div class="alert ${cls} alert-dismissible fade show custom-alert" role="alert" style="line-height: 1.5rem;">
            <strong>${title}</strong> ${text}
            <button type="button" class="close" data-dismiss="alert" aria-label="Close">
              <span aria-hidden="true">&times;</span>
            </button>
          </div>`);
}

export function hide_alert() {
    $('#alert_placeholder').html("");
}

export function format_timespan(secs: number) {
    let days = 0;
    let hours = 0;
    let mins = 0;

    let dayString = "";
    let hourString = "";
    let minString = "";
    let secString = "";

    if (secs >= 60 * 60 * 24) {
        days = Math.floor(secs / (60 * 60 * 24));
        if (days > 1) {
            dayString = days + ` ${__("days")}, `;
        } else if (days > 0) {
            dayString = days + ` ${__("day")}, `;
        }
        secs %= 60 * 60 * 24;
    }

    if (secs >= 60 * 60) {
        hours = Math.floor(secs / (60 * 60));
        if (hours >= 10) {
            hourString = hours + ":";
        } else {
            hourString = "0" + hours + ":";
        }
        secs %= 60 * 60;
    } else {
        hourString = "00:";
    }

    if (secs >= 60) {
        mins = Math.floor(secs / 60);
        if (mins >= 10) {
            minString = mins + ":";
        } else {
            minString = "0" + mins + ":";
        }
        secs %= 60;
    } else {
        minString = "00:";
    }

    if (secs >= 10) {
        secString = secs.toString();
    } else {
        secString = "0" + secs;
    }

    return dayString + hourString + minString + secString;
}

export function toLocaleFixed(i: number, fractionDigits: number) {
    return i.toLocaleString(undefined, {
        minimumFractionDigits: fractionDigits,
        maximumFractionDigits: fractionDigits
    });
}

export function toggle_password_fn(input_name: string) {
    return () => {
        let input = <HTMLInputElement>$(input_name)[0];
        if (input.type == 'password')
            input.type = 'text';
        else
            input.type = 'password';
    }
}



let eventSourceReconnectTimeout: number = null;
let eventSource: EventSource = null;

const RECONNECT_TIME = 5000;

export function setupEventSource(first: boolean, keep_as_first: boolean, continuation: (eventSource: EventSource) => void) {
    if (!first) {
        show_alert("alert-warning",  __("util.event_connection_lost_title"), __("util.event_connection_lost"))
    }
    console.log("Connecting to event source");
    if (eventSource != null) {
        eventSource.close();
    }
    eventSource = new EventSource('/events');

    if (eventSourceReconnectTimeout != null) {
        clearTimeout(eventSourceReconnectTimeout);
    }
    eventSourceReconnectTimeout = window.setTimeout(() => setupEventSource(keep_as_first ? first : false, keep_as_first, continuation), RECONNECT_TIME);

    eventSource.addEventListener('keep-alive', function (e) {
        if(!keep_as_first)
            hide_alert();
        clearTimeout(eventSourceReconnectTimeout);
        eventSourceReconnectTimeout = window.setTimeout(() => setupEventSource(keep_as_first ? first : false, keep_as_first, continuation), RECONNECT_TIME);
    }, false);

    continuation(eventSource);
}

export function postReboot(alert_title: string, alert_text: string) {
    eventSource.close();
    clearTimeout(eventSourceReconnectTimeout);
    show_alert("alert-success",alert_title, alert_text);
    // Wait 3 seconds before starting the reload/reconnect logic, to make sure the reboot has actually started yet.
    // Else it sometimes happens, that we reconnect _before_ the reboot starts.
    window.setTimeout(() => whenLoggedInElseReload(() =>
        setupEventSource(true, true, (eventSource) =>
                window.setTimeout(() =>
                // It is a bit of a hack to use version here, but
                // as opposed to keep-alive, version was already there in the first version.
                // so this will even work if downgrading to an version older than
                // 1.1.0
                eventSource.addEventListener('version', function (e) {
                    window.location.reload();
                }, false), 5000))
    ), 3000);
}

let loginReconnectTimeout: number = null;

export function ifLoggedInElseReload(continuation: () => void) {
    $.ajax({url: "/login_state", timeout:3000}).done(function(data, statusText, xhr){
        if (data == "Logged in") {
            continuation();
        } else {
            window.location.href = window.location.href
        }
    }).fail(function(xhr, statusText, errorThrown) {
        if (xhr.status == 404) {
            continuation();
        }
    });
}

export function whenLoggedInElseReload(continuation: () => void) {
    if (loginReconnectTimeout != null) {
        clearTimeout(loginReconnectTimeout);
        loginReconnectTimeout = null;
    }
    if (eventSourceReconnectTimeout != null) {
        clearTimeout(eventSourceReconnectTimeout);
        eventSourceReconnectTimeout = null;
    }
    loginReconnectTimeout = window.setTimeout(
        () => ifLoggedInElseReload(
            () => {clearTimeout(loginReconnectTimeout); continuation();}),
        RECONNECT_TIME);

    ifLoggedInElseReload(() => {clearTimeout(loginReconnectTimeout); continuation();});
}

// Password inputs use the empty string as the "unchanged" value.
// However the API expects a null value if the value should not be changed.
export function passwordUpdate(value: string) {
    return value.length > 0 ? value : null;
}
