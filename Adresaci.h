#include <vector>
#include "PlikAdresatow.h"


using namespace std;

class Adresaci {
private:
    Adresat pojedynczyAdresat;
    vector <Adresat> wczytaniAdresaci;
public:
    void dodajAdresata (int idZalogowanegoUzytkonika);
    void wyswietlWszystkichUzytkownikow ();
    //friend void wczytajZPliku();
    Adresaci ();
};
