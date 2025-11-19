#ifndef GEN_LIST_H
#define GEN_LIST_H

#define TEMP_CELL_TYPE(T)   s_##T ##_cell
#define CELL_TYPE(T)        t_##T ##_cell
#define LIST_TYPE(T)        t_## T ##_list


#define INCLUDE_GENERIC_LIST(T)                                                                             \
    typedef struct TEMP_CELL_TYPE(T) {                                                                      \
        T value;                                                                                            \
        struct TEMP_CELL_TYPE(T) *next;                                                                     \
    } CELL_TYPE(T);                                                                                         \
    typedef struct {                                                                                        \
        CELL_TYPE(T) *head;                                                                                 \
        CELL_TYPE(T) *tail;                                                                                 \
        unsigned int size;                                                                                  \
    } LIST_TYPE(T);                                                                                         \
    LIST_TYPE(T) create_empty_##T ##_list();                                                                \
    unsigned int length_##T ##_list(const LIST_TYPE(T) *list);                                              \
    T get_##T ##_list(const LIST_TYPE(T) *list, const unsigned int index);                                  \
    void set_##T ##_list(LIST_TYPE(T) *list, const unsigned int index, const T val);                        \
    void push_front_##T ##_list(LIST_TYPE(T) *list, const T val);                                           \
    void push_back_##T ##_list(LIST_TYPE(T) *list, const T val);                                            \
    void insert_at_##T ##_list(LIST_TYPE(T) *list, const unsigned int index, const T val);                  \
    void delete_at_##T ##_list(LIST_TYPE(T) *list, const unsigned int index);                               \
    void destroy_##T ##_list(LIST_TYPE(T) *list);                                                           \
    void print_##T ##_list(const LIST_TYPE(T) *list);                                                       \


