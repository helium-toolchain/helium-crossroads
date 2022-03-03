#include "indexer_api.h"

castleindexer* castle_init(char* path) {
    castleindexer *indexer = new castleindexer();

    indexer->init(path);

    return indexer;
}

void castle_index(castleindexer *indexer) {
    indexer->index();
}

castleindexer* castle_init_and_index(char* path) {
    castleindexer *indexer = new castleindexer();

    indexer->init(path);
    indexer->index();

    return indexer;
}

char* castle_get_compound_blob(castleindexer* indexer, char* path) {
    return indexer->get_compound_blob(path);
}

char* castle_get_list_blob(castleindexer* indexer, char* path) {
    return indexer->get_list_blob(path);
}

castleindex castle_get_value_token(castleindexer *indexer, char *path) {
    return indexer->get_value_token(path);
}

castleindex castle_get_index_tree(castleindexer *indexer) {
    return indexer->get_index_tree();
}

castleindex castle_get_index_tree_from_path(castleindexer *indexer, char *path) {
    return indexer->get_index_tree_from_path(path);
}
