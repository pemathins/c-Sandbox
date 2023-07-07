#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>

#define PORT 8466
#define SA struct sockaddr*
#define BUFFERMAX 1024

typedef struct quote
{
	char name[7];
	float open;
	float high;
	float low;
	float close;
	float vol;
	char time[16];
}quote;

class MqlConnection {
	char host[10];
	public:
	MqlConnection(std::string p_host, int p_port)
	{
		strcpy(host,p_host);
		if(strcmp(host,"localhost")==0)
		{
			host = INADDR_ANY;
			
		}
	}

	int server_fd, newSocket;	
	int valread, valwrite;
	struct sockaddr_in address;
	int opt = 0;
	int addrlen = sizeof(address);
	char buffer[BUFFERMAX];
	char bufferMessage[BUFFERMAX];

	server_fd = socket(AF_INET, SOCK_STREAM, opt);

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	bool socketConnected()
	{
		bind(server_fd, (SA)&address, sizeof(address));
		listen(server_fd, 4);
	}

	std::string socketRead()
	{
	}

	std::string socketRead()
	{
	}

	~MqlConnection()
	{
		close(newSocket);
		shutdown(server_fd,SHUT_RDWR);
	}
};
int main(int argc, char* argv[])
{
	MqlConnection sock{"localhost", PORT};
	if(sock.socketConnected())
	{

	}

	return 0;
}
