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
        
         if(kierunek = "N"){
            if(mapa[x][y+1] = 2||mapa[x-1][y] = 2){
               rotate_right("test");
               explore("test");
            }else if(mapa[x][y+1] = 3||mapa[x-1][y] = 2){
               move("test");
               explore("test");
            }else if(mapa[x-1][y] = 3){
               rotate_left("test");
               explore("test");
            }else if(mapa[x][y+1] = 2||mapa[x-1][y] = 2||mapa[x+1][y] = 2){
               move("test");
               explore("test");
            }else if(mapa[x][y+1] = 3||mapa[x-1][y] = 2||mapa[x+1][y] = 2){
               rotate_right("test");
               explore("test");
            }
         }

         if(kierunek = "S"){
            if(mapa[x][y-1] = 2||mapa[x+1][y] = 2){
               rotate_right("test");
               explore("test");
            }else if(mapa[x][y-1] = 3||mapa[x+1][y] = 2){
               move("test");
               explore("test");
            }else if(mapa[x+1][y] = 3){
               rotate_left("test");
               explore("test");
            }else if(mapa[x][y-1] = 2||mapa[x+1][y] = 2||mapa[x-1][y] = 2){
               move("test");
               explore("test");
            }else if(mapa[x][y-1] = 3||mapa[x+1][y] = 2||mapa[x-1][y] = 2){
               rotate_right("test");
               explore("test");
            }
         }

         if(kierunek = "W"){
            if(mapa[x-1][y] = 2||mapa[x][y-1] = 2){
               rotate_right("test");
               explore("test");
            }else if(mapa[x-1][y] = 3||mapa[x][y-1] = 2){
               move("test");
               explore("test");
            }else if(mapa[x][y-1] = 3){
               rotate_left("test");
               explore("test");
            }else if(mapa[x][y-1] = 2||mapa[x-1][y] = 2||mapa[x][y+1] = 2){
               move("test");
               explore("test");
            }else if(mapa[x][y-1] = 2||mapa[x-1][y] = 2||mapa[x][y+1] = 2){
               rotate_right("test");
               explore("test");
            }
         }

         if(kierunek = "E"){
            if(mapa[x+1][y] = 2||mapa[x][y+1] = 2){
               rotate_right("test");
               explore("test");
            }else if(mapa[x+1][y] = 3||mapa[x][y+1] = 2){
               move("test");
               explore("test");
            }else if(mapa[x][y+1] = 3){
               rotate_left("test");
               explore("test");
            }else if(mapa[x][y+1] = 2||mapa[x+1][y] = 2||mapa[x][y-1] = 2){
               move("test");
               explore("test");
            }else if(mapa[x][y+1] = 2||mapa[x+1][y] = 2||mapa[x][y-1] = 2){
               rotate_right("test");
               explore("test");
            }
         }


    }while( x0=Pozycja.x || y0-1 = Pozycja.y);


    

}