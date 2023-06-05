#include "all_functions.h"

void Run_Hash_table(){
    int size=1000;
    int loop1=0;
    int points=20;
    int repetition=1000;
    int loop2=0;
    int search=0;
    bool status= false;
    int count=1;
    double_vec time_colection;
    int_vector primes;
    node_vector new_vector;

    clear_this_file(2);
    while (loop1<points){
        primes = sieveOfEratosthenes(size*count);;
        new_vector = Creat_Hash_table(primes);
        while (loop2<repetition){
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(0, primes.size() - 1);
            search = primes[dis(gen)];
            auto start_time=std::chrono::steady_clock::now();
            status= Hash_table_search(search, new_vector);
            auto stop=std::chrono::steady_clock::now();
            auto total_tid2=std::chrono::duration<double,std::micro >(stop-start_time).count();
            if(status){
                time_colection.push_back(total_tid2);
            }
            loop2++;
        }

        Senda_data_2_file(primes.size()*count,time_colection,2);
        new_vector.clear();
        time_colection.clear();
        primes.clear();
        count++;
        loop2=0;
        loop1++;
    }


}
