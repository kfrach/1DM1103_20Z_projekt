#ifndef _ALGORYTM_H
#define _ALGORYTM_H

#include "communication.h"
#include "movement.h"
#include "mapping.h"


typedef struct _Pozycja
{
    int x;
    int y;
    char *kierunek;
}Pozycja;


void poznaj_do_okoła(int mapa[N][N], Pozycja x, Pozycja y, Pozycja *kierunek);

#endif