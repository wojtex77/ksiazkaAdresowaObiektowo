#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include "Uzytkownicy.h"

using namespace std;

int main() {

Uzytkownicy uzytkownicyKsiazki;
    uzytkownicyKsiazki.rejestracja();
    uzytkownicyKsiazki.logowanie();
    uzytkownicyKsiazki.zmienHaslo(uzytkownicyKsiazki.zwrocIdZalogowanegoUzytkownika());
    Sleep(1000);
    uzytkownicyKsiazki.wyloguj();
    cout << uzytkownicyKsiazki.zwrocIdZalogowanegoUzytkownika();
    return 0;
}
