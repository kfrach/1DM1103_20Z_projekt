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
    int x = wczytaj_pozycje(1);
    int y = wczytaj_pozycje(2);
    int zwrot = wczytaj_pozycje(3);
    int i = 1;

    
    explore("test");

    do
    {
       rotate_left("test");
       zwrot = wczytaj_pozycje(3);
    } while (zwrot = 4);

    do
    {
       move("test");
       explore("test");
       x = wczytaj_pozycje(1);
       y = wczytaj_pozycje(2);
       zwrot = wczytaj_pozycje(3);
    } while (mapa[x-1][y] == 2);

    rotate_right("test");
    explore("test");

    int x_zerowa = wczytaj_pozycje(1);
    int y_zerowa = wczytaj_pozycje(2);
    int zwrot = wczytaj_pozycje(3);

   do{
         i++;
         if(zwrot = 8){
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

         if(zwrot = 2){
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

         if(zwrot = 4){
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

         if(zwrot = 6){
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
         }
         
      }while((x = x_zerowa)||(y = y_zerowa - 1));

}