#ifndef STRUCT_FLOAT_H
#define STRUCT_FLOAT_H

/////////////////////////////
#define T float
#define STRUCT_NAME str_float
#define GET_FUNCTION get_str_float
#define SET_FUNCTION set_str_float
/////////////////////////////

// A ne pas modifier

typedef struct {
    T content;
} STRUCT_NAME;

T GET_FUNCTION (STRUCT_NAME *s);
void SET_FUNCTION (STRUCT_NAME *s, T val);

#endif