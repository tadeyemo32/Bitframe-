#ifndef HEAP_CPP
#define HEAP_CPP

#include "heap.h"

namespace Heap
{

  template <typename T>
  MaxHeap<T>::MaxHeap()
  {
    std::cout << "MaxHeap created\n";
    n = 0;
  }

  template <typename T>
  void MaxHeap<T>::push(T val)
  {
    heap.push(val);
    n++;
  }
  template <typename T>
  void Heap::MaxHeap<T>::print() const
  {
    std::priority_queue<T> copy = heap;
    std::vector<T> elements;

    while (!copy.empty())
    {
      elements.push_back(copy.top());
      copy.pop();
    }

    int n = elements.size();
    int level = 0;
    int index = 0;

    while (index < n)
    {
      int nodesInLevel = 1 << level;
      int spaces = (1 << (std::max(0, (int)(std::log2(n)) - level))) * 2;

      for (int i = 0; i < nodesInLevel && index < n; ++i, ++index)
      {
        std::cout << std::string(spaces, ' ') << elements[index];
      }
      std::cout << "\n\n";
      level++;
    }
  }

  template <typename T>
  void MaxHeap<T>::pop()
  {
    if (!heap.empty())
    {
      heap.pop();
      n--;
    }
    else
    {
      std::cout << "Unable to pop\n";
    }
  }

  template <typename T>
  std::optional<T> MaxHeap<T>::top()
  {
    if (!heap.empty())
    {
      return heap.top();
    }
    return std::nullopt;
  }

  template <typename T>
  bool MaxHeap<T>::empty()
  {
    return heap.empty();
  }

  template <typename T>
  int MaxHeap<T>::size()
  {
    return heap.size();
  }

  template <typename T>
  MaxHeap<T>::~MaxHeap()
  {
    heap = std::priority_queue<T>();
    n = 0;
  }

}
#endif
