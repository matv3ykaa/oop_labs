#ifndef DOUBLY_LINKED_LIST_INL
#define DOUBLY_LINKED_LIST_INL

#include "list.h"
#include <new>

template <typename T>
DoublyLinkedList<T>::Node::Node(const T& data) : data(data), next(nullptr), prev(nullptr) {}

template <typename T>
DoublyLinkedList<T>::Node::Node(T&& data) : data(std::move(data)), next(nullptr), prev(nullptr) {}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(std::pmr::polymorphic_allocator<Node> alloc)
    : allocator_(alloc), head(nullptr), tail(nullptr) {}

template <typename T>
void DoublyLinkedList<T>::push_back(const T& value) {
    Node* new_node = allocate_node(value);
    if (tail) {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    } else {
        head = tail = new_node;
    }
}

template <typename T>
void DoublyLinkedList<T>::push_front(const T& value) {
    Node* new_node = allocate_node(value);
    if (head) {
        head->prev = new_node;
        new_node->next = head;
        head = new_node;
    } else {
        head = tail = new_node;
    }
}

template <typename T>
void DoublyLinkedList<T>::pop_back() {
    if (tail) {
        Node* temp = tail;
        if (tail->prev) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            head = tail = nullptr;
        }
        deallocate_node(temp);
    }
}

template <typename T>
void DoublyLinkedList<T>::pop_front() {
    if (head) {
        Node* temp = head;
        if (head->next) {
            head = head->next;
            head->prev = nullptr;
        } else {
            head = tail = nullptr;
        }
        deallocate_node(temp);
    }
}

template <typename T>
bool DoublyLinkedList<T>::empty() const {
    return head == nullptr;
}

template <typename T>
DoublyLinkedList<T>::iterator::iterator(Node* node) : current(node) {}

template <typename T>
T& DoublyLinkedList<T>::iterator::operator*() {
    return current->data;
}

template <typename T>
T* DoublyLinkedList<T>::iterator::operator->() {
    return &current->data;
}

template <typename T>
typename DoublyLinkedList<T>::iterator& DoublyLinkedList<T>::iterator::operator++() {
    current = current->next;
    return *this;
}

template <typename T>
typename DoublyLinkedList<T>::iterator& DoublyLinkedList<T>::iterator::operator--() {
    current = current->prev;
    return *this;
}

template <typename T>
bool DoublyLinkedList<T>::iterator::operator!=(const iterator& other) const {
    return current != other.current;
}

template <typename T>
bool DoublyLinkedList<T>::iterator::operator==(const iterator& other) const {
    return current == other.current;
}

template <typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::begin() {
    return iterator(head);
}

template <typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::end() {
    return iterator(nullptr);
}

template <typename T>
typename DoublyLinkedList<T>::Node* DoublyLinkedList<T>::allocate_node(const T& value) {
    void* ptr = allocator_.allocate(1);
    return new (ptr) Node(value);
}

template <typename T>
void DoublyLinkedList<T>::deallocate_node(Node* node) {
    allocator_.deallocate(node, 1);
}

#endif // DOUBLY_LINKED_LIST_INL
