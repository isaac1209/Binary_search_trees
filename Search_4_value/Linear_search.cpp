#include "all_functions.h"

bool linear_seach(int_vector& data_array, int value){
    for(auto &x: data_array ){
        if(x==value) return true;
    }
    return false;
}