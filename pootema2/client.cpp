#include "client.h"
#include <iostream>

// initializare varibile statice
int Client::nr_client = 0;

Client::Client(const std::string nr_telefon, const int stele, const std::string locatie) : Hotel(locatie, stele)
{
    m_locatie = locatie;
    nr_client++;
}

Client::Client(const Client &client) : Hotel(client)
{
    m_locatie = client.m_locatie;
    nr_client++;
}

// destructor
Client::~Client()
{
    nr_client--;
}

//supraincarare operatori ; // apelaza operator= din clasa de baza
Client& Client::operator=(const Client& client)
{
    Hotel::operator=(client);
    m_locatie = client.m_locatie;
    nr_client++;
    return *this;
}
// operator>>
std::istream& operator>>(std::istream &is, Client& client)
{
    is >> static_cast<Hotel&>(client);
    std::cout << "Locatie: ";
    is >> client.m_locatie;
    return is;
}
// operator <<
std::ostream& operator<<(std::ostream &os, const Client& client)
{
    os << "---\nClient\n";
    os << static_cast<const Hotel&>(client);
    os << "Locatie : " << client.m_locatie << "\n";
    return os;
}
// functie virtuale pure implementate in clasa derivata
void Client::starea(void)
{
    std::cout << "Voi fi cazat intr-un hotel\n";
}

// functii oarecare
void Client::afiseaza(void)
{
    std::cout << "Sunt un client!\n";
    Hotel::afiseaza();
    std::cout << "Locatie: " << m_locatie << '\n';
}

// functii statice
int Client::getSize(void)
{
    return nr_client;
}



