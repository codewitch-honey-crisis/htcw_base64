#include <Arduino.h>

#include "base64.h"
static const char* base64_encoded = "aGVsbG8gd29ybGQtLQ==";
static const char* base64_decoded = "hello world--";

typedef struct {
    const char* input;
} string_buffer_t;
static int string_read(void* state) {
    string_buffer_t* sb = (string_buffer_t*)state;
    if (sb->input == NULL) {
        return -1;
    }
    if (!*sb->input) {
        return -1;
    }
    return *(sb->input++);
}
void setup() {
    Serial.begin(115200);
    Serial.println("booted");
    string_buffer_t buf;
    base64_context_t ctx;
    
    // encode
    buf.input = base64_decoded;
    char buffer[256];
    size_t len;
    int result;

    base64_init(string_read, &buf, &ctx);
    len = sizeof(buffer) - 1;
    do {
        result = base64_encode(&ctx, (uint8_t*)buffer, &len);
        buffer[len] = 0;
        Serial.print(buffer);
        len = sizeof(buffer) - 1;

    } while (result > 0);
    Serial.println("");
    if (result < 0) {
        Serial.println("error");
    } else {
        Serial.println("done");
    }

    // decode
    buf.input = base64_encoded;
    base64_init(string_read, &buf, &ctx);
    len = sizeof(buffer) - 1;
    do {
        result = base64_decode(&ctx, (uint8_t*)buffer, &len);
        buffer[len] = 0;
        Serial.print(buffer);
        len = sizeof(buffer) - 1;

    } while (result > 0);
    Serial.println("");
    if (result < 0) {
        Serial.println("error");
    } else {
        Serial.println("done");
    }

    return 0;
}

void loop() {
  
}
