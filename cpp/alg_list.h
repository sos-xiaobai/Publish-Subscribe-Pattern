#ifndef ALG_LIST_H
#define ALG_LIST_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

template<typename T>
class Class_List 
{
    public:

        struct Node 
        {
            char Topic_name[20]; // 20 bytes
            T data;
            Node* next;
        };
        
        Node* head;

        Class_List() : head(nullptr) {};

        void Add_Node(T data) ;
        Node* Search_Node(Node* data) ;
        void Delete_Node(Node* data) ;
};


#endif // ALG_LIST_H