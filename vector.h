#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

using namespace std;

template <typename Tr>

class Vector {
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;

    private:
        T* data;
        int dataSize;
        Operation src;
        int dimensions;
        int* dimensionSizes;

    public:
        Vector() : data(nullptr) {};

        Vector(int dimensions, int* dimensionSizes) : dimensions(dimensions), dimensionSizes(dimensionSizes) {
            dataSize=1;
            for(int i=0; i<dimensions;i++){
                dataSize*=dimensionSizes[i];
            }
            data=new T[dataSize];
        }

        void set(T datum, int* coordinates){
            int poss= src(coordinates, dimensionSizes, dimensions);
            data[poss]=datum;
        };

        T get(int* coordinates){
            int poss=src(coordinates,dimensionSizes,dimensions);
            return data[poss];
        };
};

#endif
