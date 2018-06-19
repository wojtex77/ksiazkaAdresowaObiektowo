using namespace std;

class Uzytkownik {
private:
    int idUzytkownika;
    string login;
    string haslo;
public:
    void ustawLogin (string loginUzytkownika);
    void ustawHaslo (string hasloUzytkownika);
    void ustawID (int id);
    string zwrocLogin ();
    string zwrocHaslo ();
    int zwrocID ();
    Uzytkownik ();
};
