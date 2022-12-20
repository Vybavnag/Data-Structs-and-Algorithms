// This file will contain part of your solution
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <ostream>
#include "Node.h"

struct LinkedList{
    Node* head;            // Keep a pointer to the head (first element) of the list
    LinkedList(){       
        head = nullptr;     // A null pointer for head means the list is empty
    }

    void prepend(int value){
        if (head == nullptr){           // If we currently have an empty list
            head = new Node(value);     // Create a new node with the given value and make that the head
        }
        else{                               // If there are already elements in the list
            Node* temp = new Node(value);   // Make a new node with the given value
            temp->next = head;              // Make the current head to be the next element of the newly created node
            head = temp;                    // Point the head to the newly created node
        }
    }

    void append(int value){
        if (head == nullptr){               // If we have an empty list
            head = new Node(value);         // Create a new node with the given value and make that the head
        }
        else{                               // If there are already elements in the list
            Node* temp = new Node(value);   // Make a new node with the given value

            Node* last = head;              // Find the last element in the list
            while (last->next != nullptr){  // That is the first element whose next pointer is null
                last = last->next;
            }

            last->next = temp;              // Make the next pointer of the last element point to the newly created node
        }
    }

    void removeFirst(){
        if (head != nullptr){
            Node* oldHead = head;
            head = head->next;
            delete oldHead;
        }
    }

    void removeLast(){
        if (head != nullptr){
            Node* temp = head;
            Node* prev = nullptr;
            while (temp->next != nullptr){
                prev = temp;
                temp = temp->next;
            }
            delete temp;
            prev->next = nullptr;
        }
    }
    
    int getCount(){
        //////////////////////////////////////////////
        /*count should find out about the total number of elements in arrayList. since temp starts from head, count should start at 1*/
        int count=1;
        //////////////////////////////////////////////
        Node* temp= head;
        while(temp->next!=nullptr){
            count++;
            temp=temp->next;
        }
        return count;
    }

    int get(int index){
        /// To make sure the linkedList is not empty///////
        if (head == nullptr){
            throw std::logic_error("Empty LinkedList");
        }
        //////////////////////////////////////////////////
        int count = getCount();
        std::cout<<count<<std::endl;
        int i=0;
        int result=0;


        Node* temp=head;
        if(index<0){
            throw std::logic_error("less than 0");
        }
        else if(index==0){
            result=temp->data;
            return result;
        }
        else if(index>=count){
            throw std::logic_error("out of bounds");
        }
        else{
            while(i!=index){
                if(temp->next==nullptr){
                    throw std::logic_error("error");
                }
                temp=temp->next;
                i++;
            }
            result=temp->data;
            return result;
        }

        
        return 0;
    }

    void insert(int value, int index){
        if (head == nullptr){               // If we have an empty list
            head = new Node(value);         // Create a new node with the given value and make that the head
        }
       else{
            index=index+1;
            int count = getCount();
            Node** tempNode=&head;
           while(index--){
               if(index==0){
                   Node* temp= new Node(value);
                   temp->next=*tempNode;
                   *tempNode=temp;
               }
               else{
                   tempNode=&(*tempNode)->next;
               }
           }
           count++;
       }
    }

    ~LinkedList(){                  // We must release all the memory we are occupying, which is not necessarily one contiguous chunk
        Node* temp = head;          // Start at the head
        while (head != nullptr){    // As long as there are more elements
            head = head->next;      // release the head element and make its pointer point to the next element
            delete temp;
            temp = head;
        }
    }
};

std::ostream& operator<< (std::ostream& os, LinkedList& list){ // Print out the list on one line, separating elements by a space
    Node* current = list.head;
    while (current != nullptr){
        os << current->data << " ";
        current = current->next;
    }

    return os;
}


#endif