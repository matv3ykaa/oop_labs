#include <iostream>
#include <memory_resource>
#include "include/allocator.h"
#include "include/list.h"

struct Person {
    std::string name;
    int age;
    std::string address;

    Person(const std::string& name, int age, const std::string& address)
        : name(name), age(age), address(address) {}

    friend std::ostream& operator<<(std::ostream& os, const Person& person) {
        os << "Name: " << person.name << ", Age: " << person.age << ", Address: " << person.address;
        return os;
    }
};

int main() {
    CustomAllocator custom_alloc;
    std::pmr::polymorphic_allocator<int> allocator(&custom_alloc);

    DoublyLinkedList<int> list(allocator);

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_front(5);

    for (auto it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    list.pop_back();
    list.pop_front();

    for (auto it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
// <===============================>
    CustomAllocator custom_alloc_new;
    std::pmr::polymorphic_allocator<int> allocator_new(&custom_alloc_new);
    DoublyLinkedList<Person> list_new(allocator_new);

    list_new.push_back(Person("Alice", 30, "1234 Elm Street"));
    list_new.push_back(Person("Bob", 25, "5678 Oak Avenue"));
    list_new.push_back(Person("Charlie", 35, "91011 Pine Road"));

    std::cout << "List of persons after push_back operations:" << std::endl;
    for (const auto& person : list_new) {
        std::cout << person << std::endl;
    }

    list_new.pop_front();
    list_new.pop_back();

    std::cout << "\nList of persons after pop_front and pop_back:" << std::endl;
    for (const auto& person : list_new) {
        std::cout << person << std::endl;
    }

    return 0;
}
