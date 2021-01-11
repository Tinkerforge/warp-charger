import $ from "jquery";

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
        data: JSON.stringify(null)
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
    $('#alert_placeholder').html(`<div class="alert ${cls} alert-dismissible fade show" role="alert" style="position: absolute; top: 0; left: 0px; right: 0px; z-index: 9999;">
            <strong>${title}</strong> ${text}
            <button type="button" class="close" data-dismiss="alert" aria-label="Close">
              <span aria-hidden="true">&times;</span>
            </button>
          </div>`);

    if(cls.indexOf("success") >= 0) {
        setTimeout(() => $('#alert_placeholder').html(""), 10000);
    }
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
