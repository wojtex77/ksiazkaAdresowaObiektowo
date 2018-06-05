#include <iostream>
#include <string>
#include "Uzytkownik.h"

using namespace std;

    void Uzytkownik::ustawLogin (string loginUzytkownika){
    login=loginUzytkownika;
    }
    void Uzytkownik::ustawHaslo (string hasloUzytkownika){
    haslo=hasloUzytkownika;
    }
    string Uzytkownik::zwrocLogin (){
    return login;
    }
    string Uzytkownik::zwrocHaslo (){
    return haslo;
    }
    Uzytkownik::Uzytkownik () {
    idUzytkownika=0;
    login="";
    haslo="";
    }
