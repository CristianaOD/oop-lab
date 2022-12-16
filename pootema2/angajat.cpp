#include "angajat.h"
#include <iostream>

// initializare varibile statice
int Angajat::nr_angajati = 0;

Angajat::Angajat(const std::string nr_telefon, const int stele, const std::string locatie) : Hotel(nr_telefon, stele)
{
    m_locatie = locatie;
    nr_angajati++;
}

Angajat::Angajat(const Angajat& Angajat) : Hotel(Angajat)
{
    m_locatie = Angajat.m_locatie;
    nr_angajati++;
}

// functie virtuala pura apelata de clasa derivata
void Angajat::starea(void)
{
    std::cout << "Lucrez in cadrul unui hotel\n";
}

// operatorul= ; apelez operatorul= din clasa de baza
Angajat& Angajat::operator=(const Angajat& angajat)
{
    Hotel::operator=(angajat);
    //pentru campurile proprii
    m_locatie = angajat.m_locatie;
    nr_angajati++;
    return *this;
}
// operatorul>> ; folosesc operatorul>> din clasa de baza
std::istream& operator>>(std::istream &is, Angajat& angajat)
{
    std::cout << "Introduceti datele despre angajat:\n";
    is >> static_cast<Angajat&>(angajat);

    std::cout << "Locatie : ";
    is >> angajat.m_locatie;
    return is;
}
// operator<<  ; folosesc operator<< din clasa de baza
std::ostream& operator<<(std::ostream &os, const Angajat& angajat)
{
    os << "------\nAngajat\n";
    os << static_cast<const Angajat&>(angajat);
    os << "Locatie: " << angajat.m_locatie << "\n";;
    return os;
}
// functii oarecare ; apelez functia de afisare din clasa de baza
void Angajat::afiseaza(void)
{
    std::cout << "Angajat \n";
    Hotel::afiseaza();
    std::cout << "Locatie : " << m_locatie << "\n";
}
// functii statice
int Angajat::getSize(void)
{
    return nr_angajati;
}
// destructor
Angajat::~Angajat()
{
    nr_angajati--;
}

