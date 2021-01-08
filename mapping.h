#ifndef _MAPPING_H
#define _MAPPING_H

#include "communication.h"
#include "movement.h"

#define N 40


int mapa[N][N];



void wczytaj_mape(int mapa[N][N]);
void wypisz_mape(int mapa[N][N]);

void zmiana_znaku_move(int mapa[N][N], int x , int y, char *pozycja);
// int x - pozycja x-owa z jsona +20 zeby bylo na srodku
// int y - pozycja y-owa z jsona +20 zeby bylo na srodku
// char *pozycja - pozycja miejsce na jakim stoimi z jsona np. grass



void zmiana_znaku_explore(int mapa[N][N], int x , int y, char *pozycja_1, char *pozycja_2, char *pozycja_3 , char *kierunek);
// int x - pierwszy x z listy explore z jsona +20
// int y - pierwszy y z listy explore z jsona +20
// char *kierunek - z ostatniego jsona przy move musimy wziac kierunek w ktory patrzy np. N
// char *pozycja_1 , char *pozycja_2 , char *pozycja_3 - w kolejnosci widziane elementy z  jsona explore np. grass wall wall



#endif