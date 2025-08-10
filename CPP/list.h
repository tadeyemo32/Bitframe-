#ifndef BITFRAME_CPP_LINKED_LIST_H
#define BITFRAME_CPP_LINKED_LIST_H
#include "cstdio"
namespace Bits {

template <typename T>
class s_LinkedList {
private:
    struct Node {
        T data;
        Node* next;
    };
    
    Node* head;
    int size;

public:
    s_LinkedList() : head(nullptr), size(0) {}
    
    ~s_LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
    
    void push_front(T data) {
        Node* newNode = new Node{data, head};
        head = newNode;
        size++;
    }
    
    void push_back(T data) {
        Node* newNode = new Node{data, nullptr};
        
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
        size++;
    }

    void insert(int position,T data){
        
        if(position>size || position==0 || position== size){
            perror("Invalid Index"); 
        }else{
            Node*newNode = new Node{data,nullptr};
            Node* current = head; 
            Node* forward = head->next; 
            int n = 0 ; 
            while (current !=nullptr &&forward!=nullptr){
               if(n== position-1){
                current->next = newNode;
                newNode->next = forward->next; 
                break;    
               } 
                current = current->next;
                forward = forward->next; 
                n++;
            }
        }


    void pop_back();

    void pop(int index);
    
    }



};

} 

#endif
