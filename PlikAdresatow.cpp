#include "PlikAdresatow.h"

//#include "Adresat.h"
#include <fstream>
#include <iostream>


using namespace std;

void PlikAdresatow::dopiszDoPliku (Adresat nowyAdresat, int IdUzytkownika){
    int i=0;
    fstream plik;
    plik.open("kontakty.txt",ios::app);
    if (plik.good() == true) {
        plik.seekg(0, ios::end);
        if (plik.tellg() != 0) {
            plik << endl;
        }
        plik<<nowyAdresat.zwrocId()<<"|"<<wszyscyUzytkownicy.zwrocIdZalogowanegoUzytkownika()<<"|"<<nowyAdresat.zwrocImie()<<"|"<<nowyAdresat.zwrocNazwisko()<<"|"<<nowyAdresat.zwrocNumerTelefonu()<<"|"<<nowyAdresat.zwrocEmail()<<"|"<<nowyAdresat.zwrocAdres()<<"|";
        i++;
    } else cout << "wystapil problem z plikiem";
    plik.close();
    plik.clear();
}
