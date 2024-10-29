//Modul:    Programmieren 2 - Praktikum
//Datum:    08.10.24 - 15:32:34
//Name:     Lars Ebbeke
//Aufgabe:  P2A3-Bankkonto
//Todo:
//-

#include <cmath>
#include "bankkonto.h"

void Konto::einzahlen(const double &betrag) {
    saldo += betrag;
}

void Konto::auszahlen(const double &betrag) {
    saldo += -betrag;
}

void Konto::verzinsen() {
    //ist das Konto im Minus muss der andere Zins angewendet werden
    if (saldo > 0) {
        saldo *= 1 + sollZins/100;
    }
    else {
        saldo *= 1 + dispoZins/100;
    }
}

void Konto::changeSollZins(const float &newZins) {
    sollZins = newZins;
}

void Konto::changeDispoZins(const float &newZins) {
    dispoZins = newZins;
}

double Konto::getKontostand() const {
    //getKontostand() gibt den Wert auf zwei nachkommastellen genau an, intern wird aber mit maximaler präzision gearbeitet
    return round(saldo*100)/100;
}