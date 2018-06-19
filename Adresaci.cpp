#include <iostream>
#include <vector>
#include "Adresaci.h"


using namespace std;

Adresaci::Adresaci(){
    PlikAdresatow plik;
    plik.wczytajZPliku(wczytaniAdresaci);
}

void Adresaci::wyswietlWszystkichUzytkownikow() {
    if (wczytaniAdresaci.empty()!=true) {
        int iloscWpisow=wczytaniAdresaci.size();
        for (int i=0; i<iloscWpisow; i++) {
            cout << wczytaniAdresaci[i].zwrocImie() << " " << wczytaniAdresaci[i].zwrocNazwisko() <<endl;
            cout << wczytaniAdresaci[i].zwrocNumerTelefonu() << endl;
            cout << wczytaniAdresaci[i].zwrocEmail() << endl;
            cout << wczytaniAdresaci[i].zwrocAdres() << endl;
        }
    }
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
    PlikAdresatow plik;
    plik.dopiszDoPliku(pojedynczyAdresat,idZalogowanegoUzytkownika);

}
