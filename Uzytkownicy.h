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
    int zwrocNajwyzszeIDUzytkownika (vector <Uzytkownik> &Uzytkownicy);
    void dopiszDoPliku();
    void wczytajZPliku();
    int konwertujNaInt (string liczbaStringiem);
    int IdZalogowanegoUzytkownika;
    int zweryfikujUzytkownika(string login, string haslo);
public:
    void rejestracja ();
    void wyswietlWszystkichUzytkownikow ();
    int zwrocIdZalogowanegoUzytkownika ();
    void logowanie ();
    Uzytkownicy ();
};
