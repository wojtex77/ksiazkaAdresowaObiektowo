#include <iostream>
#include <string>
#include <vector>
#include "Uzytkownicy.h"
#include <fstream>
#include <cstdlib>


using namespace std;

int Uzytkownicy::zwrocNajwyzszeIDUzytkownika (vector <Uzytkownik> &Uzytkownicy) {
    int iloscWpisow=Uzytkownicy.size();
    int najwyzsza=0;
    if (iloscWpisow==0);
    else {
        for (int i=0; i<iloscWpisow; i++) {
            if (Uzytkownicy[i].zwrocID()>najwyzsza) najwyzsza=Uzytkownicy[i].zwrocID();
        }
    }
    return najwyzsza;
}

void Uzytkownicy::rejestracja () {
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
    dopiszDoPliku();
}

void Uzytkownicy::dopiszDoPliku() {
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

void Uzytkownicy::wczytajDoWektora(vector <Uzytkownik> &Uzytkownicy) {
    fstream plik;
    string linia;
    plik.open("users.txt",ios::in);
    if (plik.good() == true)
    {
        do {
            getline(plik,linia);
            if (linia.empty());
            else rozdzielLinieNaCechy(linia, wczytanyUzytkownik);
        }
        while (!plik.eof());
    }
    plik.close();
    plik.clear();
}

void Uzytkownicy::wczytajZPliku(){
    wczytajDoWektora(wszyscyUzytkownicy);
}

int Uzytkownicy::konwertujNaInt (string liczbaStringiem) {
    int liczba = atoi(liczbaStringiem.c_str());
    return liczba;
}

void Uzytkownicy::rozdzielLinieNaCechy(string linia, Uzytkownik wczytanyUzytkownik){
    int i=0, dlugoscLogin, dlugoscHaslo;
    string id, login, haslo;
    vector <int> pozycjeKoncaCechy;
    int dlugoscLinii = linia.length();
    while (i<dlugoscLinii) {
        char znak=linia[i];
        if (znak=='|')
            pozycjeKoncaCechy.push_back(i);
        i++;
    }
    wczytanyUzytkownik.ustawID(konwertujNaInt(linia.substr(0,pozycjeKoncaCechy[0])));

    dlugoscLogin=pozycjeKoncaCechy[1]-pozycjeKoncaCechy[0]-1;
    wczytanyUzytkownik.ustawLogin(linia.substr(pozycjeKoncaCechy[0]+1,dlugoscLogin));

    dlugoscHaslo=pozycjeKoncaCechy[2]-pozycjeKoncaCechy[1]-1;
    wczytanyUzytkownik.ustawHaslo(linia.substr(pozycjeKoncaCechy[1]+1,dlugoscHaslo));

    wszyscyUzytkownicy.push_back(wczytanyUzytkownik);
}

void Uzytkownicy::wyswietlWszystkichUzytkownikow(){
    cout << "Wszyscy uzytkownicy:"<<endl;
    int ilosc=wszyscyUzytkownicy.size();
    for (int i=0; i<ilosc; i++){
        cout << wszyscyUzytkownicy[i].zwrocID()<< " ";
        cout << wszyscyUzytkownicy[i].zwrocLogin()<< " ";
        cout << wszyscyUzytkownicy[i].zwrocHaslo()<< " "<<endl;
    }
};

Uzytkownicy::Uzytkownicy(){
    wczytajZPliku();
}
