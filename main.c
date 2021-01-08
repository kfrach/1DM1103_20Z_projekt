#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#include "communication.h"
#include "movement.h"


int main(int argc, char **argv)
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

    return 0;
}