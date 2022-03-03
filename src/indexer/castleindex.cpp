#include <cstring>

#include "castleindex.h"

using namespace std;

castleindex castleindex::get_child_with_name(const char* name, const char** index) const {
    for(int i = 0; i < this->child_count; i++) {
        if(strcmp(name, index[this->children[i].nameindex]) == 0){
            return this->children[i];
        }
    }
    return castleindex::invalid_index();
}

castleindex castleindex::invalid_index() {
    castleindex index{};
    index.type = INVALID_TOKEN;
    return index;
}

