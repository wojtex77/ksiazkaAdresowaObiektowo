#include <iostream>
#include <string>
#include <vector>
#include "Uzytkownicy.h"
#include <fstream>

using namespace std;

int Uzytkownicy::zwrocNajwyzszeIDUzytkownika (vector <Uzytkownik> &Uzytkownicy){
    int iloscWpisow=Uzytkownicy.size();
    int najwyzsza=0;
    if (iloscWpisow==0);
    else{
        for (int i=0; i<iloscWpisow; i++){
            if (Uzytkownicy[i].zwrocID()>najwyzsza) najwyzsza=Uzytkownicy[i].zwrocID();
        }
    }
    return najwyzsza;
}

void Uzytkownicy::rejestracja (){
    string login, haslo;
    int idUzytkownika=zwrocNajwyzszeIDUzytkownika(wszyscyUzytkownicy);

    cout << "Podaj login: ";
    cin >> login;
    nowyUzytkownik.ustawLogin(login);
    cout << "Podaj haslo: ";
    cin >> haslo;
    nowyUzytkownik.ustawHaslo(haslo);
    nowyUzytkownik.ustawID(idUzytkownika+1);
    wszyscyUzytkownicy.push_back(nowyUzytkownik);
}

void Uzytkownicy::dopiszDoPliku(){
    fstream plik;
    plik.open("users.txt",ios::app);
    if (plik.good() == true) {
        plik.seekg(0, ios::end);
        if (plik.tellg() != 0) {
            plik << endl;
        }
        plik<<nowyUzytkownik.zwrocID()<<"|"<<nowyUzytkownik.zwrocLogin()<<"|"<<nowyUzytkownik.zwrocHaslo()<<"|";
    } else cout << "wystapil problem z plikiem";
    plik.close();
    plik.clear();
}
