#pragma once // we're just keeping pragma once here, its supported by clang and gcc. if you compile this without pragma once support, sucks.

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <vector>

#include "castleindex.h"

using namespace std;

class castleindexer {
    public:
        virtual void init(char* filepath);
        virtual void index();

        int32_t get_token_offset(char* path);
        int32_t get_token_end(char* path);

        char* get_compound_blob(char* path);
        char* get_list_blob(char* path);

        castleindex get_value_token(char* path);

        castleindex get_index_tree();
        castleindex get_index_tree_from_path(char* path);

        virtual ~castleindexer();

    private:
        FILE* file;
        castleindex treeindex;
        char** names;

        void index_names();
        static vector<string> split_path(char* path);
};
