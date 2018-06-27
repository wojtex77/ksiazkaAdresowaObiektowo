#include "PlikAdresatow.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>  // for string streams
#include <windows.h>


using namespace std;


string PlikAdresatow::konwertujIntNaString (int liczba){
    ostringstream str1;
    str1 << liczba;
    string liczbaStringiem = str1.str();
    return liczbaStringiem;
}

string PlikAdresatow::scalAdresataDoLinii(Adresat &adresat, int idZalogowanegoUzytkownika){
    string linia;
    string idAdresataStringiem=konwertujIntNaString(adresat.zwrocId());
    string idUzytkownikaStringiem=konwertujIntNaString(idZalogowanegoUzytkownika);
    return linia=idAdresataStringiem+"|"+idUzytkownikaStringiem+"|"+adresat.zwrocImie()+"|"+adresat.zwrocNazwisko()+"|"+adresat.zwrocNumerTelefonu()+"|"+adresat.zwrocEmail()+"|"+adresat.zwrocAdres()+"|";
}

void PlikAdresatow::podmienWpis (Adresat zedytowanyAdresat) {
    Adresat tymczasowyAdresat;
    string liniaTymczasowa, liniaGlowna;
    fstream tymczasowy, glowny;
    int idZGlownego, j=1;
    tymczasowy.open("temp.txt", fstream::app);
    glowny.open("kontakty.txt", fstream::in);

    if ((tymczasowy.good() == true)&&(glowny.good()==true)) {}

    do {
        getline(glowny,liniaGlowna);
        if (j!=1) tymczasowy<<endl;
        idZGlownego=wczytajIdZLiniiPliku(liniaGlowna);
        if (idZGlownego==zedytowanyAdresat.zwrocId()) {
            int idUzytkownikaZPliku=wczytajIdUzytkownikaZLiniiPliku(liniaGlowna);
            tymczasowy<<scalAdresataDoLinii(zedytowanyAdresat, idUzytkownikaZPliku);
        } else tymczasowy<<liniaGlowna;
        j++;
    } while (!glowny.eof());
    tymczasowy.close();
    glowny.close();
    tymczasowy.clear();
    glowny.clear();

    remove("kontakty.txt");
    rename("temp.txt","kontakty.txt");
}

void PlikAdresatow::usunWpis(int idKontaktu){
    Adresat tymczasowyAdresat;
    string liniaTymczasowa, liniaGlowna;
    fstream tymczasowy, glowny;
    int idZGlownego, j=1;
    tymczasowy.open("temp.txt", fstream::app);
    glowny.open("kontakty.txt", fstream::in);

    if ((tymczasowy.good() == true)&&(glowny.good()==true)) {}

    do {
        getline(glowny,liniaGlowna);
        idZGlownego=wczytajIdZLiniiPliku(liniaGlowna);
        if ((j!=1)&&(idZGlownego!=idKontaktu)) tymczasowy<<endl;
        if (idZGlownego==idKontaktu);
        else tymczasowy<<liniaGlowna;
        j++;
    } while (!glowny.eof());
    tymczasowy.close();
    glowny.close();
    tymczasowy.clear();
    glowny.clear();

    remove("kontakty.txt");
    rename("temp.txt","kontakty.txt");

}

int PlikAdresatow::zwrocNajwyzszeIdZPliku (){
    string linia;
    fstream plik;
    int idKontaktuBiezace=0;
    int idKontaktuNajwyzsze=0;
    plik.open("kontakty.txt",ios::in);
    if (plik.good() == true)
    {
        do {
            getline(plik,linia);
            if (linia.empty());
            else idKontaktuBiezace=wczytajIdZLiniiPliku(linia);
            if (idKontaktuBiezace>idKontaktuNajwyzsze) idKontaktuNajwyzsze=idKontaktuBiezace;
        }
        while (!plik.eof());
        plik.close();
        plik.clear();
    }
    return idKontaktuNajwyzsze;
}

int PlikAdresatow::wczytajIdZLiniiPliku (string linia){
    int i=0;
    string id;
    vector <int> pozycjeKoncaCechy;
    int idKontaktu;
    int dlugoscLinii = linia.length();
    while (i<dlugoscLinii) {
        char znak=linia[i];
        if (znak=='|')
            pozycjeKoncaCechy.push_back(i);
        i++;
    }
    idKontaktu=(konwertujNaInt(linia.substr(0,pozycjeKoncaCechy[0])));
    return idKontaktu;
}

