//
// Created by sebib on 3/21/2023.
//

#ifndef LAB2_COLLECTION_H
#define LAB2_COLLECTION_H

#include <iostream>
#include <vector>
#include "VectorDinamic.h"
#include "List.h"

using namespace std;

class Collection {
private:
    List<int> elements;
    List<int> occurences;

public:
    Collection();
    ~Collection();

    vector<int> getElems(vector<int> &listElements);
    vector<int> getOccurences(vector<int> &occurElements);

    void add(int elem, int nrOccurencesDatDeUtilizator);
    int getAt(int position);
    int getSize();
};

#endif //LAB2_COLLECTION_H
