#pragma once

#ifdef _WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif

// we'll need to catch windows compilers here since method implementations vastly differ from platform to platform
// other compiler users: sucks to be you. edit this file.
#if defined(__CYGWIN32__) || defined(__MINGW32__) || defined(_WIN32)
#define WINDOWS
#else
#define LINUX
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
