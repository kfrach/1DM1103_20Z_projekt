#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

typedef struct _Memory
{
    char *response;
    size_t size;
} Memory;

static size_t write_callback(void *data, size_t size, size_t nmemb, void *userp)
{
    /* to jest rzeczywista liczba bajtów przekazanych przez curl */
    size_t realsize = size * nmemb;

    /* jawnie konwertujemy (void*) na naszą strukturę, bo wiemy, że będziemy ją tutaj otrzymywać */
    Memory *mem = (Memory *) userp;

    char *ptr = NULL;

    /* Sprawdzamy czy pierwszy raz wywołujemy funkcję i trzeba zaalokować pamięć po raz pierwszy,
    czy trzeba zrobić reallokację (która kopiuje automatycznie starą zawartość w nowe miejsce) */
    if (mem->response != NULL)
        ptr = realloc(mem->response, mem->size + realsize + 1);
    else
        ptr = malloc(mem->size + realsize + 1);

    if (ptr == NULL)
        return 0; /* brak pamięci! */

    /* teraz zapamiętujemy nowy wskaźnik i doklejamy na końcu dane przekazane przez curl w 
       obszarze pamięci wskazywanym przez data */
    mem->response = ptr;
    memcpy(&(mem->response[mem->size]), data, realsize);
    mem->size += realsize;
    mem->response[mem->size] = 0; // to na końcu dodajemy bo to w końcu string, i zawsze powinien się skończyć!

    return realsize;
}

char * make_request(char *url)
{
    CURL *curl;
    CURLcode res;
    Memory chunk;
    chunk.size = 0;
    chunk.response = NULL;
    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_HEADER, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);        
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

        res = curl_easy_perform(curl);
       
        if (res != CURLE_OK)
            fprintf(stderr, "Błąd! curl_easy_perform() niepowodzenie: %s\n", curl_easy_strerror(res));
        else
        {
            printf("%s", chunk.response);        
        }

        
        free(chunk.response);
        curl_easy_cleanup(curl);
    }        
}

int move(char *token)
{
    make_request("http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/move/qwerty_23");
    return 0;
}

int rotate_left(char *token)
{
    make_request("http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/rotate/qwerty_23/left");
    return 0;
}

int rotate_right(char *token)
{
    make_request("http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/rotate/qwerty_23/right");
    return 0;
}

int explore(char *token)
{
    make_request("http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/explore/qwerty_23");
    return 0;
}

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