#include "gen_list.h"

#include <stdio.h>
#include <stdlib.h>

void print_int_(const int n) {
    printf("%d", n);
}

IMPLEMENT_GENERIC_LIST(int)

void print_string_(const string s) {
    printf("\"%s\"", s);
}

IMPLEMENT_GENERIC_LIST(string)