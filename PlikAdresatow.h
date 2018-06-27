#include <iostream>
#include "Adresat.h"
//#include "Adresaci.h"
#include <vector>
#include <cstdlib>


using namespace std;

class PlikAdresatow {
private:
    void rozdzielLinieNaCechy (vector <Adresat> &wczytaniAdresaci, string linia, int idUzytkownika);
    int wczytajIdZLiniiPliku (string linia);
    int wczytajIdUzytkownikaZLiniiPliku (string linia);
    int konwertujNaInt (string liczbaStringiem);
    string scalAdresataDoLinii (Adresat &adresat, int idZalogowanegoUzytkownika);
    string konwertujIntNaString (int liczba);
public:
    void dopiszDoPliku (Adresat nowyAdresat, int IdUzytkownika);
    void podmienWpis (Adresat zedytowanyAdresat);
    void usunWpis (int idKontaktu);
    void wczytajZPliku (vector <Adresat> &wczytaniAdresaci, int idUzytkownika);
    int zwrocNajwyzszeIdZPliku ();
};
