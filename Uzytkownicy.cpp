#include <iostream>
#include <string>
#include <vector>
#include "Uzytkownicy.h"

using namespace std;

void Uzytkownicy::rejestrujNowegoUzytkownika (){
    Uzytkownik nowyUzytkownik;
    string login, haslo;

    cout << "Podaj login: ";
    cin >> login;
    nowyUzytkownik.ustawLogin(login);
    cout << "Podaj haslo: ";
    cin >> haslo;
    nowyUzytkownik.ustawHaslo(haslo);
    wszyscyUzytkownicy.push_back(nowyUzytkownik);
}

    void Uzytkownicy::wyswietlDaneWszystkichUzytkonikow() {
        int iloscWpisow=wszyscyUzytkownicy.size();
        for (int i=0; i<iloscWpisow; i++){
            cout<<wszyscyUzytkownicy[i].zwrocLogin() << endl;
            cout<<wszyscyUzytkownicy[i].zwrocHaslo() << endl;
        }
    }
