#ifndef GEN_STRUCT_H
#define GEN_STRUCT_H

#define INCLUDE_GENERIC_STRUCT(T)               \
    typedef struct {                            \
        T content;                              \
    } str_##T;                                  \
    T get_str_##T(str_##T s);                   \
    void set_str_##T(str_##T *s, T val);

#define IMPLEMENT_GENERIC_STRUCT(T)             \
                                                \
    T get_str_##T(str_##T s) {                  \
        return s.content;                       \
    }                                           \
    void set_str_##T(str_##T *s, T val) {       \
        s->content = val;                       \
    }                           

///////////////////////////////////////////

INCLUDE_GENERIC_STRUCT(int)

typedef char* string;
INCLUDE_GENERIC_STRUCT(string)
#endif