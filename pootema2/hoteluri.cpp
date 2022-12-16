#include "hoteluri.h"
#include "hotel.h"
#include "client.h"
#include "angajat.h"
#include <iostream>

Hotel* Hoteluri::citesteHoteluri(void)
{
    HoteluriEnum option = NONE;
    Hotel *hotel = nullptr;
    while(option != CLIENT && option != ANGAJAT)
    {
        std::cout << "Optiunile sunt:\n";
        std::cout << "Client - 0\n";
        std::cout << "Angajat  - 1\n";
        std::cout << "Introduceti serviciul dorit: ";
        int tmpOption;
        std::cin >> tmpOption;
        if(tmpOption < 0 || tmpOption >= Hoteluri::NUM_ELEMS)
        {
            std::cout << "Optiune gresita\n";
        }
        else
        {
            option = (HoteluriEnum) tmpOption;
        }
    }
    switch(option)
    {
        case Hoteluri::CLIENT: {
            Client *tmpClient = new Client();
            std::cin >> *tmpClient;
            hotel = (Hotel*) tmpClient;
            break;
        }
        case Hoteluri::ANGAJAT: {
            Angajat *tmpAngajat = new Angajat();
            std::cin >> *tmpAngajat;
            hotel = (Hotel*) tmpAngajat;
            break;
        }
        default: {
            std::cout << "Nu ar trebui sa se ajunga aici decat daca am adaugat un animal in enum de care am uitat\n";
            break;
        }
    }
    return hotel;
}

