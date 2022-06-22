#pragma once
#include<fstream>
#include<iostream>
#include<time.h>
#include<stdlib.h>
//#include"Functionalities.h"
using namespace std;
//using namespace Functionalities;


namespace DataStructures
{
    template<class N> 
    class node
    {
    public:
        N vertData;       // stores vertex`s data
        node* next;       // stores pointer to the next node

        node()
        {
            next = nullptr;
        }    

    };

    template<class L> 
    class List
    {
        node<L>* head;                        // points to the head node of the vector/List
    public: 
        
        int listSize;                         // size ofthe list
        List()
        {
            head = nullptr;
            listSize = 0;
        }

        void push_back(L data)                // to push_back more nodes in the List/vector
        {
            if(head == nullptr)
            {
                head = new node<L>();
                head->vertData = data;
                head->next = nullptr;
                listSize++;
            }
            else
            {
                node<L>* current = head;
                while(current->next != nullptr)
                {
                    current = current->next;
                }
                node<L>* newNode = new node<L>();
                current->next = newNode;
                newNode->vertData = data;
                newNode->next = nullptr;
                listSize++;
            }

        }
        void displayList()                    // displays contents of the List
        {
            node<L>* temp;
            temp = head;
            while(temp != nullptr)
            {
                cout<<"Data: \n"<<temp->vertData<<endl;
                temp = temp->next;

            }
        }
        int get_size()                    // returns the size of list
        {
            return listSize;
        }
        L& operator[](int index)         // overloaded subscript []operator returns the vertex at a certain index
        {
            
            int Count = 0;
            node<L>* temp = head;
            if(head == nullptr)
            {
                cout<<"List is empty\n";

            }
            else
            {
                
                while(Count !=index)
                {
                    temp = temp->next;
                    Count++;
                }
                
            }
            return temp->vertData;
        }
        bool is_empty()           // checks if the Listr is empty
        {
            if(head == nullptr)
            {
                return true;
            }
            else{
                return false;
            }
        }
        L front()             // returns the head of the List
        {
            return head->vertData;
        }
        void pop_front()        // delets the  head of the List and moves the head to next node
        {
            node<L>* temp = head;
            head = temp->next;
            temp->next = nullptr;
            delete temp;

        }
        /*L* begin()              
        {
            return head;
        }
        L* end()
        {
            node<L>* temp = head;
            while(temp->next != nullptr)
            {
                temp = temp->next;
            }
            return temp;
        }*/ 
        
        

    };

    

























}





  