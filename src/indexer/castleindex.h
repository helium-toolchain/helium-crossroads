#pragma once

#include <cstdint>

typedef char castle_token_type;

struct castleindex {
    public:
        void* children;

        int32_t offset;
        int32_t length;
        uint16_t nameindex;
        
        castle_token_type type;

        ~castleindex(){
            delete (castleindex*)children;
        }
};

#define ROOT_TOKEN 0
#define LIST_TOKEN 29
#define COMPOUND_TOKEN 30
