#include <iostream>
#include <string>
#include <vector>
#include "Uzytkownicy.h"

using namespace std;

int main()
{
    Uzytkownicy wszyscyUzytkownicy;
    int liczba=0;
    while (1){
        wszyscyUzytkownicy.rejestracja();
        wszyscyUzytkownicy.dopiszDoPliku();
    }
    return 0;
}
