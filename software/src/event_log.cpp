#include "event_log.h"

void EventLog::printfln(const char *fmt, ...)
{
    char buf[128];
    memset(buf, 0, sizeof(buf)/sizeof(buf[0]));

    va_list args;
    va_start (args, fmt);
    auto written = vsnprintf(buf, sizeof(buf)/sizeof(buf[0]), fmt, args);
    va_end (args);

    String t = String(millis());
    size_t to_write = 12 + written + 1; // 12 for the longest timestamp (-2^31) and a space; 1 for the \n

    Serial.print(t);
    for(int i = 0; i < 12 - t.length(); ++i)
        Serial.print(' ');
    Serial.print(buf);

    if (buf[written - 1] != '\n') {
        Serial.println("");
    }

    // Don't write the event buffer if it is currently read.
    if (sending_response)
        return;

    if (event_buf.free() < to_write) {
        drop(to_write - event_buf.free());
    }

    for(int i = 0; i < t.length(); ++i) {
        event_buf.push(t[i]);
    }
    for(int i = 0; i < 12 - t.length(); ++i)
        event_buf.push(' ');

    for(int i = 0; i < written; ++i) {
        event_buf.push(buf[i]);
    }
    if (buf[written - 1] != '\n') {
        event_buf.push('\n');
    }
}

void EventLog::drop(size_t count)
 {
    char c;
    for(int i = 0; i < count; ++i)
        event_buf.pop(&c);
    Serial.println(event_buf.used());

    while(event_buf.used() > 0 && c != '\n')
        event_buf.pop(&c);
    Serial.println(event_buf.used());
}

void EventLog::register_urls()
{
    server.on("/event_log", HTTP_GET, [this](AsyncWebServerRequest *request) {
        auto *response = request->beginChunkedResponse("text/plain", [this](uint8_t *buffer, size_t maxLen, size_t index) -> size_t {
            auto CHUNK_SIZE = 1024;
            //Write up to "maxLen" bytes into "buffer" and return the amount written.
            //index equals the amount of bytes that have been already sent
            //You will be asked for more data until 0 is returned
            //Keep in mind that you can not delay or yield waiting for more data!
            size_t to_write = MIN(MIN(CHUNK_SIZE, maxLen), event_buf.used() - index);

            sending_response = to_write != 0;

            for(int i = 0; i < to_write; ++i) {
                event_buf.peek_offset((char *)(buffer + i), index + i);
            }
            return to_write;
        });

        response->setCode(200);
        request->send(response);
    });
}
