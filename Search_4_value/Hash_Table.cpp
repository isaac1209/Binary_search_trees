#include "all_functions.h"

void Hash_table_insert(int key, int value, node_vector& Myvector){
    node* N= new node;
    N->data=value;
    if(Myvector[key]== nullptr){
        Myvector[key]=N;
    } else{
        node* current = Myvector[key];
        while (current->next_node != nullptr){
            current = current->next_node;
        }
        current->next_node = N;
    }
}

int Hash_key(int value, int vec_size){
    int New_key= value % vec_size;
    return New_key;
}

bool Hash_table_search(int value, node_vector& Myvector){
    int size=Myvector.size();
    int key= Hash_key(value,size);

        node* current = Myvector[key];
        while (current != nullptr){
            if(current->data == value){
                return true;
            }
            current = current->next_node;
        }
        return false;
}

node_vector Creat_Hash_table(int_vector& Myvector){
    int size=Myvector.size();
    node_vector hash_table_vec(size);
    for(auto &value: Myvector){
        int key= Hash_key(value,size);
        Hash_table_insert(key,value,hash_table_vec);
    }
    return hash_table_vec;
}

