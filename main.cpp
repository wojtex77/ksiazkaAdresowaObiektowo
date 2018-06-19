#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include "Uzytkownicy.h"
#include "Adresaci.h"

using namespace std;

char menuGlowne ();
char menuKsiazki();

int main() {
    char wyborMenuGlowne;
    char wyborMenuKsiazki;

    Uzytkownicy uzytkownicyKsiazki;
    Adresaci adresaciKsiazki;

    while (1) {
        if (uzytkownicyKsiazki.zwrocIdZalogowanegoUzytkownika()==0) {
            wyborMenuGlowne=menuGlowne();
            switch(wyborMenuGlowne) {
            case '1': {
                uzytkownicyKsiazki.rejestracja();
                break;
            }
            case '2': {
                uzytkownicyKsiazki.logowanie();
                break;
            }
            case '0': {
                cout << "Do zobaczenia!";
                Sleep(2000);
                exit(0);
                break;
            }
            default: {
                cout << "Niepoprawny wybor";
                Sleep(1500);
            }
            }
        } else {
            wyborMenuKsiazki=menuKsiazki();
            switch (wyborMenuKsiazki) {
            case '1': {
                adresaciKsiazki.dodajAdresata(uzytkownicyKsiazki.zwrocIdZalogowanegoUzytkownika(), adresaciKsiazki.zwrocNajwyzszeIdKontaktu());
                Sleep(1500);
                break;
            }
            case '7':{
                uzytkownicyKsiazki.zmienHaslo(uzytkownicyKsiazki.zwrocIdZalogowanegoUzytkownika());
                break;
            }
            case '0':{
                uzytkownicyKsiazki.wyloguj();
                break;
            }
            case '6':{
                adresaciKsiazki.wyswietlWszystkichAdresatow();
                system("pause");
                break;
            }
            default:
                cout << "Niepoprawny wybor";
                Sleep(1500);
            }
        }
    }

    return 0;
}


char menuGlowne () {
    char wybor;

    system("cls");
    cout << "Ksiazka Adresowa >> Menu Glowne" << endl << "------------------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "0. Zakoncz" << endl;
    cout << endl << "Twoj wybor: ";
    cin >> wybor;
    cin.sync();
    cout << endl << "------------------------------------" << endl;
    return wybor;
}

char menuKsiazki() {
    char wybor;

    system("cls");
    cout << "Ksiazka Adresowa >> Menu Ksiazki" << endl << "------------------------------------"  << endl;
    cout << "1. Dodaj kontakt" << endl;
    cout << "2. Szukaj po imieniu" << endl;
    cout << "3. Szukaj po nazwisku" << endl;
    cout << "4. Edytuj kontakt" << endl;
    cout << "5. Usun kontakt" << endl;
    cout << "6. Wyswietl wszystkie kontakty" << endl << endl;
    cout << "7. Zmien Haslo" << endl;
    cout << "0. Wyloguj" << endl;
    cout << endl << "Twoj wybor: ";
    cin >> wybor;
    cin.sync();
    cout << endl << "------------------------------------" << endl;
    return wybor;
}

