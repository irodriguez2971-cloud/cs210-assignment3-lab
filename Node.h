//
// Created by Iv123 on 9/22/2026.
//

#ifndef CS210_ASSIGNMENT3_LAB_PDF_NODE_H
#define CS210_ASSIGNMENT3_LAB_PDF_NODE_H

template <typename T>
class Node {
public:
    T *data;  //Matches what ArrayList calls its own storage
    Node<T> *next;

    explicit Node(T* value) : data(value), next(nullptr) {}
};

#endif //CS210_ASSIGNMENT3_LAB_PDF_NODE_H