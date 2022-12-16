#include "angajat.h"
#include "client.h"
#include "hotel.h"
#include "hoteluri.h"
#include "options.h"
#include <iostream>
#include <vector>

int main()
{
    // instantiere client
    Client client = Client("0743950377", 4, "Hotel2");
    // instantiere angajat
    Angajat angajat = Angajat("0745671234", 3, "Hotel1");

    // declarare vector de 2 pointeri catre animal
    Hotel **hotel = new Hotel*[2];
    std::cout << "=========\n";
    std::cout << "Upcasting\n";
    std::cout << "=========\n";
    // upcasting - transform din ptr la ob din clasele derivate la ptr la obiect din clasa de baza
    hotel[0] = &client;
    hotel[1] = &angajat;

    // apelare functii virtuale prin pointeri catre clasa de baza
    for(int i = 0; i < 2; i++)
        hotel[i]->starea();
    std::cout << "===========\n";
    std::cout << "Downcasting\n";
    // downcasting - transform din pointer la clasa de baza in ob de tip clasa derivata
    Client client_din_hotel =  *((Client*) hotel[0]);
    Angajat angajat_din_hotel = *((Angajat*) hotel[1]);
    // verificare
    client_din_hotel.starea();
    angajat_din_hotel.starea();

    std::cout << "============\n";
    std::cout << "Dynamic cast\n";
    std::cout << "============\n";

    // dynamic cast
    for(int i = 0; i < 2; i++)
    {
        Angajat *tmpAngajat;
        Client *tmpClient;
        if((tmpAngajat = dynamic_cast<Angajat*>(hotel[i])) != nullptr)
        {
            printf("in hotelul[%d] se afla angajatul\n", i);
            tmpAngajat->starea();
        }
        else if((tmpClient = dynamic_cast<Client*>(hotel[i])) != nullptr)
        {
            printf("in hotelul[%d] este cazat clientul\n", i);
            tmpClient->starea();
        }
    }

    std::cout << "=====================================\n";
    std::cout << "constructor de copiere pentru obiecte\n";
    // constructor copiere
    Angajat a1 = Angajat(angajat);
    a1.starea();

    // tipuri de apel ale constructorului de copiere
    Client c1 = Client(client);
    c1.starea();
    Client c2 = client;
    c2.starea();
    Client c3(client);
    c3.starea();

    // ilustrare operator=
    Angajat angajat2 = Angajat("0754367769", 3, "Hotel2");
    Client client2  = Client("0756728902", 2, "Hotel3");
    std::cout << "========================\n";
    std::cout << "operatorul""=" "pentru obiecte\n";
    std::cout << "========================\n";
    a1 = angajat2;
    a1.afiseaza();
    c1 = client2;
    c1.afiseaza();

    // campuri si functii statice
    delete[] hotel;
    std::cout << "==========================\n";
    std::cout << "Campuri si functii statice\n";
    printf("In cadrul complexului de hoteluri sunt %d hoteluri dintre care %d clienti si %d angajati\n", Hotel::getSize(), Client::getSize(), Angajat::getSize());

    // STL citirea a n obiecte
    std::vector<Hotel*> vec_hotel;
    int nrObiecte;
    // citirea a n obiecte de tip animal diferite
    std::cout << "===========================================\n";
    std::cout << "citirea a n obiecte de tip hotel:\n";
    std::cout << "nrObiecte: ";
    std::cin >> nrObiecte;

    for(int i = 0; i < nrObiecte; i++)
    {
        Hotel *hotel = Hoteluri::citesteHoteluri(); // functie statica reutilizabila pt citirea unui hotel de la tastatura
        vec_hotel.push_back(hotel);
    }
    // afisarea celor n obiecte de tip pointeri catre clasa de baza
    std::cout << "=============================================================\n";
    std::cout << "afisarea celor " << nrObiecte <<" obiecte de tip pointeri catre clasa de baza\n";

    Options::afiseazaToate(vec_hotel);
    // meniu interactiv
    std::cout << "================\n";
    std::cout << "Meniu interactiv\n";

    bool running = true;
    while(running == true)
    {
        Options::afisMenu();
        Options::Option option = Options::citesteOptiuni();
        switch(option)
        {
            case Options::OP_AFISEAZA_TOATE:{
                Options::afiseazaToate(vec_hotel);
                break;
            }
            case Options::OP_ADAUGA_OBIECT: {
                Options::adaugaObiect(vec_hotel);
                break;
            }
            case Options::OP_STERGE_DUPA_IDX: {
                Options::stergeDupaIdx(vec_hotel);
                break;
            }
            case Options::OP_GET_NR_CLIENTI: {
                std::cout << "nr clienti: " << Options::getNrClienti(vec_hotel) << '\n';
                break;
            }
            case Options::OP_GET_NR_ANGAJATI: {
                std::cout << "nr angajati: " << Options::getNrAngajati(vec_hotel) << '\n';
                break;
            }
            case Options::OP_MODIFICA_DUPA_IDX: {
                Options::modificaDupaIdx(vec_hotel);
                break;
            }
            case Options::OP_CLIENT_CAMERA_STELE: {
                Options::ClientCameraStele(vec_hotel);
                break;
            }
            case Options::OP_ANGAJAT_STELE: {
                Options::angajatStele(vec_hotel);
                break;
            }
            case Options::OP_EXIT_PROGRAM: {
                running = Options::exitProgram();
                break;
            }
            default: {
                std::cout << ".\n";
                break;
            }
        }
    }
    return 0;
}