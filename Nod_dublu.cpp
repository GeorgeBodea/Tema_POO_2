//
// Created by George on 4/18/2020.
//

#include "Nod_dublu.h"

Nod_dublu::Nod_dublu(const char *text, int val) {
    anterior = nullptr;
    fiu1 = nullptr;
    fiu2 = nullptr;
    info = new char[strlen(text) + 1];
    strcpy(info, text);
    prioritate = val;
}

Nod_dublu::~Nod_dublu() {
    delete[] info;
    anterior = nullptr;
    fiu1 = fiu2 = nullptr;
    prioritate = 0;
}

Nod_dublu *Nod_dublu::get_fiu(int nr_fiu) {
    if (nr_fiu == 1)
        return static_cast<Nod_dublu *>(fiu1);
    else
        return fiu2;
}

void Nod_dublu::set_fiu(Nod_dublu *nod, int nr_fiu) {
    if (nr_fiu == 1)
        fiu1 = (Nod_simplu *) nod;
    else
        fiu2 = nod;
}

int Nod_dublu::get_prior() {
    return prioritate;
}

void Nod_dublu::set_tata(Nod_dublu *tata) {
    anterior = tata;

}

Nod_dublu *Nod_dublu::get_tata() {
    return anterior;
}

void urca(Nod_dublu *nod_de_inserat, Nod_simplu *inceput) {
    while (nod_de_inserat !=
           inceput->get_fiu()) {//&& nod_curent -> get_prior() > nod_curent->get_tata() -> get_prior() ) {
        if (nod_de_inserat->get_prior() <= nod_de_inserat->get_tata()->get_prior())
            break;
        swap_valori(nod_de_inserat, nod_de_inserat->get_tata());
        nod_de_inserat = nod_de_inserat->get_tata();
    }
}

Nod_dublu &Nod_dublu::operator=(const Nod_dublu &nod) {
    delete[] info;
    info = new char[strlen(nod.info) + 1];
    strcpy(info, nod.info);
    prioritate = nod.prioritate;
    return *this;
}

void swap_valori(Nod_dublu *nod1, Nod_dublu *nod2) {
    Nod_dublu *aux = new Nod_dublu;
    // Putem face operatiile urmatoare intrucat am facut supraincarcarea operatorului =
    *aux = *nod1;
    *nod1 = *nod2;
    *nod2 = *aux;
}

void coboara(Nod_dublu *nod) {
    if (nod->get_fiu(2) != nullptr) {
        if (nod->get_fiu(1)->get_prior() > nod->get_fiu(2)->get_prior()) {
            if (nod->get_fiu(1)->get_prior() > nod->get_prior()) {
                swap_valori(nod, nod->get_fiu(1));
                coboara(nod->get_fiu(1));
            }
        } else {
            if (nod->get_fiu(2)->get_prior() > nod->get_prior()) {
                swap_valori(nod, nod->get_fiu(2));
                coboara(nod->get_fiu(2));
            }
        }
    } else if (nod->get_fiu(1) != nullptr) {
        if (nod->get_fiu(1)->get_prior() > nod->get_prior()) {
            swap_valori(nod, nod->get_fiu(1));
            coboara(nod->get_fiu(1));
        }
    }
}

char *Nod_dublu::get_info() {
    return info;
}

std::ostream &operator<<(std::ostream &out, Nod_dublu &nod) {
    out << nod.get_info() << ' ' << nod.get_prior() << ' ';
    return out;
}

std::istream &operator>>(std::istream &in, Nod_dublu &nod) {
    char *aux;
    int prio_nou;
    aux = new char[256];

    in >> aux;
    delete[] nod.info;
    nod.info = new char[strlen(aux) + 1];
    strcpy(nod.info, aux);
    delete[] aux;

    in >> prio_nou;
    nod.prioritate = prio_nou;
    return in;
}

Nod_dublu::Nod_dublu(const Nod_dublu &nod) {
    info = new char[strlen(nod.info) + 1];
    strcpy(info, nod.info);
    prioritate = nod.prioritate;
}
