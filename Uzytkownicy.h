#include <iostream>
#include <string>
#include <vector>
#include "Uzytkownik.h"

using namespace std;

class Uzytkownicy {
private:
    Uzytkownik nowyUzytkownik;
    vector <Uzytkownik> wszyscyUzytkownicy;
public:
    int zwrocNajwyzszeIDUzytkownika (vector <Uzytkownik> &Uzytkownicy);
    void rejestracja ();
    void dopiszDoPliku();
};
