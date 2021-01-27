#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#include "communication.h"
#include "movement.h"
#include "mapping.h"



void tablica(int mapa[N][N])
{
    int x ,y;
    char type[10];
    char bufor[255];
    char *b;
    FILE *pt;
    pt = fopen("info.txt","r");    
    while(fgets(bufor, 254, pt))
    {
    b = strtok(bufor," ");
    x = atoi(b);
    b = strtok(NULL," ");
    y = atoi(b);    
    b = strtok(NULL,"\n");
    strcpy(type,b);    
    if(strcmp(type,"wall") == 0)
    mapa[x][y] = 2;
    else if (strcmp(type,"grass") == 0)
    mapa[x][y] = 1;
    else if (strcmp(type,"sand") == 0)
    mapa[x][y] = 3;     
    }
    
    fclose(pt);
}


int wczytaj_pozycje(int i){
    

    int x ,y,z;
    char type[10];
    char bufor[255];
    char *b;
    FILE *pt;
    pt = fopen("pozycja.txt","r");    
    while(fgets(bufor, 254, pt))
    {
    b = strtok(bufor," ");
    x = atoi(b);
    b = strtok(NULL," ");
    y = atoi(b);    
    b = strtok(NULL,"\n");
    z = atoi(b);
    }
    if(i=1)
    {
    return x;  
    }else if(i=2)
    {
    return y;  
    }else if(i=3)
    {
    return z;  
    }
    }



void wypisz_mape(int mapa[N][N])
{
    int i,j;    
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if (j == N-1)
            printf("%d\n",mapa[i][j]);
            else
            printf("%d",mapa[i][j]);
        }
    }
}

void zapisz_mape(int mapa[N][N])
{
    int i,j;

    FILE * fin = fopen("mapa.txt", "w");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(j==N-1)
            fprintf(fin,"%d\n",mapa[i][j]);
            else
            fprintf(fin,"%d",mapa[i][j]);
        
            
            
        }
    }
    fclose(fin);
}
