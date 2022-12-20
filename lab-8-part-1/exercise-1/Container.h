#ifndef CONTAINER_H
#define CONTAINER_H

#include "ArrayList.h"
#include "LinkedList.h"

struct Container{

    ArrayList<int> storage;
    int K;

    Container(){
        K=10;
        for(int i=0; i<K; i++){
            storage.append(false);
        }
    }

    Container(int n){
        K=n;
        for(int i=0; i<K; i++){
            storage.append(false);
        }
    }

    void add(int value){
        if(value<0 || value >=K){
            throw std::logic_error("Out of Bounds");
        }

        storage[value]=true;
    }


    bool search(int value){
        if (value<0 || value >=K){
            return false;
        }
        return storage[value];
    }


};

#endif