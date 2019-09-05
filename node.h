#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    Node<T>* next = nullptr;
    Node<T>* prev = nullptr;

    void killSelf() {
        if(next != NULL){
            next->killSelf();
        }
            delete this;

    }
};

#endif