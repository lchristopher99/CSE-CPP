#pragma once
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;

template <class T>
class Node
{
public:
    T data;
    Node<T>* next;
    Node()
    {
        next = nullptr;
    }
    
    Node(T data, Node <T>* next = nullptr)
    {
        this->data = data;
        this->next = next;
    }
};

template<class T>
class LinkedList
{
private:
    Node<T>* head;
    
public:
    LinkedList() //Constructor that initializes the class object
    {
        head = nullptr;
    }
    
    ~LinkedList()  //Deallocates any memory allocated in class methods.  Called when "delete" is used on a class object.
    {
        ClearList();
    }
    
    void ClearList()
    {
        Node<T> *tmp = head;
        Node<T> *tmp2 = nullptr;
        
        while (tmp != nullptr)
        {
            tmp2 = tmp;
            tmp = tmp->next;
            delete tmp2;
        }
        
        head = nullptr;
    }
    
    //    void Insert(T data)
    //    {
    //        Node<T> *temp = new Node<T>(data); //Created a new node in dynamic memory
    //
    //        //If the list is empty
    //        if (head == nullptr)
    //        {
    //            //Add it to the beginning and end of the list
    //            head = temp;
    //        }
    //        else
    //        {
    //            //Traverse to the end of the list
    //            Node<T>* tempT = head;
    //
    //            while (tempT->next != nullptr)
    //            {
    //                tempT = tempT->next;
    //            }
    //
    //            //Attach the new node to the end of the
    //            //list
    //            tempT->next = temp;
    //        }
    //    }
    
    void Insert(T data)
    {
        if (head == NULL) {
            head = new Node<T>(data, NULL);
        } else {
            Node<T> *temp = head;
            Node<T> *tempT = NULL;
            while (temp != NULL && temp->data < data) {
                tempT = temp;
                temp = temp->next;
            }
            if (temp == NULL) {
                tempT->next = new Node<T>(data, NULL);
            } else if (temp == head) {
                tempT = new Node<T>(data, head);
                head = tempT;
            } else {
                tempT->next = new Node<T>(data, temp);
            }
        }
    }
    
    void Remove(T data)
    {
        Node<T> *tmp = head;
        Node<T> *tmp2 = nullptr;
        
        while (tmp != nullptr && tmp->data != data)
        {
            tmp2 = tmp;
            tmp = tmp->next;
        }
        
        if (tmp == nullptr)
            return;
        else
        {
            if (tmp == head)
            {
                head = head->next;
                delete tmp;
            }
            else
            {
                //delete the node
                tmp2->next = tmp->next;
                delete tmp;
            }
        }
        
    }
    
    friend ostream& operator<<(ostream &os, const LinkedList<T> &list)
    {
        Node<T> *tmp = list.head;
        
        while (tmp != nullptr)
        {
            os << tmp->data << endl;
            tmp = tmp->next;
        }
        
        return os;
    }
};

