#ifndef _HOTEL_H_
#define _HOTEL_H_
#include <string>

class Hotel {

protected:
    std::string m_locatie;
    int m_stele;
    // variabile statice
    static int nr_hoteluri;

public:
    // constructori
    Hotel(const std::string locatie, const int stele); // constructor parametrizat
    Hotel(const Hotel &hotel);                     // constructor de copiere
    // functii oarecare
    void afiseaza(void);
    // functii statice
    static int getSize(void);
    // setters & getters
    int getStele(void);
    void setStele(const int varsta);
    std::string getLocatie(void);
    void setLocatie(const std::string locatie);
    // functii virtuale pure care fac clasa abstracta
    virtual void starea(void) = 0;
    // operator=
    Hotel& operator=(Hotel const &hotel);
    // operator>>
    friend std::istream& operator>>(std::istream &is, Hotel& hotel);
    // operator<<
    friend std::ostream& operator<<(std::ostream &os, const Hotel& hotel);
    // destructor
    ~Hotel();
};
#endif /* _HOTEL_H_ */

#ifndef TEMA2POO_HOTEL_H
#define TEMA2POO_HOTEL_H

#endif //TEMA2POO_HOTEL_H
