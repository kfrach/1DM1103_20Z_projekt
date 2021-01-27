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

void poznaj_do_okola(int mapa[N][N])
{
    int x = wczytaj_pozycje(1);
    int y = wczytaj_pozycje(2);
    int zwrot = wczytaj_pozycje(3);
    int i = 1;
    int nx;
    int ny;
    
    explore("test");
    tablica(mapa);
    

    while(zwrot !=4) 
    {
       rotate_left("test");       
       zwrot = wczytaj_pozycje(3);       
    } ;

   
    do
    {
       explore("test");
       tablica(mapa);
       move("test");
       
       x = wczytaj_pozycje(1);
       y = wczytaj_pozycje(2);
       zwrot = wczytaj_pozycje(3);
    }while (mapa[x-1][y] == 1 ||mapa[x-1][y] == 3) ;

    rotate_right("test");
    explore("test");

    int x_zerowa = wczytaj_pozycje(1);
    int y_zerowa = wczytaj_pozycje(2);
    zwrot = wczytaj_pozycje(3);


    for(int j =0; j<250; j++)
    {
       x = wczytaj_pozycje(1);
       y = wczytaj_pozycje(2);
       rotate_right("test");
       explore("test");
       move("test");
       explore("test");
       rotate_left("test");
       explore("test");
       move("test");
       explore("test");
       nx = wczytaj_pozycje(1);
       ny = wczytaj_pozycje(2);
       if(nx == x && ny == y)
       {
           rotate_left("test");
           rotate_left("test");
           rotate_left("test");
       }
   }
   
  /* do{
         i++;
         if(zwrot = 8){
            if(mapa[x][y+1] == 2 && mapa[x-1][y] == 2){
               rotate_right("test");
               explore("test");
               tablica(mapa);
               zwrot = wczytaj_pozycje(3);
            }else if(mapa[x][y+1] == 3 && mapa[x-1][y] == 2){
               move("test");
               x = wczytaj_pozycje(1);
               y = wczytaj_pozycje(2);
               explore("test");
               tablica(mapa);
            }else if(mapa[x-1][y] == 3){
               rotate_left("test");
               zwrot = wczytaj_pozycje(3);
               explore("test");
               tablica(mapa);
            }else if(mapa[x][y+1] == 2 && mapa[x-1][y] == 2 && mapa[x+1][y] == 2){
               move("test");
               x = wczytaj_pozycje(1);
               y = wczytaj_pozycje(2);
               explore("test");
               tablica(mapa);
            }else if(mapa[x][y+1] == 3  &&  mapa[x-1][y] == 2 && mapa[x+1][y] == 2){
               rotate_right("test");
               zwrot = wczytaj_pozycje(3);
               explore("test");
               tablica(mapa);
            }
         }

         if(zwrot = 2){
            if(mapa[x][y-1] == 2 && mapa[x+1][y] == 2){
               rotate_right("test");
               zwrot = wczytaj_pozycje(3);
               explore("test");
               tablica(mapa);
            }else if(mapa[x][y-1] == 3 && mapa[x+1][y] == 2){
               move("test");
               x = wczytaj_pozycje(1);
               y = wczytaj_pozycje(2);
               explore("test");
               tablica(mapa);
            }else if(mapa[x+1][y] == 3){
               rotate_left("test");
               zwrot = wczytaj_pozycje(3);
               explore("test");
               tablica(mapa);
            }else if(mapa[x][y-1] == 2 && mapa[x+1][y] == 2 && mapa[x-1][y] == 2){
               move("test");
               x = wczytaj_pozycje(1);
               y = wczytaj_pozycje(2);
               explore("test");
               tablica(mapa);
            }else if(mapa[x][y-1] == 3 && mapa[x+1][y] == 2 && mapa[x-1][y] == 2){
               rotate_right("test");
               explore("test");
               tablica(mapa);
            }
         }

         if(zwrot = 4){
            if(mapa[x-1][y] == 2 && mapa[x][y-1] == 2){
               rotate_right("test");
               zwrot = wczytaj_pozycje(3);
               explore("test");
               tablica(mapa);
            }else if(mapa[x-1][y] == 3 && mapa[x][y-1] == 2){
               move("test");
               x = wczytaj_pozycje(1);
               y = wczytaj_pozycje(2);
               explore("test");
               tablica(mapa);
            }else if(mapa[x][y-1] == 3){
               rotate_left("test");
               zwrot = wczytaj_pozycje(3);
               explore("test");
               tablica(mapa);
            }else if(mapa[x][y-1] == 2 && mapa[x-1][y] == 2 && mapa[x][y+1] == 2){
               move("test");
               x = wczytaj_pozycje(1);
               y = wczytaj_pozycje(2);
               explore("test");
               tablica(mapa);

            }else if(mapa[x][y-1] == 2 && mapa[x-1][y] == 2 && mapa[x][y+1] == 2){
               rotate_right("test");
               zwrot = wczytaj_pozycje(3);
               explore("test");
               tablica(mapa);

            }
         }

         if(zwrot = 6){
            if(mapa[x+1][y] == 2 && mapa[x][y+1] == 2){
               rotate_right("test");
               zwrot = wczytaj_pozycje(3);
               explore("test");
               tablica(mapa);

            }else if(mapa[x+1][y] == 3 && mapa[x][y+1] == 2){
               move("test");
               x = wczytaj_pozycje(1);
               y = wczytaj_pozycje(2);
               explore("test");
               tablica(mapa);

            }else if(mapa[x][y+1] == 3){
               rotate_left("test");
               explore("test");
               tablica(mapa);

            }else if(mapa[x][y+1] == 2 && mapa[x+1][y] == 2 && mapa[x][y-1] == 2){
               move("test");
               x = wczytaj_pozycje(1);
               y = wczytaj_pozycje(2);
               explore("test");
               tablica(mapa);

            }else if(mapa[x][y+1] == 2 && mapa[x+1][y] == 2 && mapa[x][y-1] == 2){
               rotate_right("test");
               zwrot = wczytaj_pozycje(3);
               explore("test");
               tablica(mapa);

            }
         }
         
      }while(i<10);
      
}


//(x = x_zerowa)&&(y = y_zerowa - 1)
*/
}
