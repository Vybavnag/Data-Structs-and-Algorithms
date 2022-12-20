#ifndef GOODLIST_H
#define GOODLIST_H

#include <ostream>


struct GoodList{
    int count1;
    int** p;
    int count;
    int capacity;
    int capacity1;
    int iNdex;
    
    GoodList(){
        capacity=100000;
        p= new int*[capacity]; 
        capacity1=8;
        count=0;
        iNdex=0;
        p[iNdex]=new int[capacity1];
    }


    void append(int value){
        p[iNdex][count]=value; 
        if(count==capacity1){
            capacity1*=2;
            iNdex++;
            p[iNdex]=new int[capacity1];
        }
        count++;
        
    }

    int& operator[](int index){
        if (index<10){
            return p[0][index];
        }
    }

    ~GoodList(){
        delete [] p;
    }
};

std::ostream& operator<<(std::ostream& os, GoodList& gl){

    // Your code here

    return os;
}


#endif