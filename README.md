# Generic_lists

This code defines two generic structures, for a given type ``T``:

- A structure ``str_T`` with a single field ``content`` containing a ``T`` value
- A double-ended linked list ``t_T_list``, containing ``T`` values. A custom function ``void print_T_(const T)`` associated with the type ``T`` needs to be defined in ``gen_list.c`` for each instanciation of the type.

The types are instanciated at compile time, and their code is written once, in a similar manner to C++ templates.

The ``main`` function defines two variables of generic type ``str_int`` and ``str_string`` respectively, then two linked lists containing ``int`` and ``string`` (``char *``) values respectively.