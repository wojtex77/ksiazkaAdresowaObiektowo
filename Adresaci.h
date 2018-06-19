#include "Adresat.h"
#include <vector>


using namespace std;

class Adresaci {
private:
    Adresat pojedynczyAdresat;
    vector <Adresat> wczytaniAdresaci;
public:
    void dodajAdresata (int idZalogowanegoUzytkonika);
    void wyswietlWszystkichUzytkownikow ();

    Adresaci ();
};
