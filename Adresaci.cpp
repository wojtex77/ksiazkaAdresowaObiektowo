#include <iostream>
#include <vector>
#include "Adresaci.h"


using namespace std;

void Adresaci::wyswietlZgodneWyniki (vector <int> &idZgodnychWynikow) {
    int iloscZgodnychWynikow=idZgodnychWynikow.size();
    int i=0;
    if (idZgodnychWynikow.empty()==true) cout <<endl<< "Brak zgodnych wynikow"<< endl;
    else {
        cout << "Pasujace wyniki:" << endl << endl;
        for (int j=0; j<iloscZgodnychWynikow; j++) {
            while (idZgodnychWynikow[j]!=wczytaniAdresaci[i].zwrocId()) i++;
            cout << "nazwa/ID: " << wczytaniAdresaci[i].zwrocImie()<< " "<<wczytaniAdresaci[i].zwrocNazwisko()<< "/"<< wczytaniAdresaci[i].zwrocId()<< endl;
            cout << "tel.:     " << wczytaniAdresaci[i].zwrocNumerTelefonu()<< endl;
            cout << "e-mail:   " << wczytaniAdresaci[i].zwrocEmail()<< endl;
            cout << "Adres:    " << wczytaniAdresaci[i].zwrocAdres()<< endl << endl;
            i=0;
        }
    }
    system("pause");
}

void Adresaci::szukajPoImieniu () {
    vector <int> idZgodnychWynikow;
    int iloscWpisow=wczytaniAdresaci.size();
    string szukaneImie;
    cout << "KSIAZKA ADRESOWA >> SZUKAJ PO IMIENIU" << endl << endl;
    cout << "Wpisz szukane imie: ";
    getline(cin,szukaneImie);
    for (int i=0; i<iloscWpisow; i++) {
        if (wczytaniAdresaci[i].zwrocImie()==szukaneImie) idZgodnychWynikow.push_back(wczytaniAdresaci[i].zwrocId());
    }
    wyswietlZgodneWyniki(idZgodnychWynikow);
}

void Adresaci::szukajPoNazwisku () {
    vector <int> idZgodnychWynikow;
    int iloscWpisow=wczytaniAdresaci.size();
    string szukaneNazwisko;
    cout << "KSIAZKA ADRESOWA >> SZUKAJ PO NAZWISKU" << endl << endl;
    cout << "Wpisz szukane nazwisko: ";
    getline(cin,szukaneNazwisko);
    for (int i=0; i<iloscWpisow; i++) {
        if (wczytaniAdresaci[i].zwrocNazwisko()==szukaneNazwisko) idZgodnychWynikow.push_back(wczytaniAdresaci[i].zwrocId());
    }
    wyswietlZgodneWyniki(idZgodnychWynikow);
}

Adresaci::Adresaci(int idZalogowanegoUzytkownika) {
    PlikAdresatow plik;
    plik.wczytajZPliku(wczytaniAdresaci, idZalogowanegoUzytkownika);
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

void Adresaci::dodajAdresata (int idZalogowanegoUzytkownika, int najwyzszeIdKontaktu) {
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

int Adresaci::zwrocNajwyzszeIdKontaktu() {
    PlikAdresatow plik;
    return plik.zwrocNajwyzszeIdZPliku();
}
