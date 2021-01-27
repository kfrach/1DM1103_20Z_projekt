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

void poznaj_do_okola(int mapa[N][N], Pozycja *pozycja)
{
    int x = pozycja->x;
    int y = pozycja->y;
    int i = 1;

    
    explore("test");

    do
    {
       rotate_left("test");
    } while (strcmp(pozycja->kierunek,"W") == 0);

    do
    {
       move("test");
       explore("test");
    } while (mapa[x-1][y] == 2);

    rotate_right("test");
    explore("test");

    //int x0 = Pozycja.x;
    //int y0 = Pozycja.y;
   do{
         i++;
         if(strcmp(pozycja->kierunek,"N") == 0){
            if(mapa[x][y+1] == 2||mapa[x-1][y] == 2){
               rotate_right("test");
               explore("test");
            }else if(mapa[x][y+1] == 3||mapa[x-1][y] == 2){
               move("test");
               explore("test");
            }else if(mapa[x-1][y] == 3){
               rotate_left("test");
               explore("test");
            }else if(mapa[x][y+1] == 2||mapa[x-1][y] == 2||mapa[x+1][y] == 2){
               move("test");
               explore("test");
            }else if(mapa[x][y+1] == 3||mapa[x-1][y] == 2||mapa[x+1][y] == 2){
               rotate_right("test");
               explore("test");
            }
         }

         if(strcmp(pozycja->kierunek,"S") == 0){
            if(mapa[x][y-1] == 2||mapa[x+1][y] == 2){
               rotate_right("test");
               explore("test");
            }else if(mapa[x][y-1] == 3||mapa[x+1][y] == 2){
               move("test");
               explore("test");
            }else if(mapa[x+1][y] == 3){
               rotate_left("test");
               explore("test");
            }else if(mapa[x][y-1] == 2||mapa[x+1][y] == 2||mapa[x-1][y] == 2){
               move("test");
               explore("test");
            }else if(mapa[x][y-1] == 3||mapa[x+1][y] == 2||mapa[x-1][y] == 2){
               rotate_right("test");
               explore("test");
            }
         }

         if(strcmp(pozycja->kierunek,"W") == 0){
            if(mapa[x-1][y] == 2||mapa[x][y-1] == 2){
               rotate_right("test");
               explore("test");
            }else if(mapa[x-1][y] == 3||mapa[x][y-1] == 2){
               move("test");
               explore("test");
            }else if(mapa[x][y-1] == 3){
               rotate_left("test");
               explore("test");
            }else if(mapa[x][y-1] == 2||mapa[x-1][y] == 2||mapa[x][y+1] == 2){
               move("test");
               explore("test");
            }else if(mapa[x][y-1] == 2||mapa[x-1][y] == 2||mapa[x][y+1] == 2){
               rotate_right("test");
               explore("test");
            }
         }

         if(strcmp(pozycja->kierunek,"E") == 0){
            if(mapa[x+1][y] == 2||mapa[x][y+1] == 2){
               rotate_right("test");
               explore("test");
            }else if(mapa[x+1][y] == 3||mapa[x][y+1] == 2){
               move("test");
               explore("test");
            }else if(mapa[x][y+1] == 3){
               rotate_left("test");
               explore("test");
            }else if(mapa[x][y+1] == 2||mapa[x+1][y] == 2||mapa[x][y-1] == 2){
               move("test");
               explore("test");
            }else if(mapa[x][y+1] == 2||mapa[x+1][y] == 2||mapa[x][y-1] == 2){
               rotate_right("test");
               explore("test");
            }
         
      }while(i=100);

      

}