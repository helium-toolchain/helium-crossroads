#pragma once

#ifdef _WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif

#ifdef __cplusplus
extern "C" {
#endif

    DLLEXPORT void delete_pointer(void* pointer);

    DLLEXPORT void delete_pointer_array(void** pointer);

    DLLEXPORT void free_pointer(void* pointer);

#ifdef __cplusplus
}
#endif
