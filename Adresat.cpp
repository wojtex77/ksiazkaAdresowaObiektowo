#include <iostream>
#include "Adresat.h"

using namespace std;

void Adresat::ustawId(int id){
    idAdresata=id;
}
int Adresat::zwrocId(){
    return idAdresata;
}
void Adresat::ustawImie(string imie){
    imieAdresata=imie;
}
string Adresat::zwrocImie(){
    return imieAdresata;
}
void Adresat::ustawNazwisko(string nazwisko){
    nazwiskoAdresata=nazwisko;
}
string Adresat::zwrocNazwisko(){
    return nazwiskoAdresata;
}

void Adresat::ustawNumerTelefonu (string numer){
    numerTelefonu=numer;
}
string Adresat::zwrocNumerTelefonu(){
    return numerTelefonu;
}

void Adresat::ustawEmail(string email){
    emailAdresata=email;
}
string Adresat::zwrocEmail(){
    return emailAdresata;
}

void Adresat::ustawAdres (string adres){
    adresAdresata=adres;
}
string Adresat::zwrocAdres(){
    return adresAdresata;
}

Adresat::Adresat(){
    idAdresata=0;
    imieAdresata="";
    nazwiskoAdresata="";
    numerTelefonu="";
    emailAdresata="";
    adresAdresata="";
}
