#include <iostream>
#include <string>

using namespace std;

class Uzytkownik {
private:
    int idUzytkownika;
    string login;
    string haslo;
public:
    void ustawLogin (string loginUzytkownika);
    void ustawHaslo (string hasloUzytkownika);
    string zwrocLogin ();
    string zwrocHaslo ();
    Uzytkownik ();
};
