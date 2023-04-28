// programming
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include "ars.h"
#include

#define PORT 8080

int main(int argc, char* argv[])
{
	int server_fd, new_socket, valread;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	char buffer[1024] = { 0 };
	char* user_Name = "";

	// Creating socket file descriptor
	server_fd = socket(AF_INET, SOCK_STREAM, 0);

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	bind(server_fd, (struct sockaddr*)&address,	sizeof(address));

	listen(server_fd, 3);

	new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen));

	valread = read(new_socket, buffer, 1024);

	
	LoginCheck(buffer);

	close(new_socket);

	shutdown(server_fd, SHUT_RDWR);

	return 0;
}
