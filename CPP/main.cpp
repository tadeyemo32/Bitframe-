#include "list.h"
#include <iostream>


typedef struct vec {
    int x;
    int y; 
}Vec;



int main(){
using namespace Bits; 

s_LinkedList<vec> list;
Vec vector = vec{5,5};
list.push_back(vector);


    return 0;
}
