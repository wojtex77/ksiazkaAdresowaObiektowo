#include <iostream>
#include <string>
#include <vector>
#include "Uzytkownik.h"

using namespace std;

class Uzytkownicy {
private:
    Uzytkownik nowyUzytkownik;
    Uzytkownik wczytanyUzytkownik;
    vector <Uzytkownik> wszyscyUzytkownicy;
    void wczytajDoWektora(vector <Uzytkownik> &Uzytkownicy);
    void rozdzielLinieNaCechy(string linia, Uzytkownik wczytanyUzytkownik);
    int konwertujNaInt (string liczbaStringiem);
public:
    int zwrocNajwyzszeIDUzytkownika (vector <Uzytkownik> &Uzytkownicy);
    void rejestracja ();
    void dopiszDoPliku();
    void wczytajZPliku();
    void wyswietlWszystkichUzytkownikow ();
    Uzytkownicy ();
};
