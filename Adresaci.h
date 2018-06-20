#include <vector>
#include "PlikAdresatow.h"


using namespace std;

class Adresaci {
private:
    Adresat pojedynczyAdresat;
    vector <Adresat> wczytaniAdresaci;
    void wyswietlZgodneWyniki (vector <int> &idZgodnychWynikow);
public:
    int zwrocNajwyzszeIdKontaktu ();
    void dodajAdresata (int idZalogowanegoUzytkonika, int najwyzszeIdKontaktu);
    void wyswietlWszystkichAdresatow ();
    void szukajPoImieniu ();
    void szukajPoNazwisku();
    Adresaci (int idZalogowanegoUzytkownika);
};
