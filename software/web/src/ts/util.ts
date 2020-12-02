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
    $.get("/reboot");
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
