#ifndef BITFRAME_C_LIST_H
#define BITFRAME_C_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    void* data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
    int num_elements;
    size_t elementSize;
} LinkedList;

LinkedList* create_linked_list(size_t elementSize) {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->num_elements = 0;
    list->elementSize = elementSize;
    return list;
}

void push_front(LinkedList* list, void* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = malloc(list->elementSize);
    memcpy(newNode->data, data, list->elementSize);
    newNode->next = list->head;
    list->head = newNode;
    list->num_elements++;
}
void push_back(LinkedList* list ,void*data){
    Node*newNode = (Node*)malloc(sizeof(Node));
    if(list->num_elements <1){
    newNode->data = malloc(sizeof(list->elementSize));
    memcpy(newNode->data,data,list->elementSize);
    newNode->next=NULL;
    list->head=newNode;
    list->head = newNode;
    list->num_elements++;
        return;
    }
    Node*curr = list->head;

    while(curr->next!=NULL){
        curr = curr->next;
    }
    curr->next =newNode;
    newNode->data = malloc(list->elementSize);
    memcpy(newNode->data,data,list->elementSize);
    newNode->next = NULL;
    list->num_elements++;

}

void free_list(LinkedList* list) {
    Node* current = list->head;
    while (current) {
        Node* temp = current;
        current = current->next;
        free(temp->data);
        free(temp);
    }
    free(list);
}

void print_list(LinkedList* list, void (*printFunc)(void*)) {
    Node* current = list->head;
    while (current) {
        printf("[");
        printFunc(current->data);
        printf("]\n  ↓\n");
        current = current->next;
    }
    printf("NULL\n");
}

void list_pop_back(LinkedList*list){
    if(list->head==NULL){
        return; 
    }
    if(list->head->next==NULL){
        free(list->head->data);
        free(list->head);
        list->head =NULL;
        
    }else{
        Node*curr = list->head;
        while(curr->next !=NULL){
            curr = curr->next;
        }
        free(curr->next->data);
        free(curr->next);
        curr->next =NULL;
    }

    list->elementSize--; 
}
void list_pop_front(LinkedList*list){
    if(list->head ==NULL){
        return;
    }
    Node*temp = list->head;
    list->head = list->head->next;
    free(temp->data);
    free(temp);
    list->num_elements--; 


}


#endif
