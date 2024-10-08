//Modul:    Programmieren 2 - Praktikum
//Datum:    08.10.24 - 15:32:34
//Name:     Lars Ebbeke
//Aufgabe:  P2A3-Bankkonto
//Todo:
//-

#ifndef P2A3_BANKKONTO_BANKKONTO_H
#define P2A3_BANKKONTO_BANKKONTO_H

class Konto{
private:
    double saldo;
    float sollZins;
    float dispoZins;

public:
    void einzahlen(const double& betrag);
    void auszahlen(const double& betrag);

    void verzinsen();

    void changeSollZins(const float& newZins);
    void changeDispoZins(const float& newZins);

    double kontostand() const;
};

#endif //P2A3_BANKKONTO_BANKKONTO_H