#define IMPLEMENT_GENERIC_LIST(T)                                                                           \
                                                                                                            \
    LIST_TYPE(T) create_empty_##T ##_list() {                                                               \
        LIST_TYPE(T) l;                                                                                     \
        l.head = NULL;                                                                                      \
        l.tail = NULL;                                                                                      \
        l.size = 0;                                                                                         \
        return l;                                                                                           \
    }                                                                                                       \
                                                                                                            \
    unsigned int length_##T ##_list(const LIST_TYPE(T) *list)  {                                            \
        return list->size;                                                                                  \
    }                                                                                                       \
                                                                                                            \
    CELL_TYPE(T)* get_##T ##_cell(const LIST_TYPE(T) *list, const unsigned int index) {                     \
        CELL_TYPE(T) *cell = list->head;                                                                    \
        if (cell == NULL || index > list->size)                                                             \
            return NULL;                                                                                    \
        if (index == 0)                                                                                     \
            return cell;                                                                                    \
        if (index == list->size - 1 && list->size != 0)                                                     \
            return list->tail;                                                                              \
        unsigned int i = 0;                                                                                 \
        while (cell != NULL && i < index) {                                                                 \
            cell = cell->next;                                                                              \
            i++;                                                                                            \
        }                                                                                                   \
        return cell;                                                                                        \
    }                                                                                                       \
                                                                                                            \
    T get_##T ##_list(const LIST_TYPE(T) *list, const unsigned int index) {                                 \
            CELL_TYPE(T) *cell = get_##T ##_cell(list, index);                                              \
            return cell->value;                                                                             \
    }                                                                                                       \
                                                                                                            \
    CELL_TYPE(T) *create_##T ##_cell(const T val) {                                                         \
        CELL_TYPE(T) *newcell = (CELL_TYPE(T)*) malloc(sizeof(CELL_TYPE(T)));                               \
        newcell->value = val;                                                                               \
        newcell->next = NULL;                                                                               \
        return newcell;                                                                                     \
    }                                                                                                       \
                                                                                                            \
    void set_##T ##_list(LIST_TYPE(T) *list, const unsigned int index, const T val) {                       \
        CELL_TYPE(T) *cell = get_##T ##_cell(list, index);                                                  \
        cell->value = val;                                                                                  \
    }                                                                                                       \
                                                                                                            \
    void push_front_##T ##_list(LIST_TYPE(T) *list, const T val) {                                          \
        CELL_TYPE(T) *newcell = create_##T ##_cell(val);                                                    \
        newcell->next = list->head;                                                                         \
        list->head = newcell;                                                                               \
        list->size++;                                                                                       \
        if (list->tail == NULL)                                                                             \
            list->tail = newcell;                                                                           \
    }                                                                                                       \
    void push_back_##T ##_list(LIST_TYPE(T) *list, const T val) {                                           \
        if (list->size == 0) {                                                                              \
            push_front_##T ##_list(list, val);                                                              \
            return;                                                                                         \
        }                                                                                                   \
        CELL_TYPE(T) *newcell = create_##T ##_cell(val);                                                    \
        CELL_TYPE(T) *lastcell = get_##T ##_cell(list, list->size - 1);                                     \
        lastcell->next = newcell;                                                                           \
        list->tail = newcell;                                                                               \
        list->size++;                                                                                       \
    }                                                                                                       \
                                                                                                            \
    void insert_at_##T ##_list(LIST_TYPE(T) *list, const unsigned int index, const T val) {                 \
        if (index == 0) {                                                                                   \
            push_front_##T ##_list(list, val);                                                              \
            return;                                                                                         \
        }                                                                                                   \
        if (list->size != 0 && index == list->size - 1) {                                                   \
            push_back_##T ##_list(list, val);                                                               \
            return;                                                                                         \
        }                                                                                                   \
                                                                                                            \
        CELL_TYPE(T) *prev = get_##T ##_cell(list, index - 1);                                              \
        CELL_TYPE(T) *newcell = create_##T ##_cell(val);                                                    \
        newcell->next = prev->next;                                                                         \
        prev->next = newcell;                                                                               \
        list->size++;                                                                                       \
    }                                                                                                       \
                                                                                                            \
    void delete_at_##T ##_list(LIST_TYPE(T) *list, const unsigned int index) {                              \
        if (index == 0) {                                                                                   \
            CELL_TYPE(T) *first = list->head;                                                               \
            if (first == NULL)                                                                              \
                return;                                                                                     \
            list->head = first->next;                                                                       \
            free(first);                                                                                    \
            list->size--;                                                                                   \
            if (list->size == 0)                                                                            \
                list->tail = NULL;                                                                          \
            return;                                                                                         \
        }                                                                                                   \
                                                                                                            \
        CELL_TYPE(T) *prev = get_##T ##_cell(list, index - 1);                                              \
        CELL_TYPE(T) *cell = prev->next;                                                                    \
        if (prev == NULL || cell == NULL)                                                                   \
            return;                                                                                         \
                                                                                                            \
        CELL_TYPE(T) *next = cell->next;                                                                    \
        free(cell);                                                                                         \
        prev->next = next;                                                                                  \
        list->size--;                                                                                       \
                                                                                                            \
        if (index == list->size) {                                                                          \
            list->tail = prev;                                                                              \
        }                                                                                                   \
    }                                                                                                       \
                                                                                                            \
    void destroy_##T ##_list(LIST_TYPE(T) *list) {                                                          \
        CELL_TYPE(T) *cell = list->head;                                                                    \
        while (cell != NULL) {                                                                              \
            CELL_TYPE(T) *next = cell->next;                                                                \
            free(cell);                                                                                     \
            cell = next;                                                                                    \
        }                                                                                                   \
        list->head = NULL;                                                                                  \
        list->tail = NULL;                                                                                  \
    }                                                                                                       \
                                                                                                            \
    void print_##T ##_list(const LIST_TYPE(T) *list) {                                                      \
        printf("[ ");                                                                                       \
        CELL_TYPE(T) *cell = list->head;                                                                    \
        if (cell == NULL) {                                                                                 \
            printf("]\n");                                                                                  \
            return;                                                                                         \
        }                                                                                                   \
        while(cell->next != NULL) {                                                                         \
            print_##T ##_ (cell->value);                                                                    \
            cell = cell->next;                                                                              \
            printf(", ");                                                                                   \
        }                                                                                                   \
        print_##T ##_ (cell->value);                                                                        \
        printf(" ]\n");                                                                                     \
    }                                                                                                       \
                          

///////////////////////////////////////////

INCLUDE_GENERIC_LIST(int)

typedef char* string;
INCLUDE_GENERIC_LIST(string);

#endif