//Modul:    Programmieren 2 - Praktikum
//Datum:    08.10.24 - 15:32:19
//Name:     Lars Ebbeke
//Aufgabe:  P2A3-Bankkonto
//Todo:
//-

#include <iostream>
#include <random>
#include <cmath>
#include "bankkonto.h"

const double min = -500.0;
const double max = 500.0;

int main() {
    //ein Konto-Objekt erzeugen, Objekt liegt auf dem Stack wird also automatisch wieder freigegeben benötigt also kein "delete"
    Konto testKonto(100.0, 1.25, 2.5);

    //zufallsgenerator initialisieren
    //Diesen Generator und wie der zu benutzen ist hab ich aus dem Netz. CLion meinte std::rand() sei nicht gut
    std::random_device rd;  // Zufallsquelle
    std::mt19937 gen(rd()); // Zufallszahlengenerator
    std::uniform_real_distribution<> dist(min, max);

    //100 mal verzinsen, ein/auszahlen und kontostand ausgeben
    for (int i = 1; i <= 100; ++i) {
        double kontobewegung = dist(gen);
        //auf zwei nachkommastellen runden
        kontobewegung = round(kontobewegung*100)/100;

        //Konto wird vor jeder Kontobewegung verzinst
        testKonto.verzinsen();

        std::cout << "Jahr\t" << i << "\tKontostand:\t" << testKonto.getKontostand() << "\n";

        if (kontobewegung > 0) {
            testKonto.einzahlen(kontobewegung);
            std::cout << kontobewegung << " eingezahlt\n";
        }
        else {
            testKonto.auszahlen(-kontobewegung);
            std::cout << -kontobewegung << " ausgezahlt\n";
        }
    }
}
