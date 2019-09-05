#ifndef LINKED_H
#define LINKED_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"

template <typename T>
class LinkedList : public List<T> {
    public:
        LinkedList() : List<T>() {}

        T front() {
            if(this->nodes == 0){
                throw "List without nodes";
            }else return  this->head->data;
        }

        T back() {
            if(this->nodes == 0){
                throw "List without nodes";
            }else return this->tail->data;
        }

        void push_front(T value) {
            Node<T>* nuevo = new Node<T>;
            nuevo->data = value;
            if(this->nodes == 0){
                this->head = nuevo;
                this->tail = this->head;
                this->nodes++;
            } else{
                nuevo->next = this->head;
                this->head->prev = nuevo;
                this->head = nuevo;
                this->nodes++;
            }
        }

        void push_back(T value) {
            Node<T>* nuevo = new Node<T>;
            nuevo->data = value;
            if (this->nodes == 0){
                this->head = nuevo;
                this->tail = this->head;
                this->nodes++;
            } else {
                this->tail->next = nuevo;
                nuevo->prev  = this->tail;
                this->tail = nuevo;
                this->nodes++;
            }
        }

        void pop_front() {
            if (this->nodes == 0){
                throw "No elements to pop";
            }else{
                if (this->nodes == 1){
                    delete this->head;
                    this->nodes--;
                }else{
                Node<T> *deleted = this->head;
                this->head = this->head->next;
                this->head->prev = nullptr;
                delete deleted;
                this->nodes--;
                }
            }
        }

        void pop_back() {
            if(this->nodes == 0){
                throw  "No elements to pop";
            }else{
                if (this->nodes == 1){
                    delete this->head;
                    this->nodes--;
                }else{
                    Node<T> *deleted = this->tail;
                    Node<T> *newtail = this->tail->prev;
                    this->tail = newtail;
                    this->tail->next = nullptr;
                    delete deleted;
                    this->nodes--;
                }
            }
        }

        T operator[](int index) {
            if(index>=this->nodes){
                throw "Excessive index";
            }else{
                Node<T> *indexed = this->head;
                for (int i = 0; i < index ; i++) {
                    indexed = indexed->next;
                }
                return indexed->data;
            }
        }

        bool empty() {
            return this->nodes==0;
        }

        int size() {
            return this->nodes;
        }

        void clear() {
            this->head->killSelf();
            this->nodes = 0;
        }

        void sort() {
            int size = this->nodes;
            int array[size];
            Node<T>*iterador = this->head;
            for (int i = 0; i <size ; ++i) {
                array[i] = iterador->data;
                iterador = iterador->next;
            }
            for (int i = (size)/2; i >0 ; i /=2) {
                for (int j = i; j < size; j++) {
                    int temp = array[j];
                    int k;
                    for ( k = j; k >=i  && array[k-i]>temp; k -=i) {
                        array[k] = array[k-i];
                    }
                    array[k] = temp;
                }
            }
            iterador = this->head;
            for (int l = 0; l < size ; l++) {
                iterador->data = array[l];
                iterador = iterador->next;
            }
        }
    
        void reverse() {
            int size = this->nodes;
            int *array= new int [size];
            Node<T>*iterador = this->head;
            for (int i = 0; i <size ; ++i) {
                array[i] = iterador->data;
                iterador = iterador->next;
            }
            iterador = this->head;
            for (int j = size-1; j >=0 ; j--) {
                iterador->data = array[j];
                iterador = iterador->next;
            }
        }

        string name() {
            return "Linked List";
        }

        BidirectionalIterator<T> begin() {
            // TODO
        }

	    BidirectionalIterator<T> end() {
            // TODO
        }

        void merge(LinkedList<T> list) {
            // TODO
        }
};

#endif