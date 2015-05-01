#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <time.h>

#define GPU_LOG "gpu.txt"
#define PORT 8771

int main(int argc, char **argv){
    struct sockaddr_in serv_addr;
    int sock, sock2;
    char **recvbuf;
    char *n = "\n";
    FILE *f = NULL;

    // listener socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0){
        perror("socket failed!");
	close(sock);
	exit(1);
    }
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(PORT);

    if(bind(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
        perror("couldn't bind socket!");
	close(sock);
        exit(1);
    }
    if(listen(sock, 5) < 0){
        perror("couldn't setup listener socket!");
	close(sock);
	exit(1);
    }

    // record gpu
    while(1){
	sock2 = accept(sock, (struct sockaddr *)NULL, NULL);
	if(sock2 < 0){
	    perror("accept() socket failed!");
	    close(sock2);
	    exit(1);
	}
        if(recv(sock2, recvbuf, sizeof(recvbuf), 0) < 0){
	    printf("recv() failed! trying again...\n");
	} else{
	    printf("%s  |  Logged to gpu.txt\n", recvbuf);
	    f = fopen(GPU_LOG, "a");
	    fwrite(recvbuf, 1, sizeof(recvbuf), f);
	    fwrite(n, 1, sizeof(n), f);
	    fclose(f);
        }
    }
}
