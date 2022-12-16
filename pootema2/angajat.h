#ifndef _ANGAJAT_H_
#define _ANGAJAT_H_

#include "hotel.h"

class Angajat : public Hotel {

private:
    std::string m_locatie;
    // variabile statice
    static int nr_angajati;
public:
    // constructori
    Angajat(const std::string nr_telefon = "", const int stele = 0, const std::string locatie = ""); // constructor parametrizat
    Angajat(const Angajat& angajat);                                                          // constructor de copiere

    virtual void starea(void);  // functii virtuale pure din clasa de baza

    void afiseaza(void);  // functii oarecare

    static int getSize(void); // functii statice

    friend std::istream& operator>>(std::istream &is, Angajat& angajat); // operator>>

    friend std::ostream& operator<<(std::ostream &os, const Angajat& angajat); // operator<<

    Angajat& operator=(const Angajat& angajat);  // operator=

    // Destructor
    ~Angajat();
};
#endif /* _ANGAJAT_H */
#ifndef TEMA2POO_ANGAJAT_H
#define TEMA2POO_ANGAJAT_H

#endif //TEMA2POO_ANGAJAT_H
