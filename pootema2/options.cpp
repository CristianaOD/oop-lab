#include "options.h"
#include "hoteluri.h"
#include <iostream>

void Options::afisMenu(void)
{
    printf("Optiuni:\n"
           "1. afiseaza toate elementele din vector\n"
           "2. adauga obiecte in vector\n"
           "3. sterge obiect din vector dupa index\n"
           "4. cati clienti sunt in vector\n"
           "5. cati angajati sunt in vector\n"
           "6. modifica un element din vector dupa index\n"
           "7. clientul cu cele mai multe camere rezervate\n"
           "8. angajatul cu cele mai multe ore lucrate\n"
           "9. exit din program\n");
}

Options::Option Options::citesteOptiuni(void)
{
    int option = -1;
    while(option < 1 || option > Options::OP_NUM_OPTIONS)
    {
        printf("Optiunea aleasa este: ");
        std::cin >> option;
        if(option < 1 || option > Options::OP_NUM_OPTIONS)
        {
            std::cout << "Optiune gresita\n";
            afisMenu();
        }
    }
    return (Options::Option) (option-1);
}

void Options::adaugaObiect(std::vector<Hotel*>& vec_hotel)
{
    Hotel *hotel = Hoteluri::citesteHoteluri();
    vec_hotel.push_back(hotel);
}
void Options::stergeDupaIdx(std::vector<Hotel*>& vec_hotel)
{
    std::cout << "Index de sters: ";
    int index;
    std::cin >> index;
    if(index > vec_hotel.size()-1)
    {
        std::cout << "Indexul nu este in dimensiunea vectorului: " << vec_hotel.size() << "\n";
        return;
    }
    vec_hotel.erase(vec_hotel.begin() + index);
}
int Options::getNrClienti(std::vector<Hotel*>& vec_hotel)
{
    int nrClienti = 0;
    for(auto it = vec_hotel.begin(); it != vec_hotel.end(); it++)
    {
        if(dynamic_cast<Client*>(*it) != nullptr)
            nrClienti++;
    }
    return nrClienti;
}
int Options::getNrAngajati(std::vector<Hotel*>& vec_hotel)
{
    int nr_angajati = 0;
    for(auto it = vec_hotel.begin(); it != vec_hotel.end(); it++)
    {
        if(dynamic_cast<Angajat*>(*it) != nullptr)
            nr_angajati++;
    }
    return nr_angajati;
}

void Options::afiseazaToate(std::vector<Hotel*>& vec_hotel)
{
    Angajat *angajat;
    Client *client;
    for(auto it = vec_hotel.begin(); it != vec_hotel.end(); it++)
    {
        Hotel *hotel = *it;
        if((client = dynamic_cast<Client*>(hotel)) != nullptr)
        {
            std::cout << *client;
        }
        else if((angajat = dynamic_cast<Angajat*>(hotel))!= nullptr)
        {
            std::cout << *angajat;
        }
    }
}

void Options::modificaDupaIdx(std::vector<Hotel*>& vec_hotel)
{
    std::cout << "Unimplemented yet\n";
}

int Client_cmp(const void *a, const void *b)
{
    Client* client1 = ( Client*) a;
    Client* client2 = ( Client*) b;
    return client1->getStele() > client2->getStele();
}

void Client_Sortare(Client *client, int nr_client)
{
    std::cout << "Sortare clienti\n";
    qsort(client, nr_client, sizeof(Client), Client_cmp);
    std::cout << "terminare sortare\n";
}

void Options::ClientCameraStele(std::vector<Hotel*>& vec_hotel)
{
    Client *client = nullptr;
    int stele = 0;

    for(auto it = vec_hotel.begin(); it != vec_hotel.end(); it++)
    {
        Client *tmp;
        if((tmp = dynamic_cast<Client*>(*it)) != nullptr)
        {
            if(tmp->getStele() > stele)
            {
                stele = tmp->getStele();
                client = tmp;
            }
        }
    }
    if(client == nullptr)
        std::cout << "Nu exista client in vector\n";
    else{
        std::cout << "Clientul cu cele mai multe stele:\n";
        std::cout << *client;
    }
}
void Options::angajatStele(std::vector<Hotel*>& vec_hotel)
{
    Angajat *angajat = nullptr;
    int stele = 0;
    for(auto it = vec_hotel.begin(); it != vec_hotel.end(); it++)
    {
        Angajat *tmp;
        if((tmp = dynamic_cast<Angajat*>(*it)) != nullptr)
        {
            if(tmp->getStele() > stele)
            {
                stele = tmp->getStele();
                angajat = tmp;
            }
        }
    }
    if(angajat == nullptr)
        std::cout << "Nu exista angajatul in vector\n";
    else{
        std::cout << "Angajatul cu cele mai multe stele din vector:\n";
        std::cout << *angajat;
    }
}
bool Options::exitProgram(void)
{
    return false;
}

