#include <iostream>
#include <vector>
#include "Adresaci.h"


using namespace std;

Adresaci::Adresaci(){}

void Adresaci::wyswietlWszystkichUzytkownikow(){
    cout << wczytaniAdresaci[0].zwrocImie() << " " << wczytaniAdresaci[0].zwrocNazwisko() <<endl;
    cout << wczytaniAdresaci[0].zwrocNumerTelefonu() << endl;
    cout << wczytaniAdresaci[0].zwrocEmail() << endl;
    cout << wczytaniAdresaci[0].zwrocAdres() << endl;

}

void Adresaci::dodajAdresata (int idZalogowanegoUzytkownika){
    string imie, nazwisko, numerTelefonu, email, adres;

    cout << "Imie: ";
    getline(cin,imie);
    pojedynczyAdresat.ustawImie(imie);
    cout << "Nazwisko: ";
    cin >> nazwisko;
    pojedynczyAdresat.ustawNazwisko(nazwisko);
    cout << "Numer telefonu: ";
    cin >> numerTelefonu;
    pojedynczyAdresat.ustawNumerTelefonu(numerTelefonu);
    cout << "Email: ";
    cin >> email;
    pojedynczyAdresat.ustawEmail(email);
    cout << "Adres: ";
    cin.sync();
    getline(cin, adres);
    pojedynczyAdresat.ustawAdres(adres);

    wczytaniAdresaci.push_back(pojedynczyAdresat);

}
