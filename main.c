#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "../cJSON/cJSON.h"
#include "communication.h"
#include "movement.h"
#include "mapping.h"


int main(int argc, char **argv, int mapa[N][N])
{
    //char token = "http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/explore/qwerty_23";
    for(int i = 0; i<argc; i++)    
    {
    if (strcmp(argv[i],"M") == 0)
    move("test");

    else if (strcmp(argv[i],"R") == 0)
    rotate_right("test");

    else if (strcmp(argv[i],"L") == 0)
    rotate_left("test");

    else if (strcmp(argv[i],"E") == 0)
    explore("test");
    }
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        mapa[i][j] = 0;
    }
            
    tablica(mapa);
    wypisz_mape(mapa);
    zapisz_mape(mapa);

    return 0;
}