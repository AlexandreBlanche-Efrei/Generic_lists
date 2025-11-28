#ifndef STRUCT_H
#define STRUCT_H
// modifier la constante FILE_H

/////////////////////////////
// A modifier
#define T int
#define STRUCT_NAME str_int
#define GET_FUNCTION get_str_int
#define SET_FUNCTION set_str_int
// idem pour toutes les fonctions
/////////////////////////////

// A ne pas modifier

typedef struct {
    T content;
} STRUCT_NAME;

T GET_FUNCTION (STRUCT_NAME *s);
void SET_FUNCTION (STRUCT_NAME *s, T val);

#endif