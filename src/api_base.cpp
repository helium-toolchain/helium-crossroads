#include "api_base.h"

#include <cstdlib>

void delete_pointer(void *pointer) {
    operator delete(pointer);
}

void delete_pointer_array(void **pointer) {
    delete[] pointer;
}

void free_pointer(void *pointer) {
    free(pointer);
}
