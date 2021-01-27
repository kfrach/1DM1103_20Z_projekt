#ifndef _COMMUNICATION_H
#define _COMMUNICATION_H

#include "movement.h"

typedef struct _Memory
{
    char *response;
    size_t size;
} Memory;

typedef struct _Pozycja
{
    int x;
    int y;
    char *kierunek;
}Pozycja;





static size_t write_callback(void *data, size_t size, size_t nmemb, void *userp);
char * make_request(char *url);



#endif