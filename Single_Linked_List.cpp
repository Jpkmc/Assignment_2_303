#include "Single_Linked_List.h"

// Define a template class Single_linked_list with a template type items_Type
template <typename items_Type>
Single_linked_list<items_Type>::Node::Node(const items_Type &item)
    : data(item), nextPtr(nullptr) {} // Constructor for a Node in the linked list

// Constructor for the Single_linked_list class
template <typename items_Type>
Single_linked_list<items_Type>::Single_linked_list()
    : headptr(nullptr), tailptr(nullptr), items(0) {}

// Destructor for the Single_linked_list class
template <typename items_Type>
Single_linked_list<items_Type>::~Single_linked_list() {
  while (!empty()) {
    pop_front(); // Delete all nodes to prevent memory leaks
  }
}

// Add an item to the front of the linked list
template <typename items_Type>
void Single_linked_list<items_Type>::push_front(const items_Type &item) {
  Node *new_node = new Node(item);
  if (empty()) {
    headptr = tailptr = new_node;
  } else {
    new_node->nextPtr = headptr;
    headptr = new_node;
  }
  items++;
}

// Add an item to the end of the linked list
template <typename items_Type>
void Single_linked_list<items_Type>::push_back(const items_Type &item) {
  Node *new_node = new Node(item);
  if (empty()) {
    headptr = tailptr = new_node;
  } else {
    tailptr->nextPtr = new_node;
    tailptr = new_node;
  }
  items++;
}

// Remove the first item in the linked list
template <typename items_Type>
bool Single_linked_list<items_Type>::pop_front() {
  if (empty()) {
    return false;
  }
  Node *temp = headptr;
  headptr = headptr->nextPtr;
  delete temp; // Delete the first node
  items--;
  return true;
}

// Remove the last item in the linked list
template <typename items_Type> bool Single_linked_list<items_Type>::pop_back() {
  if (empty()) {
    return false;
  }
  if (headptr == tailptr) {
    delete headptr;
    headptr = tailptr = nullptr;
  } else {
    Node *current = headptr;
    while (current->nextPtr != tailptr) {
      current = current->nextPtr;
    }
    delete tailptr;
    tailptr = current;
    tailptr->nextPtr = nullptr;
  }
  items--;
  return true;
}

// Get the value of the first item in the linked list
template <typename items_Type>
items_Type Single_linked_list<items_Type>::front() const {
  if (empty()) {
    throw runtime_error("List is empty");
  }
  return headptr->data;
}

// Get the value of the last item in the linked list
template <typename items_Type>
items_Type Single_linked_list<items_Type>::back() const {
  if (empty()) {
    throw runtime_error("List is empty");
  }
  return tailptr->data;
}

// Check if the linked list is empty
template <typename items_Type>
bool Single_linked_list<items_Type>::empty() const {
  return items == 0;
}

// Insert an item at a specified index in the linked list
template <typename items_Type>
void Single_linked_list<items_Type>::insert(size_t index, const items_Type &item) {
  if (index < 0 || index > items) {
    push_back(item); // If the index is out of bounds, add to the end
  } else if (index == 0) {
    push_front(item); // If the index is 0, add to the front
  } else {
    Node *new_node = new Node(item);
    Node *current = headptr;
    for (size_t i = 0; i < index - 1; i++) {
      current = current->nextPtr; // Traverse to the previous node
    }
    new_node->nextPtr = current->nextPtr;
    current->nextPtr = new_node; // Insert the new node
    items++;
  }
}

// Remove an item at a specified index in the linked list
template <typename items_Type>
bool Single_linked_list<items_Type>::remove(size_t index) {
  if (index < 0 || index >= items || empty()) {
    return false;
  }
  if (index == 0) {
    return pop_front(); // If the index is 0, remove from the front
  } else {
    Node *current = headptr;
    for (size_t i = 0; i < index - 1; i++) {
      current = current->nextPtr; // Traverse to the previous node
    }
    Node *temp = current->nextPtr;
    current->nextPtr = temp->nextPtr; // Remove the specified node
    delete temp;
    items--;
    return true;
  }
}

// Find the index of the first occurrence of a given item in the linked list
template <typename items_Type>
size_t Single_linked_list<items_Type>::find(const items_Type &item) {
  Node *current = headptr;
  size_t index = 0;
  while (current) {
    if (current->data == item) {
      return index; // Return the index of the found item
    }
    current = current->nextPtr;
    index++;
  }
  return items; // Return the total number of items if not found
}

// Get the number of items in the linked list
template <typename items_Type>
size_t Single_linked_list<items_Type>::size() const {
  return items;
}
