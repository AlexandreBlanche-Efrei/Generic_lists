#include "structures/struct.h" // remplacer par votre fichier .h

// Ne pas modifier

T GET_FUNCTION (STRUCT_NAME *s) {
    return s->content;
}

void SET_FUNCTION (STRUCT_NAME *s, T val) {
    s->content = val;
}