int PlikAdresatow::wczytajIdUzytkownikaZLiniiPliku (string linia){
    int i=0, dlugoscIDUzytkownika=0;
    string id;
    vector <int> pozycjeKoncaCechy;
    int idKontaktu;
    int dlugoscLinii = linia.length();
    while (i<dlugoscLinii) {
        char znak=linia[i];
        if (znak=='|')
            pozycjeKoncaCechy.push_back(i);
        i++;
    }
    idKontaktu=(konwertujNaInt(linia.substr(0,pozycjeKoncaCechy[0])));

    dlugoscIDUzytkownika=pozycjeKoncaCechy[1]-pozycjeKoncaCechy[0]-1;
    return konwertujNaInt(linia.substr(pozycjeKoncaCechy[0]+1,dlugoscIDUzytkownika));
}

int PlikAdresatow::konwertujNaInt (string liczbaStringiem) {
    int liczba = atoi(liczbaStringiem.c_str());
    return liczba;
}

void PlikAdresatow::dopiszDoPliku (Adresat nowyAdresat, int IdUzytkownika){
    int i=0;
    fstream plik;
    plik.open("kontakty.txt",ios::app);
    if (plik.good() == true) {
        plik.seekg(0, ios::end);
        if (plik.tellg() != 0) {
            plik << endl;
        }
        string linia=scalAdresataDoLinii(nowyAdresat, IdUzytkownika);
        plik<<linia;
        i++;
    } else cout << "wystapil problem z plikiem";
    plik.close();
    plik.clear();
}

void PlikAdresatow::wczytajZPliku(vector <Adresat> &wczytaniAdresaci, int idUzytkownika){
    string linia;
    fstream plik;
    plik.open("kontakty.txt",ios::in);
    if (plik.good() == true)
    {
        do {
            getline(plik,linia);
            if (linia.empty());
            else rozdzielLinieNaCechy(wczytaniAdresaci, linia, idUzytkownika);
        }
        while (!plik.eof());
        plik.close();
        plik.clear();
    }
}

void PlikAdresatow::rozdzielLinieNaCechy (vector <Adresat> &wczytaniAdresaci, string linia, int idUzytkownika){
    int i=0,dlugoscIDUzytkownika, dlugoscImie, dlugoscNazwisko, dlugoscTelefon, dlugoscEmail, dlugoscAdres;
    string id,imie,nazwisko,telefon,email,adres;
    vector <int> pozycjeKoncaCechy;
    Adresat pojedynczyAdresat;
    int dlugoscLinii = linia.length();
    while (i<dlugoscLinii) {
        char znak=linia[i];
        if (znak=='|')
            pozycjeKoncaCechy.push_back(i);
        i++;
    }
    pojedynczyAdresat.ustawId(konwertujNaInt(linia.substr(0,pozycjeKoncaCechy[0])));

    dlugoscIDUzytkownika=pozycjeKoncaCechy[1]-pozycjeKoncaCechy[0]-1;
    pojedynczyAdresat.ustawIdUzytkownika(konwertujNaInt(linia.substr(pozycjeKoncaCechy[0]+1,dlugoscIDUzytkownika)));

    dlugoscImie=pozycjeKoncaCechy[2]-pozycjeKoncaCechy[1]-1;
    pojedynczyAdresat.ustawImie(linia.substr(pozycjeKoncaCechy[1]+1,dlugoscImie));

    dlugoscNazwisko=pozycjeKoncaCechy[3]-pozycjeKoncaCechy[2]-1;
    pojedynczyAdresat.ustawNazwisko(linia.substr(pozycjeKoncaCechy[2]+1,dlugoscNazwisko));

    dlugoscTelefon=pozycjeKoncaCechy[4]-pozycjeKoncaCechy[3]-1;
    pojedynczyAdresat.ustawNumerTelefonu(linia.substr(pozycjeKoncaCechy[3]+1,dlugoscTelefon));

    dlugoscEmail=pozycjeKoncaCechy[5]-pozycjeKoncaCechy[4]-1;
    pojedynczyAdresat.ustawEmail(linia.substr(pozycjeKoncaCechy[4]+1,dlugoscEmail));

    dlugoscAdres=pozycjeKoncaCechy[6]-pozycjeKoncaCechy[5]-1;
    pojedynczyAdresat.ustawAdres(linia.substr(pozycjeKoncaCechy[5]+1,dlugoscAdres));

    if (pojedynczyAdresat.zwrocIdUzytkownika()==idUzytkownika)  wczytaniAdresaci.push_back(pojedynczyAdresat);
}
