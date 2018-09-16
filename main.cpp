#include <cstdlib>
#include <iostream>

#include "vector.h"

using namespace std;

template <typename T>
struct Dimensions {      
    int operator()(const int* coordinates, const int* sizes, int dimensions) {
        int suma = 0;
        int producto = 1;
        for(int i = 0; i < dimensions; i++){
            if(i>0) producto *= sizes[i-1];

            suma+=sizes[i]*producto;
        }
        return suma;
    }
};

struct Integer {
       typedef int T;
       typedef Dimensions<T> Operation;
};

int main(int argc, char *argv[]) {

    int dimSize[6] = {1, 2, 3, 4, 5, 6}, coor[6] = {0, 0, 0, 1, 0 ,1};

    Vector<Integer> vector(3, dimSize);

    vector.set(55,coor);

    cout << vector.get(coor)<< endl ;
    
    system("pause");
    return EXIT_SUCCESS;
}