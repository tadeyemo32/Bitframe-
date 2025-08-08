#include "heap.h"

int main()
{

  Heap::MaxHeap<int> heap;
  heap.push(50);
  heap.push(2);
  heap.push(90444);
  heap.push(-2);
  heap.print();

  std::vector<int> mainval; 
  return 0;
}
