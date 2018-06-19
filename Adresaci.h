#include <vector>
#include "PlikAdresatow.h"


using namespace std;

class Adresaci {
private:
    Adresat pojedynczyAdresat;
    vector <Adresat> wczytaniAdresaci;
public:
    int zwrocNajwyzszeIdKontaktu ();
    void dodajAdresata (int idZalogowanegoUzytkonika, int najwyzszeIdKontaktu);
    void wyswietlWszystkichAdresatow ();
    Adresaci ();
};
