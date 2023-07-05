#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 6540
#define SA struct sockaddr*
#define BUFFERMAX 1024


int main(int argc, char* argv[])
{
	int server_fd, new_socket, valread, valwrite;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	char buffer[BUFFERMAX];
	char bufferMessage[BUFFERMAX];

	server_fd = socket(AF_INET, SOCK_STREAM, 0);

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	bind(server_fd, (SA)&address, sizeof(address));

	listen(server_fd, 5);

	new_socket = accept(server_fd,NULL, NULL);

	valread = read(new_socket, buffer, BUFFERMAX);

	printf("%s\n",buffer);

	valwrite = write(new_socket, bufferMessage,strlen(bufferMessage));

	printf("%s\n",bufferMessage);

	close(new_socket);

	shutdown(server_fd, SHUT_RDWR);

	return 0;
}
