#include <stdio.h>

#include "struct_float.h"
#include "struct_string.h"

int main() {
    str_string s;
    str_float t;

    set_str_string(&s, "abcd");
    set_str_float(&t, 3.5);

    printf("s = { %s }, t = { %f }\n", get_str_string(&s), get_str_float(&t));

    return 0;
}