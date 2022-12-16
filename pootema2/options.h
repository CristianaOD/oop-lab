#ifndef _OPTIONS_H_
#define _OPTIONS_H_
#include <vector>
#include "hotel.h"
#include "client.h"
#include "angajat.h"

class Options{

public:
    enum Option
    {
        OP_AFISEAZA_TOATE,
        OP_ADAUGA_OBIECT,
        OP_STERGE_DUPA_IDX,
        OP_GET_NR_CLIENTI,
        OP_GET_NR_ANGAJATI,
        OP_MODIFICA_DUPA_IDX,
        OP_CLIENT_CAMERA_STELE,
        OP_ANGAJAT_STELE,
        OP_EXIT_PROGRAM,
        OP_NUM_OPTIONS
    };
    static void afisMenu(void);
    static Options::Option citesteOptiuni(void);
    static void afiseazaToate(std::vector<Hotel*>& vec_hotel);
    static void adaugaObiect(std::vector<Hotel*>& vec_hotel);
    static void stergeDupaIdx(std::vector<Hotel*>& vec_hotel);
    static int getNrClienti(std::vector<Hotel*>& vec_hotel);
    static int getNrAngajati(std::vector<Hotel*>& vec_hotel);
    static void modificaDupaIdx(std::vector<Hotel*>& vec_hotel);
    static void ClientCameraStele(std::vector<Hotel*>& vec_hotel);
    static void angajatStele(std::vector<Hotel*>& vec_hotel);
    static bool exitProgram(void);
};
#endif /* _OPTIONS_H */

#ifndef TEMA2POO_OPTIONS_H
#define TEMA2POO_OPTIONS_H

#endif //TEMA2POO_OPTIONS_H
