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
    Konto(double startSaldo = 0.0, float startSollZins = 0.0f, float startDispoZins = 0.0f)
            : saldo(startSaldo), sollZins(startSollZins), dispoZins(startDispoZins) {}

    //Gibt bei erfolg 1 zurück, bei fehler -1
    int einzahlen(const double& betrag);
    int auszahlen(const double& betrag);

    void verzinsen();

    void changeSollZins(const float& newZins);
    void changeDispoZins(const float& newZins);

    double getKontostand() const;
};

#endif //P2A3_BANKKONTO_BANKKONTO_H
