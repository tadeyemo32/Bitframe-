#ifndef BITFRAME_CPP_LINKED_LIST_H
#define BITFRAME_CPP_LINKED_LIST_H

#include <iostream>
#include <cstdio>

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
        head = new Node{data, head};
        size++;
    }
    
    void push_back(T data) {
        Node* newNode = new Node{data, nullptr};
        
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
        size++;
    }

    void insert(int position, T data) {
        if (position < 0 || position > size) {
            perror("Invalid Index");
            return;
        }
        
        if (position == 0) {
            push_front(data);
            return;
        }
        
        Node* current = head;
        for (int i = 0; i < position - 1; ++i) {
            current = current->next;
        }
        
        Node* newNode = new Node{data, current->next};
        current->next = newNode;
        size++;
    }

    void pop_back() {
        if (size == 0) {
            perror("Unable to pop empty list");
            return;
        }
        
        if (size == 1) {
            delete head;
            head = nullptr;
        } else {
            Node* prev = nullptr;
            Node* current = head;
            
            while (current->next != nullptr) {
                prev = current;
                current = current->next;
            }
            
            prev->next = nullptr;
            delete current;
        }
        
        size--;
    }

    void pop(int index) {
        if (index < 0 || index >= size) {
            perror("Invalid Index");
            return;
        }
        
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* current = head;
            for (int i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
        
        size--;
    }
    
    void print() { //only works for primitive types 
        if (size <= 0) {
            perror("Unable to print empty List");
            return;
        }

        Node* start = head;
        std::cout << "START->";
        while (start != nullptr) {
            std::cout << start->data << " ->";
            start = start->next;
        }
        std::cout << "END" << std::endl;
    }
};

}

#endif
