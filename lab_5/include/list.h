#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <memory_resource>
#include <iterator>

template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;

        Node(const T& data);
        Node(T&& data);
    };

    std::pmr::polymorphic_allocator<Node> allocator_;
    Node* head;
    Node* tail;

public:
    DoublyLinkedList(std::pmr::polymorphic_allocator<Node> alloc = {});
    ~DoublyLinkedList() = default;

    void push_back(const T& value);
    void push_front(const T& value);
    void pop_back();
    void pop_front();
    bool empty() const;

    struct iterator {
        Node* current;

        iterator(Node* node);
        T& operator*();
        T* operator->();
        iterator& operator++();
        iterator& operator--();
        bool operator!=(const iterator& other) const;
        bool operator==(const iterator& other) const;
    };

    iterator begin();
    iterator end();

private:
    Node* allocate_node(const T& value);
    void deallocate_node(Node* node);
};

#include "list.inl"

#endif // DOUBLY_LINKED_LIST_H
