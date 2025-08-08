#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <optional>
#include <queue>

namespace Heap
{

  template <typename T>
  class MaxHeap
  {
  private:
    std::priority_queue<T> heap;
    int n;

  public:
    void print() const;
    MaxHeap();
    void push(T val);
    void pop();
    std::optional<T> top();
    bool empty();
    int size();
    ~MaxHeap();
  };

}

#include "heap.cpp"

#endif
