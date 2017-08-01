#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <stdarg.h>

#define STRINGSZ(str) str, sizeof(str) - 1

#define PRINT_MALLOC(str, str_len) debug("%s: str ~ %.*s [%p]", "alloc memory", str_len, str, str)

void
debug(char *fmt, ...)
{
    printf("[DEBUG] ");
    va_list list;
    va_start(list, fmt);
    vprintf(fmt, list);
    va_end(list);

    puts("");
}

char *
str_alloc(const char *str, size_t size)
{
    char *buf = (char *)malloc(size);
    memcpy(buf, str, size);

    PRINT_MALLOC(buf, size);

    return buf;
}

int
main(int args, char **argv)
{
    char *tmp, *after;

    str_alloc(STRINGSZ("looool"));
    free( tmp = str_alloc(STRINGSZ("wwwwww")) );

    after = str_alloc(STRINGSZ("nonono"));
    printf("%s %s\n", tmp, after);
    return 0;
}