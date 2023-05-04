// programming
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include "libweb.a"

#define PORT 18000
#define SA struct sockaddr*
#define BUFFER_MAX_SIZE_IN 4096

char* webPageLoader(FILE*);

int main(int argc, char* argv[])
{
	int server_fd, new_socket, valread, valwrite;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	char buffer_in_get[BUFFER_MAX_SIZE_IN] = { 0 };
	char buffer_final[BUFFER_MAX_SIZE_IN];

	
	//load the web page
	FILE* file = fopen("login.html", "r");

	// returns a heap allocated buffer so please free it the escape memory leaks
	char* bufferpage = webPageLoader(file);

	sprintf(buffer_final,HEADER_W_CONTENT,strlen(bufferpage),bufferpage);
	printf("\n%s",buffer_final);
	
	server_fd = socket(AF_INET, SOCK_STREAM, 0);
;
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	bind(server_fd, (SA)&address, sizeof(address));

	listen(server_fd, 1);
	for(;;)
	{

		memset(buffer_in_get,0,BUFFER_MAX_SIZE_IN);
		
		new_socket = accept(server_fd, NULL, NULL);

		// get the request from the client 
		valread = read(new_socket, buffer_in_get, BUFFER_MAX_SIZE_IN);

		fprintf(stdout,"\n%s\n",buffer_in_get);

		// Send the web page to the user 
		valwrite = write(new_socket, buffer_final,strlen(buffer_final));

		close(new_socket);
	}
	shutdown(server_fd, SHUT_RDWR);

	free(bufferpage);
	return 0;
}

char* webPageLoader(FILE* file)
{
	if(file==0) return 1;
	fseek(file,0,SEEK_END);
	int length = ftell(file);
	fseek(file, 0, SEEK_SET);

	char* buffer = (char*)malloc(sizeof(char)*(length));

	char c;
	int i =0;
	while((c=fgetc(file))!= EOF)
	{
		buffer[i]=c;
		i++; 
	}
	fclose(file);
	printf("%s",buffer);
	return buffer;
}