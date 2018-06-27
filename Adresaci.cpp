#include <iostream>
#include <vector>
#include <windows.h>
#include "Adresaci.h"



using namespace std;

bool Adresaci::szukajPoId(int IdKontaktu) {
    vector <int> idZgodnychWynikow;
    int iloscWpisow=wczytaniAdresaci.size();
    for (int i=0; i<iloscWpisow; i++) {
        if (wczytaniAdresaci[i].zwrocId()==IdKontaktu) idZgodnychWynikow.push_back(wczytaniAdresaci[i].zwrocId());
    }
    if (idZgodnychWynikow.empty()==true) return false;
    else {
        wyswietlZgodneWyniki(idZgodnychWynikow);
        idKontaktuDoEdycji=idZgodnychWynikow[0];
        return true;
    };
}

int Adresaci::menuZmiany () {
    int wybor;
    cout <<endl<< "-----------------------------" << endl;
    cout << "Wybierz co chcesz zmienic: " << endl;
    cout << "1. Imie" << endl;
    cout << "2. Nazwisko" << endl;
    cout << "3. e-mail" << endl;
    cout << "4. Telefon" << endl;
    cout << "5. Adres" << endl;
    cout << "0. Zakoncz edycje" << endl;
    cin >> wybor;
    return wybor;
}

int Adresaci::wprowadzZmiany (int wybranaCecha){
    string imie,nazwisko,email,telefon,adres;
    int i=0;
    switch (wybranaCecha){
        case 1:
            {
                cout << "Wprowadz nowe imie: ";
                cin >> imie;
                while (idKontaktuDoEdycji!=wczytaniAdresaci[i].zwrocId()) i++;
                wczytaniAdresaci[i].ustawImie(imie);
                break;
            }
        case 2:
            {
                cout << "Wprowadz nowe nazwisko: ";
                cin >> nazwisko;
                while (idKontaktuDoEdycji!=wczytaniAdresaci[i].zwrocId()) i++;
                wczytaniAdresaci[i].ustawNazwisko(nazwisko);
                break;
            }
        case 3:
            {
                cout << "Wprowadz nowy email: ";
                cin >> email;
                while (idKontaktuDoEdycji!=wczytaniAdresaci[i].zwrocId()) i++;
                wczytaniAdresaci[i].ustawEmail(email);
                break;
            }
        case 4:
            {
                cout << "Wprowadz nowy telefon: ";
                cin >> telefon;
                while (idKontaktuDoEdycji!=wczytaniAdresaci[i].zwrocId()) i++;
                wczytaniAdresaci[i].ustawNumerTelefonu(telefon);
                break;
            }
        case 5:
            {
                cout << "Wprowadz nowy adres: ";
                cin >> adres;
                while (idKontaktuDoEdycji!=wczytaniAdresaci[i].zwrocId()) i++;
                wczytaniAdresaci[i].ustawAdres(adres);
                break;
            }
        default:
            break;


        }
        return i;
}


void Adresaci::edytujAdresata(int idZalogowanegoUzytkownika) {
    int idKontaktu;
    cout << "Podaj ID adresata do edycji: ";
    cin >> idKontaktu;
    if(szukajPoId(idKontaktu)==false) {
        cout << "Nie znaleziono kontaktu o podanym ID";
        Sleep(1000);
    } else {
        int wybor=100;
        while (wybor!=0){
            wybor=menuZmiany();
            int indeksEdytowanegoWpisu=wprowadzZmiany(wybor);
            if (wybor!=0){
                PlikAdresatow plik;
                plik.podmienWpis(wczytaniAdresaci[indeksEdytowanegoWpisu]);
            }
        }
    }
}

int Adresaci::zwrocIndeksWpisuZWektora(int idKontaktu){
    int i=0;
    while (idKontaktuDoEdycji!=wczytaniAdresaci[i].zwrocId()) i++;
    return i;
}

void Adresaci::usunAdresata(int idZalogowanegoUzytkownika) {
    int idKontaktu;
    char wybor;
    cout << "Podaj ID adresata do usuniecia: ";
    cin >> idKontaktu;
    if(szukajPoId(idKontaktu)==false) {
        cout << "Nie znaleziono kontaktu o podanym ID";
        Sleep(1000);
    } else {
        cout << "Czy chcesz usunac kontakt? ";
        cin >> wybor;
        if (wybor=='t'){
            PlikAdresatow plik;
            plik.usunWpis(idKontaktu);
        }

    }
}

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
