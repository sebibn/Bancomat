//
// Created by sebib on 16-May-23.
//

#ifndef BANCOMAT_NODE_H
#define BANCOMAT_NODE_H

template<typename T>
class List;

template<class T>
class Node {
private:
    T info;
    Node<T> *next;
    Node<T> *prev;
public:
    Node(T info, Node<T> *next, Node<T> *prev) : info(info), next(next), prev(prev) {}

    Node(T info) {
        this->info = info;
        next = nullptr;
        prev = nullptr;
    }

    friend class List<T>;
};

#endif //BANCOMAT_NODE_H
