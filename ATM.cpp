//
// Created by sebib on 4/2/2023.
//

#include "ATM.h"
#include "Tranzactie.h"
#include "fstream"

ATM::ATM() {
    this->id = 0;
}

ATM::~ATM() {

}

Collection ATM::adaugareBancnote() {

    Collection collection;

    ifstream fin("Bancnote.txt");

    int b, occ_b;
    while ( fin >> b >> occ_b) {
        collection.add(b, occ_b);
    }

    return collection;
}

bool ATM::verificarePlata(int nrBancnote, int sumaCareTrebuiePlatita, vector<int> bancnote, vector<int> &occur_bancnote) {
    int suma = 0;

    for(int i = 0; i < nrBancnote; i ++)
        suma += bancnote[i] * occur_bancnote[i];

    return (suma >= sumaCareTrebuiePlatita);
}

void ATM::plataCuBancnote(int nrBancnote, vector<int> bancnote, vector<int> &occur_bancnote) {

    int sumaCareTrebuiePlatita;

    cout << "Introduceti suma care trebuie platita:";
    cin >> sumaCareTrebuiePlatita;

    bool putemPlati = verificarePlata(nrBancnote, sumaCareTrebuiePlatita, bancnote, occur_bancnote);

    if (putemPlati)
    {
        vector<Tranzactie*> tranzactiiDeStocat;

        int suma = 0;
        int id = 0;
        for (int i = 0; i < nrBancnote; i++) {
            string bancnotaFolosita;
            int nrBancnoteFolosite = 0;
            if (occur_bancnote[i] > 0) {
                while (suma + bancnote[i] <= sumaCareTrebuiePlatita && occur_bancnote[i] > 0) // suma + bancnota[i]
                {
                    suma += bancnote[i];
                    bancnotaFolosita = to_string(bancnote[i]);
                    nrBancnoteFolosite++;
                    occur_bancnote[i] --;
                }
                if(nrBancnoteFolosite > 0) {
                    auto* tranzactie = new Tranzactie(id++, bancnote[i], bancnotaFolosita, nrBancnoteFolosite);
                    tranzactiiDeStocat.emplace_back(tranzactie);
                }
            }
        }

        int sumaTotala = 0;
        for (auto *i: tranzactiiDeStocat) {
            sumaTotala += i->getSuma() * i->getNrBancnote_TipBancnota();
        }

        cout << "\nTranzactia cu suma totala de " << sumaTotala << " in care s-au folosit bancnotele:";
        cout << "\n";
        for (auto *i: tranzactiiDeStocat) {
            cout << "Tip bancnota: " << i->getTipBancnote() << ", Nr bancnote folosite: " << i->getNrBancnote_TipBancnota() << "\n";
        }
        cout << "\n";

        // intrebam utilizatorul daca doreste sa faca plata
        int optiune = 0;

        cout << "Confirmati plata tastand '1' \n";
        cout << "Anulati plata tastand '2' \n";

        cin >> optiune;

        if(optiune == 2){
            cout << "Plata a fost anulata.\n\n";
            for (auto *i: tranzactiiDeStocat) {
                for (int j = 0; j < nrBancnote; j++) {
                    if (i->getSuma() == bancnote[j])
                        occur_bancnote[j] += i->getNrBancnote_TipBancnota();
                }
            }
            return;
        }

        string bancnoteFolosite;
        for (auto *i: tranzactiiDeStocat) {
            bancnoteFolosite += "Tip bancnota: " + i->getTipBancnote() +
                    ", Nr bancnote folosite: " + to_string(i->getNrBancnote_TipBancnota()) + "\n";
        }
        istoricTranzactii.push_back("Tranzactia cu ID-ul " +
        to_string(this->id++) + " in valoare de " + to_string(suma)
        + " in care se folosesc bancnotele: \n" + bancnoteFolosite + "\n");
        cout << "Plata confirmata.\n\n";
    }
    else
    {
        cout << "Nu aveti suficiente fonduri.\n\n";
        return;
    }
}

void ATM::afisareTranzactii() {
    for (const auto& i: istoricTranzactii) {
        cout << i;
    }
}
