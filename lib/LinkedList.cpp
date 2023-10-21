#ifndef LINKED_LIST_CPP
#define LINKED_LIST_CPP

#include "LinkedList.hpp"

template <typename T>
LinkedList<T>::LinkedList() : _size(0), _head(nullptr), _tail(nullptr) {}

template <typename T>
LinkedList<T>::LinkedList(LinkedList<T> &&other) : _size(other._size),
                                                   _head(other._head),
                                                   _tail(other._tail)
{
    other._size = 0;
    other._head = nullptr;
    other._tail = nullptr;
}

template <typename T>
LinkedList<T>::LinkedList(const std::vector<T> &items)
{
    LinkedList<T>* newList = new LinkedList();
    newList->prepend(items[0]);
    for(int i = 1; i < items.size(); i++)
    {
        this->append(items[i]);
    }
}

// template <typename T>
// LinkedList<T>::LinkedList(const LinkedList<T> &other)
// {
//     this->_size = other._size;
//     this->append(other._head.value);
//     LinkedListNode<T> *temp = other._head.next();
//     while(*temp.next() != nullptr)
//     {
//         this->append(*temp.value);
//         temp = *temp.next();
//     }
//     this->_tail.value = *temp.value;
// }

template<typename T>
size_t LinkedList<T>::size() const
{
    return this->_size;
}

template<typename T>
LinkedListNode<T>* LinkedList<T>::head() const
{
    return this->_head;
}

template<typename T>
LinkedListNode<T>* LinkedList<T>::tail() const
{
    return this->_tail;
}

template<typename T>
LinkedListNode<T>* LinkedList<T>::find(T value) const
{
    LinkedListNode<T> tempNode = this->_head;
    while(tempNode.value != value)
    {
        tempNode = *(tempNode.next());
        if(tempNode.next() == nullptr)
        {
            return nullptr;
        }
    }
    return *tempNode;    
}

template <typename T>
LinkedListNode<T> *LinkedList<T>::append(T value)
{
    LinkedListNode<T>* newNode = new LinkedListNode(value);
    this->_tail->_next = newNode;
    this->_tail = newNode;
    return newNode;
}

template <typename T>
LinkedListNode<T> *LinkedList<T>::insertAfter(LinkedListNode<T> *node, T value)
{
    LinkedListNode<T>* newNode = new LinkedListNode(value);
    newNode->_next = node->next();
    node->_next = newNode;
    return newNode;
}

template <typename T>
std::optional<T> LinkedList<T>::removeHead()
{
    if(this->_size > 0)
    {
        T value = this->_head->value;
        this->_head->_next = this->_head;
        delete this->_head;
        return value; 
    }
    return std::nullopt;
}

template <typename T>
bool LinkedList<T>::remove(T value)
{
    LinkedListNode<T>* node = this->find(value);
    if(node)
    {
        delete node;
        return true;
    }
    return false;
}

template <typename T>
void LinkedList<T>::clear()
{
    while(this->_head->next() != nullptr)
    {
        this->removeHead();
    }
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    this->clear();
}

template <typename T>
LinkedListNode<T> *LinkedList<T>::prepend(T value)
{
    LinkedListNode<T>* newNode = new LinkedListNode(value);
    newNode->_next = this->_head;
    this->_head = newNode;
    return newNode;
}





#endif
