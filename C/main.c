#include "list.h"
#include "stdio.h"
#include "stdlib.h"




void print_int(void* data) {
    printf("%d ", *(int*)data);
}

int main() {
    LinkedList* intList = create_linked_list(sizeof(int));
int m = 500;
    int a = 10, b = 20, c = 30;
    push_front(intList, &a);
    push_front(intList, &b);
    push_front(intList, &c);
    push_back(intList,&m);
    printf("List contents: ");
    print_list(intList, print_int);

    free_list(intList);
    return 0;
}
