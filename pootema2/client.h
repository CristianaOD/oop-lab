#ifndef _CLIENT_H_
#define _CLIENT_H_
#include "hotel.h"

class Client : public Hotel {

private:
    std::string m_locatie;
    // variabila statica a clasei
    static int nr_client;
public:
    // constructori
    Client(const std::string nr_telefon = "", const int stele = 0, const std::string locatie = ""); // constructor parametrizat
    Client(const Client &client);                                                             // constructor de copiere
    // functii virtuale
    virtual void starea(void);

    // functii oarecare
    void afiseaza(void);

    friend std::istream& operator>>(std::istream &is, Client& client); // operator>>

    friend std::ostream& operator<<(std::ostream &os, const Client& client); // operator<<

    Client& operator=(const Client& client); // operator=

    // functie statica
    static int getSize(void);
    // Destructor
    ~Client();
};
#endif /* _CLIENT_H_ */
#ifndef TEMA2POO_CLIENT_H
#define TEMA2POO_CLIENT_H

#endif //TEMA2POO_CLIENT_H
