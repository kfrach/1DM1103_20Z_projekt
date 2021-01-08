#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#include "communication.h"
#include "movement.h"
#include "mapping.h"



void wczytaj_mape(int mapa[N][N])
{
    int i,j,znak;

    FILE * fin = fopen("mapa.txt", "r");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            fscanf(fin,"%d", &znak);
            mapa[i][j] = znak;
        }
    }
    fclose(fin);
}

void wypisz_mape(int mapa[N][N])
{
    int i,j;

    FILE * fin = fopen("mapa.txt", "w");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            fprintf("&d",mapa[i][j]);
        }
    }
    fclose(fin);
}



void zmiana_znaku_move(int mapa[N][N], int x , int y, char *pozycja)
{
    
    if (strcmp(pozycja,"grass") == 0)
    mapa[x][y] = 1;

    else if (strcmp(pozycja,"sand") == 0)
    mapa[x][y] = 2;

}

void zmiana_znaku_explore(int mapa[N][N], int x , int y, char *pozycja_1, char *pozycja_2, char *pozycja_3 , char *kierunek)
{
    
    if(strcmp(kierunek,"N") == 0){
        if (strcmp(pozycja_1,"grass") == 0)
        mapa[x][y] = 1;

        else if (strcmp(pozycja_1,"sand") == 0)
        mapa[x][y] = 2;

        else if (strcmp(pozycja_1,"wall") == 0)
        mapa[x][y] = 3;

        if (strcmp(pozycja_2,"grass") == 0)
        mapa[x+1][y] = 1;

        else if (strcmp(pozycja_2,"sand") == 0)
        mapa[x+1][y] = 2;

        else if (strcmp(pozycja_2,"wall") == 0)
        mapa[x+1][y] = 3;

        if (strcmp(pozycja_3,"grass") == 0)
        mapa[x+2][y] = 1;

        else if (strcmp(pozycja_3,"sand") == 0)
        mapa[x+2][y] = 2;

        else if (strcmp(pozycja_3,"wall") == 0)
        mapa[x+2][y] = 3;

    } else if(strcmp(kierunek,"S") == 0){

            if (strcmp(pozycja_1,"grass") == 0)
            mapa[x][y] = 1;

            else if (strcmp(pozycja_1,"sand") == 0)
            mapa[x][y] = 2;

            else if (strcmp(pozycja_1,"wall") == 0)
            mapa[x][y] = 3;

            if (strcmp(pozycja_2,"grass") == 0)
            mapa[x-1][y] = 1;

            else if (strcmp(pozycja_2,"sand") == 0)
            mapa[x-1][y] = 2;

            else if (strcmp(pozycja_2,"wall") == 0)
            mapa[x-1][y] = 3;

            if (strcmp(pozycja_3,"grass") == 0)
            mapa[x-2][y] = 1;

            else if (strcmp(pozycja_3,"sand") == 0)
            mapa[x-2][y] = 2;

            else if (strcmp(pozycja_3,"wall") == 0)
            mapa[x-2][y] = 3;

    } else if(strcmp(kierunek,"W") == 0){

            if (strcmp(pozycja_1,"grass") == 0)
            mapa[x][y] = 1;

            else if (strcmp(pozycja_1,"sand") == 0)
            mapa[x][y] = 2;

            else if (strcmp(pozycja_1,"wall") == 0)
            mapa[x][y] = 3;

            if (strcmp(pozycja_2,"grass") == 0)
            mapa[x][y-1] = 1;

            else if (strcmp(pozycja_2,"sand") == 0)
            mapa[x][y-1] = 2;

            else if (strcmp(pozycja_2,"wall") == 0)
            mapa[x][y-1] = 3;

            if (strcmp(pozycja_3,"grass") == 0)
            mapa[x][y-2] = 1;

            else if (strcmp(pozycja_3,"sand") == 0)
            mapa[x][y-2] = 2;

            else if (strcmp(pozycja_3,"wall") == 0)
            mapa[x][y-2] = 3;

    } else if(strcmp(kierunek,"E") == 0){

            if (strcmp(pozycja_1,"grass") == 0)
            mapa[x][y] = 1;

            else if (strcmp(pozycja_1,"sand") == 0)
            mapa[x][y] = 2;

            else if (strcmp(pozycja_1,"wall") == 0)
            mapa[x][y] = 3;

            if (strcmp(pozycja_2,"grass") == 0)
            mapa[x][y+1] = 1;

            else if (strcmp(pozycja_2,"sand") == 0)
            mapa[x][y+1] = 2;

            else if (strcmp(pozycja_2,"wall") == 0)
            mapa[x][y+1] = 3;

            if (strcmp(pozycja_3,"grass") == 0)
            mapa[x][y+2] = 1;

            else if (strcmp(pozycja_3,"sand") == 0)
            mapa[x][y+2] = 2;

            else if (strcmp(pozycja_3,"wall") == 0)
            mapa[x][y+2] = 3;

    }

}
