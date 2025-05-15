# base64

A streaming encoder/decoder for base64 data

### Example:
```c
#include <ctype.h>
#include <stdio.h>
#include <string.h>

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
int main() {
    string_buffer_t buf;
    base64_context_t ctx;

    // encode
    buf.input = base64_decoded;
    char buffer[257];
    size_t len;
    int result;

    base64_init(string_read, &buf, &ctx);
    len = sizeof(buffer) - 1;
    do {
        result = base64_encode(&ctx, (uint8_t*)buffer, &len);
        buffer[len] = 0;
        fputs(buffer, stdout);
        fflush(stdout);
        len = sizeof(buffer) - 1;

    } while (result > 0);
    puts("");
    if (result < 0) {
        puts("error");
    } else {
        puts("done");
    }

    // decode
    buf.input = base64_encoded;
    base64_init(string_read, &buf, &ctx);
    len = sizeof(buffer) - 1;
    do {
        result = base64_decode(&ctx, (uint8_t*)buffer, &len);
        buffer[len] = 0;
        fputs(buffer, stdout);
        fflush(stdout);
        len = sizeof(buffer) - 1;

    } while (result > 0);
    puts("");
    if (result < 0) {
        puts("error");
    } else {
        puts("done");
    }

    return 0;
}
```

- Arduino repo: htcw_base64

- PlatformIO platformio.ini:
```
[env:node32s]
platform = espressif32
board = node32s
framework = arduino
lib_deps = 
	codewitch-honey-crisis/htcw_base64
```