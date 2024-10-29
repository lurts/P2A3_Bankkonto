//Modul:    Programmieren 2 - Praktikum
//Datum:    08.10.24 - 15:32:34
//Name:     Lars Ebbeke
//Aufgabe:  P2A3-Bankkonto
//Todo:
//-

#include <cmath>
#include <iostream>
#include "bankkonto.h"

int Konto::einzahlen(const double &betrag) {
    //Negative beträge sollen nicht eingezahlt werden dürfen, dafür ist die auszahlen() funktion
    if (betrag > 0) {
        saldo += betrag;
        std::cout << betrag << " eingezahlt\n";
        return 1;
    }
    //Bei Fehler -1 zurückgeben
    return -1;
}

int Konto::auszahlen(const double &betrag) {
    //Negative beträge sollen nicht ausgezahlt werden können dafür ist die einzahlen() funktion
    if (betrag > 0) {
        saldo += -betrag;
        std::cout << betrag << " ausgezahlt\n";
        return 1;
    }
    //Bei Fehler -1 zurückgeben
    return -1;
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