#include <iostream>
#include <string>
#include <vector>
#include "Uzytkownik.h"

using namespace std;

class Uzytkownicy {
private:
    Uzytkownik tymczasowyUzytkownik;
    vector <Uzytkownik> wszyscyUzytkownicy;
public:
    void rejestrujNowegoUzytkownika ();
    void wyswietlDaneWszystkichUzytkonikow ();
};
