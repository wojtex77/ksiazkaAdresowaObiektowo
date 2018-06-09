#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include "Uzytkownicy.h"

using namespace std;

int main() {
    Uzytkownicy uzytkownicyKsiazki;
    uzytkownicyKsiazki.rejestracja();
    uzytkownicyKsiazki.wyswietlWszystkichUzytkownikow();
    return 0;
}
