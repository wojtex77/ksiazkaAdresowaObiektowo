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

    void Uzytkownik::ustawID (int id){
    idUzytkownika=id;
    }

    string Uzytkownik::zwrocLogin (){
    return login;
    }
    string Uzytkownik::zwrocHaslo (){
    return haslo;
    }

    int Uzytkownik::zwrocID(){
    return idUzytkownika;
    } ;

    Uzytkownik::Uzytkownik () {
    idUzytkownika=0;
    login="";
    haslo="";
    }
