#include "all_functions.h"

void clear_file(std::string fileName){
    std::ofstream outFile(fileName);
    outFile.close();
}


void clear_this_file(int file_id){
    if(file_id==1){
        clear_file("linear_search.txt");
    }else if(file_id==2){
        clear_file("hash_table.txt");
    }else if(file_id==3){
        clear_file("binary_search.txt");
    }else if(file_id==4){
        clear_file("Tree_search.txt");
    }
}
