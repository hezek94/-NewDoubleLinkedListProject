#pragma once
#ifndef DOUBLE_LINKED_LIST_HPP
#define DOUBLE_LINKED_LIST_HPP

#include <iostream>

template<typename T>
struct Node {
    T data;
    Node* previous;
    Node* next;
};

template<typename T>
class DoubleLinkedList {
public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    void AddNode(T d); // push new node to front 
    void AddNodefromFront(T d); // push new node to back
    int NodeSize() const;
    void InsertAtIndex(int index, T value);
    void InsertinNode(T Nodedata, T value);
    void deleteAtNode(T node);
    void deleteAtIndex(int nodeIndex);
    void replaceNode(T val, T newVal);
    void print() const;

private:
    Node<T>* Head;
};


template <typename T>
DoubleLinkedList<T>::DoubleLinkedList() : Head(nullptr) {}

template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList() {
    Node<T>* current = Head;
    while (current != nullptr) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
}

template<typename T>
void DoubleLinkedList<T>::AddNode(T d) {
    Node<T>* newNode = new Node<T>();
    newNode->data = d;
    newNode->next = nullptr;
    if (Head == nullptr) {
        Head = newNode;
        Head->previous = nullptr;
    } else {
        Node<T>* itr = Head;
        while (itr->next != nullptr) {
            itr = itr->next;
        }
        itr->next = newNode;
        newNode->previous = itr;
    }
}

template<typename T>
void DoubleLinkedList<T>::AddNodefromFront(T d) {
        Node<T>* newNode = new Node<T>();
        newNode->data = d;
        newNode->previous = nullptr;
        if (Head == nullptr) {
            newNode->next = nullptr;
            Head = newNode;
        } else {
            newNode->next = Head;
            Head->previous = newNode;
            Head = newNode;
        }
    }


template<typename T>
int DoubleLinkedList<T>::NodeSize() const {
    int count = 0;
    Node<T>* nodeitr = Head;
    while (nodeitr != nullptr) {
        count++;
        nodeitr = nodeitr->next;
    }
    return count;
}
template<typename T>
void DoubleLinkedList<T>::InsertAtIndex(int index, T value) {
    if (index > NodeSize() || index < 0) {
            std::cerr << "Invalid index\n";
            return;
        }

        Node<T>* newNode = new Node<T>();
        newNode->data = value;
        newNode->next = nullptr;

        if (index == 1) {
            newNode->next = Head;
            if (Head != nullptr) {
                Head->previous = newNode;
            }
            newNode->previous = nullptr;
            Head = newNode;
            return;
        }

        Node<T>* Nodeitr = Head;
        for (int e = 1; e < index && Nodeitr != nullptr; e++) {
            if (e == index-1) {
                newNode->next = Nodeitr->next;
                if (Nodeitr->next != nullptr) {
                    Nodeitr->next->previous = newNode;
                    }
                Nodeitr->next = newNode;
                newNode->previous = Nodeitr;
            }
            Nodeitr = Nodeitr->next;
        }   
    }
template<typename T>
void DoubleLinkedList<T>::InsertinNode(T Nodedata, T value) {
    if (Head == nullptr) {
        std::cerr << "Invalid placement\n";
        return;
    }

    Node<T>* newNode = new Node<T>();
    newNode->data = value;
    newNode->next = nullptr;

    if (Head->data == Nodedata) {
        newNode->next = Head;
        if (Head != nullptr) {
            Head->previous = newNode;
        }
        Head = newNode;
        return;
    }

    Node<T>* Nodeitr = Head;
    while (Nodeitr != nullptr && Nodeitr->data != Nodedata) {
        Nodeitr = Nodeitr->next;
    }

    if (Nodeitr == nullptr) {
        std::cerr << "Value " << Nodedata << " not found. Node not inserted.\n";
        delete newNode; 
        return;
    }

    newNode->next = Nodeitr->next;
    if (Nodeitr->next != nullptr) {
        Nodeitr->next->previous = newNode;
    }
    Nodeitr->next = newNode;
    newNode->previous = Nodeitr;
}
template<typename T>
void DoubleLinkedList<T>::deleteAtNode(T node) {
    if (Head == nullptr) {
        std::cerr << "The node list is empty. Please check!\n";
        return;
    }

    if (Head->data == node) {
        if (Head->next != nullptr) {
            Head->next->previous = nullptr;
            Node<T>* temp = Head;
            Head = Head->next;
            delete temp;
        } else {
            delete Head;
            Head = nullptr;
        }
        return;
    }

    Node<T>* itr = Head;
    while (itr->next != nullptr && itr->next->data != node) {
        itr = itr->next;
    }

    if (itr->next == nullptr) {
        std::cerr << "Node with specified data not found\n";
        return;
    }

    Node<T>* temp = itr->next;
    itr->next = itr->next->next;
    if (itr->next != nullptr) {
        itr->next->previous = itr;
    }
    delete temp;
}

template<typename T>
void DoubleLinkedList<T>::deleteAtIndex(int nodeIndex) {
        
        if (Head == nullptr || nodeIndex < 0) {
            std::cerr << "The node list is empty. Please check!\n";
            return;
        }

        if (nodeIndex == 1) {
            if (Head->next != nullptr) {
                Head->next->previous = nullptr;
                Node<T>* temp = Head;
                Head = Head->next;
                delete temp;
            } else {
                Node<T>* temp1 = Head;
                delete temp1;
                Head = nullptr;
            }
            return;
        }

        Node<T>* itr = Head;
        for (int i = 0; i <= nodeIndex; i++) {
            if (i < nodeIndex-1) {
              Node<T>* temp = itr->next;
              itr->next = itr->next->next; 
              if (itr->next != nullptr) {
                  itr->next->previous = itr;
              } 
              delete temp;
              return;
            }
            itr = itr->next;
        }
        if (itr->next == nullptr) {
            std::cerr << "Node with specified data not found\n";
            return;
        }

    }

template<typename T>
void DoubleLinkedList<T>::replaceNode(T val, T newVal) {
        if (Head == nullptr || NodeSize() == 0) {
            std::cerr << "the node is empty and no List exist";
            return;
        }
        
        if (val == Head->data){
            Head->data = newVal;
            return;
        }
        Node<T>* current = Head;
        while(current->next !=nullptr) {
            if (current->data == val) {
                current->data = newVal;
                return;
            }
            current = current->next;
            if (current->data != val && current->next == nullptr) {
                std::cerr << "the node with the value: " << val << " does not exist in the list\n";
                return;
                }
        }
        
    }

template<typename T>
void DoubleLinkedList<T>::print() const {
    Node<T>* contain = Head;
    while (contain != nullptr) {
        std::cout << contain->data << "->";
        contain = contain->next;
    }
    std::cout << "\n";
}




#endif // DOUBLE_LINKED_LIST_HPP