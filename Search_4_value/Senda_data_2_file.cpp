#include "all_functions.h"

double calculateStandardDeviation(double_vec  arr, double average) {
    const size_t N = arr.size();
    double dev_square = 0.0;
    for (const double &itr: arr) {
        dev_square += pow((itr - average), 2);
    }
    return std::sqrt((dev_square / (N - 1))) / std::sqrt(N);
}

void Senda_data_2_file(int N_elements, double_vec& time_vector, int file_id){
    double sum=0.0;
    double avarage_time=0.0;
    double stDav=0.0;
    std::ofstream myfile;
    for(auto &x: time_vector){
        sum=sum+x;
    }
    avarage_time=sum/time_vector.size();
    stDav= calculateStandardDeviation(time_vector,avarage_time);

    if(file_id==1){
        myfile.open("linear_search.txt", std::ios::app);
        myfile<<"\n"<<N_elements<<"\t\t\t"<<avarage_time<<"\t\t\t"<<stDav<<"\t\t\t"<<50;
        myfile.close();
    } else if(file_id==2){
        myfile.open("hash_table.txt", std::ios::app);
        myfile<<"\n"<<N_elements<<"\t\t\t"<<avarage_time<<"\t\t\t"<<stDav<<"\t\t\t"<<50;
        myfile.close();
    }else if(file_id==3){
        myfile.open("binary_search.txt", std::ios::app);
        myfile<<"\n"<<N_elements<<"\t\t\t"<<avarage_time<<"\t\t\t"<<stDav<<"\t\t\t"<<50;
        myfile.close();
    }else if(file_id==4){
        myfile.open("Tree_search.txt", std::ios::app);
        myfile<<"\n"<<N_elements<<"\t\t\t"<<avarage_time<<"\t\t\t"<<stDav<<"\t\t\t"<<50;
        myfile.close();
    }
}