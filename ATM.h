//
// Created by sebib on 4/2/2023.
//

#ifndef LAB2_ATM_H
#define LAB2_ATM_H

#include "Collection.h"
#include "Tranzactie.h"

class ATM{
private:
    vector<string> istoricTranzactii;
    int id;
public:
    ATM();
    ~ATM();
    Collection adaugareBancnote();
    bool verificarePlata(int nrBancnote, int sumaCareTrebuiePlatita, vector<int> bancnote,  vector<int> &occur_bancnote);
    void plataCuBancnote(int nrBancnote, vector<int> bancnote, vector<int> &occur_bancnote);
    void afisareTranzactii();
};

#endif //LAB2_ATM_H