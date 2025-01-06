#pragma once

template<typename T>
struct Node
{
    T val;
    Node* next;

    Node();
    Node(const T&);

    //~Node();

};

template <typename T>
struct LinkedList
{
    Node<T>* head;
    int numElements;
    LinkedList();
    ~LinkedList();

    void insertElement(const T& val);
    T getElementAtPos(const int& pos);
    Node<T>* getNodeAtPos(const int& pos);
    int getElement(const T& val);
    bool deleteElement(const T& val);
    void printAll();
    bool (*func)(const T&, const T&);

 };
