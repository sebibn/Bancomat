//
// Created by sebib on 3/21/2023.
//

#include "Collection.h"
#include <algorithm>
#include <iostream>

using namespace std;

Collection::Collection() {
}

Collection::~Collection() {
}

// Returneaza pozitia lui elem daca il gaseste in vector
int Collection::getAt(TElem elem) {
    int sizeElements = this->elements.size();
    for (int i = 0; i < sizeElements; i ++) {
//        int elementActual = this->elements[i];
//        int elementActual = elements.get_At(i);
        int elementActual = elements.get_at(i);
        if (elementActual == elem) // Am gasit elem in vectorul nostru de this->elements
            return i;
    }
    return -1;
}

void Collection::add(TElem bancnota, TElem nrOccurencesDatDeUtilizator) {

//    cout << "Add element:\n";

    int position_elem = this->getAt(bancnota);
//    cout << position_elem << "\n";
    if (position_elem != -1) // Exista in sirul nostru
    {
        int aparitii_elem = occurences.get_at(position_elem);

//        cout << aparitii_elem << "\n";

        aparitii_elem++;
//        occurences.addAt(position_elem, aparitii_elem);
        occurences.set_at(position_elem, aparitii_elem);
    }
        // Nu exista acest element in sirul nostru
    else {
        this->elements.push_back(bancnota);
        this->occurences.push_back(nrOccurencesDatDeUtilizator);
    }

    /*for(int i = 0; i < elements.size(); i ++)
        cout << elements.get_at(i) << " " << occurences.get_at(i) << "\n";
    cout << "Terminat\n";*/
}

vector<int> Collection::getElems(vector<int> &listElements) {
    elements.showElems(listElements, elements);

    return listElements;
}

int Collection::getSize() {
//    return elements.getNrElems();
    return elements.size();
}

vector<int> Collection::getOccurences (vector<int> &occurElements) {
    elements.showElems(occurElements, occurences);

    return occurElements;
}
