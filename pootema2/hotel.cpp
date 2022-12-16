#include "hotel.h"
#include <iostream>
#include <stdio.h>

// initializare varibile statice
int Hotel::nr_hoteluri = 0;

// constructori
Hotel::Hotel(const std::string locatie, const int stele)
{
    m_locatie = locatie;
    m_stele = stele;
    nr_hoteluri++;
}
Hotel::Hotel(const Hotel &hotel)
{
    m_locatie = hotel.m_locatie;
    m_stele = hotel.m_stele;
    nr_hoteluri++;
}

// functii oarecare
void Hotel::afiseaza(void)
{
    std::cout << "locatie: " << m_locatie << '\n';
    std::cout << "stele: " << m_stele << '\n';
}

// functii statice
int Hotel::getSize(void)
{
    return nr_hoteluri;
}
// getters & setters
int Hotel::getStele(void)
{
    return m_stele;
}
void Hotel::setStele(const int stele)
{
    m_stele = stele;
}
std::string Hotel::getLocatie(void)
{
    return m_locatie;
}
void Hotel::setLocatie(const std::string locatie)
{
    m_locatie = locatie;
}

// operator=
Hotel& Hotel::operator=(Hotel const &hotel)
{
    m_locatie = hotel.m_locatie;
    m_stele = hotel.m_stele;
    nr_hoteluri++;
    return *this;
}
// operator>>
std::istream& operator>>(std::istream &is, Hotel &hotel)
{
    std::cout << "locatie: ";
    is >> hotel.m_locatie;
    std::cout << "stele: ";
    is >> hotel.m_stele;
    return is;
}
// operator<<
std::ostream& operator<<(std::ostream &os, const Hotel& hotel)
{
    os << "locatie: " << hotel.m_locatie << std::endl;
    os << "stele: " << hotel.m_stele << std::endl;
    return os;
}
// destructor
Hotel::~Hotel()
{
    nr_hoteluri--;
}