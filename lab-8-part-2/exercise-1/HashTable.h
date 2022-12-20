#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "ArrayList.h"
#include "LinkedList.h"


struct HashTable{

    ArrayList<LinkedList<int>*> storage;
    int K;

    HashTable(){
        K = 10;
        for(int i=0; i<K; i++){
            storage.add(new LinkedList<int>);
        }
    }

    HashTable(int K){
        this->K = K;
        for(int i=0; i<K; i++){
            storage.add(new LinkedList<int>);
        }
    }

    void add(int value){
        int index = value % K;
        storage.get(index)->append(value);
    }


    bool search(int value){
        if (value<0 ){
            return false;
        }
        int index = value % K;
        return storage.get(index)->search(value);
    }

    // You can declare other functions if needed

};

#endif