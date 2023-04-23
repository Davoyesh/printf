#include "main.h"
#define BUFFER_SIZE 1024

int _printf(const char *format, ...) {
    va_list args;
    int printed_chars = 0, buff_size = 0;
    char buffer[BUFFER_SIZE], *str;

    va_start(args, format);

    for (int i = 0; format[i]; i++) {
        if (format[i] != '%') {
            if (buff_size == BUFFER_SIZE) {
                write(1, buffer, buff_size);
                printed_chars += buff_size;
                buff_size = 0;
            }
            buffer[buff_size++] = format[i];
            continue;
        }

        switch (format[++i]) {
            case 'c':
                if (buff_size == BUFFER_SIZE) {
                    write(1, buffer, buff_size);
                    printed_chars += buff_size;
                    buff_size = 0;
                }
                buffer[buff_size++] = va_arg(args, int);
                break;

            case 's':
                str = va_arg(args, char*);
                for (int j = 0; str[j]; j++) {
                    if (buff_size == BUFFER_SIZE) {
                        write(1, buffer, buff_size);
                        printed_chars += buff_size;
                        buff_size = 0;
                    }
                    buffer[buff_size++] = str[j];
                }
                break;

            case '%':
                if (buff_size == BUFFER_SIZE) {
                    write(1, buffer, buff_size);
                    printed_chars += buff_size;
                    buff_size = 0;
                }
                buffer[buff_size++] = '%';
                break;

            default:
                return (-1);
        }
    }

    va_end(args);

    if (buff_size) {
        write(1, buffer, buff_size);
        printed_chars += buff_size;
    }

    return (printed_chars);
}
