// This file will contain part of your solution
#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <iostream>
#include <ostream>
#include <stdexcept>
template <class T>
struct ArrayList{
private:
    T* data;
    int capacity;
    int count;

    // Helper functions

    bool linear_search(const T& value){
        for (int i = 0; i < count; i++){
            if (data[i] == value){
                return true;
            }
        }
        return false;
    }

    bool binary_search(const T& value){
        int left = 0;
        int right = count;

        while (left <= right){
            int mid = (left + right) / 2;
            if (data[mid] == value){
                return true;
            }
            else if (data[mid] > value){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return false;
    }


    void selection_sort(){
        int temp;
        int temp1;
        for(int i=0; i<count-1;i++){
            temp1=i;
            for(int j= i+1; j<count; j++){
                if(data[j]<data[temp1]){
                    temp1=j;
                }
            }
            if(temp1!=i){
                temp = data[temp1];
                data[temp1] = data[i];
                data[i] = temp;
            }
        }
    }

    void insertion_sort(){
        int j;
        int temp;
        for(int i=1; i<count; i++){
            temp=data[i];
            j=i-1;

            while(j>=0 && data[j]>temp){
                data[j+1]=data[j];
                j=j-1;
            }
            data[j+1]=temp;
        }
    }


   void swap(T* a, T* b) 
    { 
    T temp = *a; 
    *a = *b; 
    *b = temp; 
    } 
   
  
    int middleInd(int start ,int end) {
        int i = start + 1;
        int piv = data[start] ;            
        for(int j =start + 1; j <= end ; j++ )  {
    

          if (data[ j ] < piv) {
            swap (&data[ i ], &data[ j ]);
            i += 1;
        }
        }

        swap ( &data[ start ] , &data[ i-1 ] ) ;  
        return i-1;                      
    }
    
    void quickSort(int low, int high) {
        if (low < high) {
      
        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on righ of pivot
        int pi = middleInd( low, high);

        // recursive call on the left of pivot
        quickSort(low, pi - 1);

        // recursive call on the right of pivot
        quickSort(pi + 1, high);
        }
    }

    void quick_sort(){

        int start=0;
        int end=count-1;
        quickSort(start, end);
    }

         
    public:
    ArrayList(){
        capacity = 1;
        count = 0;
        data = new T[capacity];
    }

    ArrayList(const ArrayList<T>& other){
        count = other.count;
        capacity = other.capacity;

        data = new T[capacity];
        for (int i = 0; i < count; i++){
            data[i] = other.data[i];
        }
    }

    ArrayList<T>& operator=(const ArrayList<T>& other){
        T* oldData = data;
        count = other.count;
        capacity = other.capacity;

        data = new T[capacity];
        for (int i = 0; i < count; i++){
            data[i] = other.data[i];
        }
        delete[] oldData;
    }

    T& operator[](int index){
        return data[index];
    }

    T& get(int index) const{
        return data[index];
    }

    bool operator==(const ArrayList<T>& other) const{
        if (count != other.count){
            return false;
        }

        for (int i = 0; i < count; i++){
            if(data[i] != other.data[i]){
                return false;
            }
        }
        return true;
    }

    void append(T value){
        data[count] = value;
        count++;

        if (count == capacity){

            int oldCapacity = capacity;
            capacity *= 2;

            T* temp = new T[capacity];

            for (int i = 0; i < oldCapacity; i++){
                temp[i] = data[i];
            }

            T* oldLocation = data;
            data = temp;
            delete[] oldLocation;
        }
    }

    int size() const{
        return count;
    }

    bool search(const T& value){
        return binary_search(value);
    }

    void sort(int algo){
        if (algo == 1){
            selection_sort();
        }
        else if(algo == 2){
            insertion_sort();
        }
        else if (algo == 3){
            quick_sort();
        }
    }

    ~ArrayList(){
        delete[] data;
    }
};

template <class T>
std::ostream& operator<<(std::ostream& os, const ArrayList<T>& list){
    for (int i = 0; i < list.size(); i++){
        os << list.get(i) << " ";
    }

    return os;
}

#endif