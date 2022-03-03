#include <stdexcept>
#include <vector>
#include <stack>

#include "castleindexer.h"

using namespace std;

void castleindexer::init(char* filepath){
    char first_char;

    this->file = fopen(filepath, "rb");

    fread(&first_char, 1, 1, this->file); // read the first byte and match it against 00, the root declarator

    if(first_char != 0){
        throw std::logic_error("invalid castle file");  // for lack of format_error in C++17. that's a C++20 thing. it's still unprocessable
    }
    fseek(file, 0, SEEK_SET);
}

// main indexing logic  
void castleindexer::index(){
    this->index_names();

    stack<int32_t> target_count, current_count;
    castleindex root{}, working_index{};
    stack<castleindex> indexer_results;
    char token_type;
    int16_t token_name_index, child_count;
    int32_t token_length;

    root.type = ROOT_TOKEN;
    root.offset = 0;
    root.nameindex = 0;
    root.length = -1;

    indexer_results.push(root);

    while(true){
        fread(&token_type, 1, 1, this->file);

        switch(token_type){
            case ROOT_TOKEN:
                throw std::logic_error("root token detected inside root token");

            case COMPOUND_TOKEN:
            case LIST_TOKEN:

                working_index.offset = ftell(this->file);
                fread(&token_length, 4, 1, this->file);
                
                if(indexer_results.top().type != LIST_TOKEN){
                    fread(&token_name_index, 2, 1, this->file);
                } else {
                    token_name_index = 0;
                }

                fread(&child_count, 2, 1, this->file);

                working_index.type = token_type;
                working_index.length = token_length;
                working_index.nameindex = token_name_index;

                ((castleindex*)indexer_results.top().children)[current_count.top()] = working_index;
                current_count.top()++;
                current_count.push(0);
                indexer_results.push(working_index);
                target_count.push(child_count);

                continue;

            default:
                break;
        }

        working_index.type = token_type;
        working_index.length = 0;
        working_index.offset = ftell(this->file);

        fread(&token_name_index, 2, 1, this->file);

        working_index.nameindex = token_name_index;

        ((castleindex*)indexer_results.top().children)[current_count.top()] = working_index;
        current_count.top()++;

        if(current_count.top() == target_count.top()){
            if(indexer_results.top().type == ROOT_TOKEN){
                break;
            }

            current_count.pop();
            target_count.pop();
            indexer_results.pop();
        }
    }
}

// this is pretty much the same code as in c#, for the record. but only because i used pointers over there
void castleindexer::index_names(){
    fseek(file, 1, SEEK_SET);

    int32_t total_length = 0, length, count = 0;
    int16_t specific_length = 0;
    vector<char*> current_names;

    fread(&total_length, 4, 1, this->file);
    
    fseek(this->file, 2, SEEK_CUR); // skip name ID

    for(length = 0; length < total_length; length += 2){
        fread(&specific_length, 2, 1, this->file);

        char* name = new char[specific_length];

        fread(name, 1, specific_length, this->file);
        current_names.push_back(name);

        delete[] name;

        length += specific_length;
        count++;
    }

    this->names = new char*[count];
    memcpy(this->names, &current_names[0], count); // 'current_names' will go out of scope, so let us copy those pointers
}

castleindex castleindexer::get_index_tree() {
    return treeindex;
}

vector<string> castleindexer::split_path(char *path) {
    size_t start = 0, end;
    string token, strpath(path);
    vector<string> result;

    while((end = strpath.find('.', start)) != string::npos) {
        token = strpath.substr(start, end - start);
        start = end + 1;
        result.push_back(token);
    }

    result.push_back(strpath.substr(start));
    return result;
}

castleindexer::~castleindexer(){
    delete file;
    delete[] names;
}