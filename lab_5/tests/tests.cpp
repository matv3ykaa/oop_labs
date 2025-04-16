#include <iostream>
#include <memory_resource>
#include <list>
#include <memory>
#include <exception>
#include "googletest/googletest/include/gtest/gtest.h"
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

TEST(DoublyLinkedListTest, PushBackAndFront) {
    CustomAllocator custom_alloc;
    std::pmr::polymorphic_allocator<int> allocator(&custom_alloc);

    DoublyLinkedList<int> list(allocator);

    EXPECT_TRUE(list.empty());

    list.push_back(10);
    list.push_back(20);

    auto it = list.begin();
    EXPECT_EQ(*it, 10);
    ++it;
    EXPECT_EQ(*it, 20);

    list.push_front(5);
    it = list.begin();
    EXPECT_EQ(*it, 5);
    ++it;
    EXPECT_EQ(*it, 10);
    ++it;
    EXPECT_EQ(*it, 20);
}

TEST(DoublyLinkedListTest, PopBackAndFront) {
    CustomAllocator custom_alloc;
    std::pmr::polymorphic_allocator<int> allocator(&custom_alloc);

    DoublyLinkedList<int> list(allocator);

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    list.pop_back();
    auto it = list.begin();
    EXPECT_EQ(*it, 10);
    ++it;
    EXPECT_EQ(*it, 20);

    list.pop_front();
    it = list.begin();
    EXPECT_EQ(*it, 20);

    list.pop_back();
    EXPECT_TRUE(list.empty());
}

TEST(DoublyLinkedListTest, IteratorEdgeCases) {
    CustomAllocator custom_alloc;
    std::pmr::polymorphic_allocator<int> allocator(&custom_alloc);

    DoublyLinkedList<int> list(allocator);

    auto it = list.begin();
    EXPECT_EQ(it, list.end());

    list.push_back(10);
    list.push_back(20);

    it = list.begin();
    EXPECT_EQ(*it, 10);
    ++it;
    EXPECT_EQ(*it, 20);
    ++it;
    EXPECT_EQ(it, list.end());
}

TEST(DoublyLinkedListTest, CustomAllocatorIntegration) {
    CustomAllocator custom_alloc;
    std::pmr::polymorphic_allocator<int> allocator(&custom_alloc);

    DoublyLinkedList<int> list(allocator);

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    list.pop_back();
    list.pop_back();
    list.pop_back();

    list.push_back(4);
    auto it = list.begin();
    EXPECT_EQ(*it, 4);
}

TEST(DoublyLinkedListTest, StressTest) {
    CustomAllocator custom_alloc;
    std::pmr::polymorphic_allocator<int> allocator(&custom_alloc);

    DoublyLinkedList<int> list(allocator);

    const int num_elements = 10000;
    for (int i = 0; i < num_elements; ++i) {
        list.push_back(i);
    }

    int count = 0;
    for (auto it = list.begin(); it != list.end(); ++it) {
        EXPECT_EQ(*it, count);
        ++count;
    }
    EXPECT_EQ(count, num_elements);

    for (int i = 0; i < num_elements; ++i) {
        list.pop_front();
    }
    EXPECT_TRUE(list.empty());
}

TEST(DoublyLinkedListTestStruct, PushBackAndFront) {
    CustomAllocator custom_alloc;
    std::pmr::polymorphic_allocator<Person> allocator(&custom_alloc);

    DoublyLinkedList<Person> list(allocator);

    EXPECT_TRUE(list.empty());

    list.push_back(Person("Alice", 30, "1234 Elm Street"));
    list.push_back(Person("Bob", 25, "5678 Oak Avenue"));

    auto it = list.begin();
    EXPECT_EQ(it->name, "Alice");
    EXPECT_EQ(it->age, 30);
    EXPECT_EQ(it->address, "1234 Elm Street");
    ++it;
    EXPECT_EQ(it->name, "Bob");
    EXPECT_EQ(it->age, 25);
    EXPECT_EQ(it->address, "5678 Oak Avenue");

    list.push_front(Person("Charlie", 35, "91011 Pine Road"));
    it = list.begin();
    EXPECT_EQ(it->name, "Charlie");
    ++it;
    EXPECT_EQ(it->name, "Alice");
    ++it;
    EXPECT_EQ(it->name, "Bob");
}

TEST(DoublyLinkedListTestStruct, PopBackAndFront) {
    CustomAllocator custom_alloc;
    std::pmr::polymorphic_allocator<Person> allocator(&custom_alloc);

    DoublyLinkedList<Person> list(allocator);

    list.push_back(Person("Alice", 30, "1234 Elm Street"));
    list.push_back(Person("Bob", 25, "5678 Oak Avenue"));
    list.push_back(Person("Charlie", 35, "91011 Pine Road"));

    list.pop_back();
    auto it = list.begin();
    EXPECT_EQ(it->name, "Alice");
    ++it;
    EXPECT_EQ(it->name, "Bob");

    list.pop_front();
    it = list.begin();
    EXPECT_EQ(it->name, "Bob");

    list.pop_back();
    EXPECT_TRUE(list.empty());
}

TEST(DoublyLinkedListTestStruct, IteratorEdgeCases) {
    CustomAllocator custom_alloc;
    std::pmr::polymorphic_allocator<Person> allocator(&custom_alloc);

    DoublyLinkedList<Person> list(allocator);

    auto it = list.begin();
    EXPECT_EQ(it, list.end());

    list.push_back(Person("Alice", 30, "1234 Elm Street"));
    list.push_back(Person("Bob", 25, "5678 Oak Avenue"));

    it = list.begin();
    EXPECT_EQ(it->name, "Alice");
    ++it;
    EXPECT_EQ(it->name, "Bob");
    ++it;
    EXPECT_EQ(it, list.end());
}

TEST(DoublyLinkedListTestStruct, CustomAllocatorIntegration) {
    CustomAllocator custom_alloc;
    std::pmr::polymorphic_allocator<Person> allocator(&custom_alloc);

    DoublyLinkedList<Person> list(allocator);

    list.push_back(Person("Alice", 30, "1234 Elm Street"));
    list.push_back(Person("Bob", 25, "5678 Oak Avenue"));
    list.push_back(Person("Charlie", 35, "91011 Pine Road"));

    list.pop_back();
    list.pop_back();
    list.pop_back();

    list.push_back(Person("David", 40, "1111 Birch Lane"));
    auto it = list.begin();
    EXPECT_EQ(it->name, "David");
}

TEST(DoublyLinkedListTestStruct, StressTest) {
    CustomAllocator custom_alloc;
    std::pmr::polymorphic_allocator<Person> allocator(&custom_alloc);

    DoublyLinkedList<Person> list(allocator);

    const int num_elements = 10000;
    for (int i = 0; i < num_elements; ++i) {
        list.push_back(Person("Person " + std::to_string(i), i, "Address " + std::to_string(i)));
    }

    int count = 0;
    for (auto it = list.begin(); it != list.end(); ++it) {
        EXPECT_EQ(it->name, "Person " + std::to_string(count));
        EXPECT_EQ(it->age, count);
        EXPECT_EQ(it->address, "Address " + std::to_string(count));
        ++count;
    }
    EXPECT_EQ(count, num_elements);

    for (int i = 0; i < num_elements; ++i) {
        list.pop_front();
    }
    EXPECT_TRUE(list.empty());
}
