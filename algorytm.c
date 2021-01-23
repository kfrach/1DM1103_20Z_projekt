#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "../cJSON/cJSON.h"
#include "communication.h"
#include "movement.h"
#include "mapping.h"
#include "algorytm.h"


//wall = 2
//grass = 3
//sand = 1

void poznaj_do_okoła(int mapa[N][N], Pozycja x, Pozycja y, Pozycja *kierunek){


    int x,y;
    int x = 1;
    int y = 2;
    //int x = Pozycja->x;
    //int y = Pozycja.y;

    
    explore("test");

    do
    {
       rotate_left("test");
    } while (kierunek=!"W");

    do
    {
       move("test");
       explore("test");
    } while (mapa[x-1][y] = 2);

    rotate_right("test");
    explore("test");

    //int x0 = Pozycja.x;
    //int y0 = Pozycja.y;

    do {
        
    }while( x0=Pozycja.x || y0-1 = Pozycja.y);


    

}