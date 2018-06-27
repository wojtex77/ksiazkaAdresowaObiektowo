#include "Uzytkownik.h"
#include <vector>

using namespace std;

class Uzytkownicy {
private:
    Uzytkownik nowyUzytkownik;
    Uzytkownik wczytanyUzytkownik;
    int indeksZalogowanegoUzytkownika;
    vector <Uzytkownik> wszyscyUzytkownicy;
    int IdZalogowanegoUzytkownika;

    void wczytajDoWektora(vector <Uzytkownik> &Uzytkownicy);
    void rozdzielLinieNaCechy(string linia, Uzytkownik wczytanyUzytkownik);
    int zwrocNajwyzszeIDUzytkownika (vector <Uzytkownik> &Uzytkownicy);
    void dopiszDoPliku();
    void wczytajZPliku();
    int konwertujNaInt (string liczbaStringiem);
    int zwrocIDZgodnegoUzytkownika(string login, string haslo);
    void zapiszZmienioneHasloDoPliku();
    bool SprawdzIstnienieLoginu (vector <Uzytkownik> &Uzytkownicy, string sprawdzanyLogin);
public:
    void ustawIdZalogowanegoUzytkownika (int Id);
    void rejestracja ();
    void wyswietlWszystkichUzytkownikow ();
    int zwrocIdZalogowanegoUzytkownika ();
    void logowanie ();
    void zmienHaslo(int idUzytkownika);
    void wyloguj ();
    Uzytkownicy ();
    ~Uzytkownicy();
};
