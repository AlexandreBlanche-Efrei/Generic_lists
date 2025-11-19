#include <stdio.h>
#include <stdlib.h>
#include "gen_struct.h"
#include "function.h"
#include "gen_list.h"

int main() {

    /// Generic structures

    // str_int and str_string defined in gen_struct.h, implemented in gen_struct.c
    // typedef char* string defined in gen_struct.h

    printf("Generic structures:\n");

    str_int s;
    set_str_int(&s, 5);

    str_string t;
    set_str_string(&t, "abcd");
    printf("s : content = %d, t : content = %s\n", get_str_int(s), get_str_string(t));

    // function defined in function.c uses the same type str_int 
    printf("f(s) = %d\n", f(s));


    /// Generic lists

    // t_int_list and t_string_list defined in gen_list.h, implemented in gen_list.c

    printf("\nGeneric lists:\n");

    t_int_list li = create_empty_int_list();
    for (int i = 1; i <= 10; i++)
        push_back_int_list(&li, i);
    print_int_list(&li);
    destroy_int_list(&li);

    t_string_list ls = create_empty_string_list();
    push_front_string_list(&ls, "ABCD");
    push_front_string_list(&ls, "EFG");
    push_front_string_list(&ls, "HIJKL");
    push_front_string_list(&ls, "MNOP");
    print_string_list(&ls);
    destroy_string_list(&ls);

    return 0;
}