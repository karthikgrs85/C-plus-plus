// LinkedList_Generic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "LinkedList_Generic.h"
#include <iostream>
#include <string>
#include <sstream>


#define dataType "input buffer"

// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
using namespace std;

template <typename T>
Node<T>::Node(const T& value) :val(value)
{
    next = nullptr;
}

template <typename T>
Node<T>::Node()
{
}


template <typename T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    numElements = 0;
}
template <typename T>
LinkedList<T>::~LinkedList()
{
    Node<T> *node = head, *nextNode = nullptr;
    while (node != nullptr)
    {
        nextNode = node->next;
        std::cout << "\n Destroying element :" << node->val;
        delete node;
        node = nextNode;
    }
}

template <typename T>
void LinkedList<T>::insertElement(const T& val)
{
    Node<T> *newNode = new Node<T>(val);
    numElements++;
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    else
    {
        //iterate through the linked list to find the location
        //assuming linked list is to be sorted in ascending order
        Node<T> *curNode = head;
        Node<T> *nextNode = head->next;

        if (func(val , head->val))
        {
            newNode->next = curNode;
            head = newNode;
            return;
        }
        while (nextNode != nullptr)
        {
            if (func(curNode->val,val) && func(val, nextNode->val))
            {
                curNode->next = newNode;
                newNode->next = nextNode;
                return;
            }
            curNode = curNode->next;
            nextNode = nextNode->next;
        }

        //It means the new Node has not been inserted still and 
        //nextNode points to nullptr
        curNode->next = newNode;
        return;
    }
}

//Assuming elements are indexed from 0 to numElements-1
template<typename T>
T LinkedList<T>::getElementAtPos(const int& pos)
{
    if (pos < 0 || pos >= numElements || head == nullptr)
        return T();
    
    Node<T>* node = head;
    int curPos = 0;
    
    while (node != nullptr && curPos != pos)
    {
        node = node->next;
        curPos++;
    }
    return node->val;
}

template <typename T>
Node<T>* LinkedList<T>::getNodeAtPos(const int& pos)
{
    if (pos < 0 || pos >= numElements || head == nullptr)
        return nullptr;
    int curPos = 0;
    Node<T>* node = head;
    while (node != nullptr && curPos != pos)
    {
        node = node->next;
        curPos++;
    }
    return node;
}

template <typename T>
int LinkedList<T>::getElement(const T& val)
{
    int high = numElements - 1, mid, low = 0;
    T curVal;

    do
    {
        mid = (low + high) / 2;
        curVal = getElementAtPos(mid);
        if (curVal == val)
            return mid;
        else if (func(curVal, val))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }

    } while (low <= high);
    return -1;
}

template<typename T>
bool LinkedList<T>::deleteElement(const T& val)
{
    int pos;
    Node<T> *prevNode, *nextNode, *curNode;
    if ((pos = getElement(val)) == -1)
    {
        cout << "\n Element not found!...";
        return false;
    }


    nextNode = getNodeAtPos(pos + 1);
    curNode = getNodeAtPos(pos);

    if (pos == 0)
    {
        head = nextNode;
    }
    else
    {
        prevNode = getNodeAtPos(pos - 1);
        prevNode->next = nextNode;
    }

    delete curNode;

    cout << "\n Element deleted successfully!...";
    numElements--;
    return true;
}
template<typename T>
void LinkedList<T>::printAll()
{
    if (head == nullptr)
    {
        cout << "\n LinkedList empty! ";
        return;
    }

    Node<T>* node = head;

    cout << "\n Elements in Linked List :\n";
    while (node->next != nullptr)
    {
        cout << node->val << " , ";
        node = node->next;
    }
    cout << node->val;
}


int main()
{
    LinkedList<string> lstring;

    string inp, option, buf;
    int num;

    auto ascStringCompare = [](const string& a, const string& b) {return (strcmp(a.c_str(),b.c_str()) < 0); };
    auto descStringCompare = [](const string& a, const string& b) {return (strcmp(a.c_str(), b.c_str()) > 0); };
    
    std::cout << "\n Enter format for sorting linked list 1- for ascending 2- for descending :";
    std::cin >> num;
    if (num == 1)
    {
        lstring.func = ascStringCompare;
        std::cout << "\n Selecting ascending format";
    }
    else
    {
        if (num != 2)
            std::cout << "\n Undefined option ";
        lstring.func = descStringCompare;
        std::cout << "\n Selecting descending format";
    }
    cin.ignore();
    do
    {
        
        std::cout << "\n LinkedList commands (enter any one) "
            "\n insert <"<<dataType<<">"
            "\n display "
            "\n delete <"<<dataType<<">"
            "\n exit \n";
        getline(cin, inp);
        stringstream ss(inp);
        ss >> option;
        if (!(strcmp(option.c_str(), "insert")))
        {
            inp.erase(0,7);
            lstring.insertElement(inp);
            std::cout << "\n Element inserted successfully!";
            lstring.printAll();
        }
        else if (!strcmp(option.c_str(), "display"))
        {
            lstring.printAll();
        }
        if (!(strcmp(option.c_str(), "delete")))
        {
            inp.erase(0, 7);
            if (lstring.deleteElement(inp))
                lstring.printAll();
        }
        //else if(!(strcmp(option.c_str(), "delete")))

    } while (strcmp(option.c_str(), "exit"));

    std::cout << "\n Program terminating...";

    //std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
