#include <iostream>
#include "Adresat.h"
#include <vector>
#include <cstdlib>
//#include "Adresaci.h"


using namespace std;

class PlikAdresatow {
private:

    void rozdzielLinieNaCechy (vector <Adresat> &wczytaniAdresaci, string linia);
    int konwertujNaInt (string liczbaStringiem);


public:
    void dopiszDoPliku (Adresat nowyAdresat, int IdUzytkownika);
    void wczytajZPliku (vector <Adresat> &wczytaniAdresaci);
    //PlikAdresatow();
};
