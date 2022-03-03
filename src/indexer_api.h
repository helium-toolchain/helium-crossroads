#pragma once

#include "indexer/castleindexer.h"
#include "api_base.h"
#include "castleindexer.h"

// exposes a P/Invoke-able API for C# bindings

#ifdef __cplusplus
extern "C" {
#endif
    DLLEXPORT castleindexer *castle_init(char *filepath);

    DLLEXPORT void castle_index(const void *indexer);

    DLLEXPORT castleindexer *castle_init_and_index(char *filepath);

    DLLEXPORT char *castle_get_compound_blob(const castleindexer *indexer, char *path);

    DLLEXPORT char *castle_get_list_blob(const castleindexer *indexer, char *path);

    // ignore the warnings on these, this only runs from a C++ compiler anyway.
    DLLEXPORT castleindex castle_get_value_token(castleindexer *indexer, char *path);

    DLLEXPORT castleindex castle_get_index_tree(castleindexer *indexer);

    DLLEXPORT castleindex castle_get_index_tree_from_path(castleindexer *indexer, char *path);

    DLLEXPORT void destroy(castleindexer *indexer);

#ifdef __cplusplus
}
#endif