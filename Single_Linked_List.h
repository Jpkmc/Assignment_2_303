#include <iostream>
#include <string>
using namespace std;

#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

template <typename items_Type>

class Single_linked_list {
private:
  struct Node {
    items_Type data;
    Node *nextPtr;

    Node(const items_Type &item);
  };
  Node *headptr;
  Node *tailptr;
  size_t items;

public:
  Single_linked_list();
  ~Single_linked_list();
  void push_front(const items_Type &item);
  void push_back(const items_Type &item);
  bool pop_front();
  bool pop_back();
  items_Type front() const;
  items_Type back() const;
  bool empty() const;
  void insert(size_t index, const items_Type &item);
  bool remove(size_t index);
  size_t find(const items_Type &item);
  size_t size() const;
};

#endif
