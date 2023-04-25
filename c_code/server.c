// Server side C/C++ program to demonstrate Socket
// programming
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/types.h>
#include "pemasheader.h"

#define PORT 8080
int main(int argc, char const* argv[])
{
	int server_fd, new_socket, valread;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	char buffer[1024] = { 0 };
	char* hello = "Hello from server";

	// Creating socket file descriptor
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("socket failed");
		exit(EXIT_FAILURE);
	}

	// Forcefully attaching socket to the port 8080
	if (setsockopt(server_fd, SOL_SOCKET,
				SO_REUSEADDR | SO_REUSEPORT, &opt,
				sizeof(opt))) {
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	// Forcefully attaching socket to the port 8080
	if (bind(server_fd, (struct sockaddr*)&address,
			sizeof(address))
		< 0) {
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	if (listen(server_fd, 3) < 0) {
		perror("listen");
		exit(EXIT_FAILURE);
	}
	if ((new_socket
		= accept(server_fd, (struct sockaddr*)&address,(socklen_t*)&addrlen))
		< 0) {
		perror("accept");
		exit(EXIT_FAILURE);
	}
	valread = read(new_socket, buffer, 1024);

 
    int len = strlen(buffer)+1;
    char* str = malloc(len*sizeof(char));
    strncpy(str,buffer,sizeof(buffer));
    printf("%s\nname : %s\n",str,buffer);
    char rev[strlen(str)];
    for(int i =strlen(str)-1,x=0;i>0,x<strlen(str);i--,x++)
    {
        rev[x] =str[i];
        printf("%c\n",str[i]);
    }
    printf("reverser : %s\n",rev);

	// send respond
	char notpalandromic[] = "String is Not palandromic.\0";
	char isPalandromic[] = "String is palandromic.\0";
    if(palandromic(buffer,rev)==0)
		send(new_socket, isPalandromic, strlen(isPalandromic), 0);
    else
		send(new_socket, notpalandromic, strlen(notpalandromic), 0);

	// closing the connected socket
	close(new_socket);
	// closing the listening socket
	shutdown(server_fd, SHUT_RDWR);

	return 0;
}


