using namespace std;

class Adresat {
private:
    int idAdresata, idUzytkownika;
    string imieAdresata, nazwiskoAdresata, numerTelefonu, emailAdresata, adresAdresata;
public:
    void ustawId (int Id);
    int zwrocId ();

    void ustawIdUzytkownika (int Id);
    int zwrocIdUzytkownika ();

    void ustawImie (string imie);
    string zwrocImie ();

    void ustawNazwisko (string nazwiskoAdresata);
    string zwrocNazwisko ();

    void ustawNumerTelefonu (string numer);
    string zwrocNumerTelefonu ();

    void ustawEmail (string email);
    string zwrocEmail ();

    void ustawAdres (string adres);
    string zwrocAdres ();

    Adresat ();
};
