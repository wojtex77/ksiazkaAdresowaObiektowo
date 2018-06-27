#include <vector>
#include "PlikAdresatow.h"


using namespace std;

class Adresaci {
private:
    Adresat pojedynczyAdresat;
    vector <Adresat> wczytaniAdresaci;
    void wyswietlZgodneWyniki (vector <int> &idZgodnychWynikow);
    bool szukajPoId(int IdKontaktu);
    int menuZmiany();
    int idKontaktuDoEdycji;
    int wprowadzZmiany (int wybranaCecha);
    int zwrocIndeksWpisuZWektora (int idKontaktu);
public:
    int zwrocNajwyzszeIdKontaktu ();
    void dodajAdresata (int idZalogowanegoUzytkonika, int najwyzszeIdKontaktu);
    void wyswietlWszystkichAdresatow ();
    void szukajPoImieniu ();
    void szukajPoNazwisku();
    void edytujAdresata(int idZalogowanegoUzytkownika);
    void usunAdresata(int idZalogowanegoUzytkownika);
    Adresaci (int idZalogowanegoUzytkownika);
};
