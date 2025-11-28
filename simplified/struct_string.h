#ifndef FILE_STRING_H
#define FILE_STRING_H

/////////////////////////////
typedef char* string;

#define T string
#define STRUCT_NAME str_string
#define GET_FUNCTION get_str_string
#define SET_FUNCTION set_str_string
/////////////////////////////

// A ne pas modifier

typedef struct {
    T content;
} STRUCT_NAME;

T GET_FUNCTION (STRUCT_NAME *s);
void SET_FUNCTION (STRUCT_NAME *s, T val);

#endif