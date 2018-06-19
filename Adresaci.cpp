#include <iostream>
#include <vector>
#include "Adresaci.h"


using namespace std;

Adresaci::Adresaci(){
    PlikAdresatow plik;
    plik.wczytajZPliku(wczytaniAdresaci);
}

void Adresaci::wyswietlWszystkichAdresatow() {
    if (wczytaniAdresaci.empty()!=true) {
        int iloscWpisow=wczytaniAdresaci.size();
        for (int i=0; i<iloscWpisow; i++) {
            cout << wczytaniAdresaci[i].zwrocId() << "."<<endl;
            cout << wczytaniAdresaci[i].zwrocImie() << " " << wczytaniAdresaci[i].zwrocNazwisko() <<endl;
            cout << wczytaniAdresaci[i].zwrocNumerTelefonu() << endl;
            cout << wczytaniAdresaci[i].zwrocEmail() << endl;
            cout << wczytaniAdresaci[i].zwrocAdres() << endl<<endl;
        }
    }
}

void Adresaci::dodajAdresata (int idZalogowanegoUzytkownika, int najwyzszeIdKontaktu){
    string imie, nazwisko, numerTelefonu, email, adres;
    pojedynczyAdresat.ustawId(najwyzszeIdKontaktu+1);
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

int Adresaci::zwrocNajwyzszeIdKontaktu(){
    int najwyzszeId=0;
    if (wczytaniAdresaci.empty()==true);
    else {
        int iloscWpisow=wczytaniAdresaci.size();
        for (int i=0; i<iloscWpisow; i++){
            if (wczytaniAdresaci[i].zwrocId()>najwyzszeId) najwyzszeId=wczytaniAdresaci[i].zwrocId();
        }
    }
    return najwyzszeId;
}
