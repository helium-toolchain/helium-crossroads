#pragma once

#include <cstdint>
#include <string>

using namespace std;

typedef char castle_token_type;

struct castleindex {
    public:
        castleindex *children;

        int32_t offset;
        int32_t length;
        uint16_t nameindex;
        uint16_t child_count;
        
        castle_token_type type;

        ~castleindex(){
            delete (castleindex*)children;
        }

        castleindex get_child_with_name(const char* name, const char** index) const;

        static castleindex invalid_index();
};

#define ROOT_TOKEN 0
#define LIST_TOKEN 29
#define COMPOUND_TOKEN 30
#define INVALID_TOKEN -1
