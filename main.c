#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h> 
#include <string.h>
#include <netdb.h>
#include <pthread.h>
#include "structs.h"
#include "management_service.h"
#include "discovery_service.h"

int main(int argc, char *argv[]){
    int manager = 0;
    if(argc > 1 && strcmp(argv[1], "manager") == 0)
        manager = 1;

    if(manager){
        pthread_t discovery_thread;
        int rc = pthread_create(&discovery_thread, NULL, listen_discovery, NULL);
        if(rc){
            printf("Error creating listen_discovery thread\n");
        }
        printf("testando...\n");

        int ret_join = pthread_join(discovery_thread, NULL);
        if(ret_join){
           printf("Error joining thread\n");
        }

    }else{
        participant_start();
    }
    return 0;
}
