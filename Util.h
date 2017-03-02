#include <string>
#include <iostream>

#ifndef UTIL_HW2
    #define UTIL_HW2

    #include "LinkedList.h"

int * nodeArrayCreator(std::string s, int * arr, int size){
    int length = s.length();
    for(int i = 0; i < size; i++){
        if( i > size - 1){
            arr[size - 1 - i] = 0;
        }
        else
            arr[size - 1 -i] = s.at( length - 1 - i ) - '0';
    }
    return arr;
}

int ** stringToIntArrays(std::string s, const unsigned int numNodes){
    int stringLen = s.length(), modo = stringLen % numNodes; 
    int numArrays = modo == 0 ? stringLen / numNodes : stringLen / numNodes + 1;
    int ** ret = new int * [numArrays];


    //loop backwards through 
    for( int i = 0; i < numArrays; i++){
        if( i == 0 && modo != 0){
            ret[i] = new int[numNodes];
            ret[i] = nodeArrayCreator( s.substr(0, modo), ret[i], numNodes); 
        }
        else{
            ret[i] = new int[numNodes];
            ret[i] = nodeArrayCreator( 
                    s.substr( (i * numNodes) + modo, (i * numNodes) + modo + numNodes),
                    ret[i], numNodes);
        }
    }
    return ret;
}

template <class T>
void print2DArr(T ** arr, int rows, int colms){
    for(int i = 0; i < rows; i++){
        for( int j = 0; j < colms; j++){
            std::cout << arr[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

#endif


