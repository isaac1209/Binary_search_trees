#include "all_functions.h"

void Run_Binary_search(){
    int size = 1000;
    int points=20;
    int repetitions=1000;
    int search=0;
    int loop1=0;
    int loop2=0;
    int count=1;
    bool status= false;
    double_vec  time_colection;
    int_vector primes;
    int last_index=0;
    clear_this_file(3);
    while(loop1<points){
        primes = sieveOfEratosthenes(size*count);
        last_index=primes.size()-1;
        while (loop2<repetitions){
            //search=rand() % primes.back();
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(0, primes.size() - 1);
            search = primes[dis(gen)];
            auto start_time=std::chrono::steady_clock::now();
            status= Run_binary_search(primes,0,last_index,search);
            auto stop=std::chrono::steady_clock::now();
            auto total_tid2=std::chrono::duration<double,std::micro >(stop-start_time).count();
            if(status){
                time_colection.push_back(total_tid2);
            }
            loop2++;
        }
        loop1++;
        Senda_data_2_file(primes.size()*count,time_colection,3);
        time_colection.clear();
        primes.clear();
        count++;
        loop2=0;

    }

}
