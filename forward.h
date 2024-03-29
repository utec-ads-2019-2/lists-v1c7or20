#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "iterators/forward_iterator.h"

template <typename T>
class ForwardList : public List<T> {
    public:
        ForwardList() : List<T>() {}

        T front() {
            if (this->nodes == 0){
                throw "List without nodes";
            } else{
                return  this->head->data;
            }
        }

        T back() {
            if(this->nodes ==0){
                throw "List without nodes";
            } else{
                return this->tail->data;
            }
        }

        void push_front(T value) {
            Node<T>* nuevo = new Node<T>;
            nuevo->data = value;
           if(this->nodes == 0) {
               this->head = nuevo;
               this->tail = this->head;
               this->nodes++;
           }else {
               nuevo->next = this->head;
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
                    this->head = nullptr;
                    this->tail= nullptr;
                    this->nodes--;
                }else{
                    Node<T> *deleted = this->head;
                    this->head = this->head->next;
                    delete deleted;
                    this->nodes--;}
            }
        }

        void pop_back() {
            if(this->nodes == 0){
                throw  "No elements to pop";
            }else{
                if (this->nodes == 1){
                delete this->head;
                this->head = nullptr;
                this->tail= nullptr;
                this->nodes--;
                }else{
                    Node<T> *deleted = this->tail;
                    Node<T> *newtail = this->head;
                    for (int i = 1; i <this->nodes-1 ; i++) {
                        newtail = newtail->next;
                    }
                    this->tail = newtail;
                    delete deleted;
                    this->nodes--;
                }
            }
        }

        T operator[](int index) {
            // Caso de índice negativo?
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
            return this->nodes == 0;
        }

        int size() {
            return this->nodes;
        }

        void clear() {
            // Head y tail deberían volver a ser null
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
            // Podría mejorarse
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
            return "Forward List";
        }

        ForwardIterator<T> begin() {
            return ForwardIterator<T>(this->head);
        }

	    ForwardIterator<T> end() {
            return ForwardIterator<T>(this->tail->next);
        }

        void merge(ForwardList<T> list) {
            int size_list = list.nodes;
            Node<T> *iterador= list.head;
            for (int i = 0; i <size_list ; i++) {
                this->push_back(iterador->data);
                iterador = iterador->next;
            }
        }
};

#endif

//este algoritmo es hecho por Victor ->zZzzZ