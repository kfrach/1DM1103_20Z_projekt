#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "../cJSON/cJSON.h"


#include "communication.h"
#include "movement.h"


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
    FILE *pt;
    pt = fopen("info.txt","a");
    CURLcode res;
    Memory chunk;
    chunk.size = 0;
    chunk.response = NULL;
    curl = curl_easy_init();    
    
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        //curl_easy_setopt(curl, CURLOPT_HEADER, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);        
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

        res = curl_easy_perform(curl);
       
        if (res != CURLE_OK)
            fprintf(stderr, "Błąd! curl_easy_perform() niepowodzenie: %s :(\n", curl_easy_strerror(res));
        else
        {
            printf("%s", chunk.response);
            if(strcmp(url,"http://edi.iem.pw.edu.pl:30000/worlds/api/v1/worlds/explore/qwerty_23") == 0) 
            {            
            const cJSON *pole = NULL;            
            const cJSON *payload = NULL;
            const cJSON *stat = NULL; 
            const cJSON *list = NULL;
            cJSON *ruch = NULL;                
            int status = 0;            
            cJSON *monitor_json = cJSON_Parse(chunk.response);            
            if (monitor_json == NULL)
            {
            const char *error_ptr = cJSON_GetErrorPtr();
            if (error_ptr != NULL)
            {
            fprintf(stderr, "Error before: %s\n", error_ptr);
            }
            status = 0;            
            }        
            stat = cJSON_GetObjectItemCaseSensitive(monitor_json, "status");
            if (cJSON_IsString(stat) && (stat->valuestring != NULL))
                {
                printf("Checking monitor \"%s\"\n", stat->valuestring);
                }  

            payload = cJSON_GetObjectItemCaseSensitive(monitor_json, "payload");
            list = cJSON_GetObjectItemCaseSensitive(payload, "list");
            cJSON_ArrayForEach(ruch,list)
            {                                    
            cJSON  *x = cJSON_GetObjectItemCaseSensitive(ruch, "x");            
            cJSON  *y = cJSON_GetObjectItemCaseSensitive(ruch, "y");            
            cJSON  *type = cJSON_GetObjectItemCaseSensitive(ruch, "type");
            printf("field type : %s\n",type->valuestring);
            printf("x :%d || y: %d \n",x->valueint, y->valueint);
            fprintf(pt,"%d %d %s\n",x->valueint,y->valueint,type->valuestring);
            }          
            free(chunk.response);
            curl_easy_cleanup(curl);
            }


            else
            {          
            const cJSON *pole = NULL;            
            const cJSON *payload = NULL;
            const cJSON *stat = NULL;            
            int status = 0;            
            cJSON *monitor_json = cJSON_Parse(chunk.response);            
            if (monitor_json == NULL)
            {
            const char *error_ptr = cJSON_GetErrorPtr();
            if (error_ptr != NULL)
            {
            fprintf(stderr, "Error before: %s\n", error_ptr);
            }
            status = 0;            
            }        
            stat = cJSON_GetObjectItemCaseSensitive(monitor_json, "status");
            if (cJSON_IsString(stat) && (stat->valuestring != NULL))
                {
                printf("Checking monitor \"%s\"\n", stat->valuestring);
                }  

            payload =  cJSON_GetObjectItemCaseSensitive(monitor_json, "payload");                                        
            cJSON  *x1 = cJSON_GetObjectItemCaseSensitive(payload, "current_x");            
            cJSON  *y1 = cJSON_GetObjectItemCaseSensitive(payload, "current_y");            
            cJSON  *type = cJSON_GetObjectItemCaseSensitive(payload, "field_type");
            cJSON  *kierunekk = cJSON_GetObjectItemCaseSensitive(payload, "direction");             
            printf("field type : %s\n",type->valuestring);
            printf("x :%d || y: %d \n",x1->valueint, y1->valueint);
            fprintf(pt,"%d %d %s\n",x1->valueint,y1->valueint,type->valuestring);                  
            free(chunk.response);
            curl_easy_cleanup(curl);
            }
        }
    }
    fclose(pt);
}