// programming
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include "ars.h"

#define HEADER_TCP "Content-Type: text/html; charset=utf-8\r\n\r\n"
int buFFLen;
#define HTML_SEND char* bufferLoader(FILE* file) { 	if(file==0) return 1;	fseek(file,0,SEEK_END);	int length = ftell(file);	seek(file, 0, SEEK_SET);char* bufferpage = (char*)malloc(sizeof(char)*(length));	char c;	int i =0;	while((c=fgetc(file))!= EOF)	{		bufferpage[i]=c;		i++; 	}	fclose(file);	printf("%s",bufferpage); buFFLen = strlen(bufferpage);	return bufferpage;}

#define PORT 18000


#define BUFFER_MAX_SIZE_IN 4096

char* bufferLoader(FILE*);

int main(int argc, char* argv[])
{
	int server_fd, new_socket, valread, valwrite;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	char buffer[BUFFER_MAX_SIZE_IN] = { 0 };
	char buffer_test[BUFFER_MAX_SIZE_IN];
	char user_Name[] = "<html><head><title>Login</title></head><body style=\"background-color: aquamarine;\"><h2>Login Form</h2>   <form id=\"login-form\"><div><label for=\"username\">Username:</label><input type=\"text\" id=\"username\" name=\"username\" required><label for=\"password\">Password:</label><input type=\"password\" id=""password""name=\"password\"required></div><div><input type=\"submit\" value=\"Login\"></div></form><div id=\"message\"></div></body></html>";

	sprintf(buffer_test,"HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: %d\r\n\r\n%s",strlen(user_Name),user_Name);
	printf("\n%s",buffer_test);
	//load the web page
	FILE* file = fopen("login.html", "r");

	char* bufferpage = bufferLoader(file);
	// 
	// fgets(pagebuffer, sizeof pagebuffer,file)

	// while(!feof(file))
	// {==0)
	// 	sscanf(pagebuffer,"\n",);
	// 	fgets(pagebuffer, sizeof pagebuffer,file);
	// }

	// fclose(file);;

	char* newBuffer = (char*)malloc(sizeof(char)*(2*BUFFER_MAX_SIZE_IN));

	// strcat(buffer_test,user_Name,);

	// Creating socket file descriptor
	server_fd = socket(AF_INET, SOCK_STREAM, 0);
;
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	bind(server_fd, (struct sockaddr*)&address,	sizeof(address));

	listen(server_fd, 1);

	new_socket = accept(server_fd, NULL, NULL);

	valread = read(new_socket, buffer, BUFFER_MAX_SIZE_IN);
	printf("\n%s",buffer_test);
	valwrite = write(new_socket, buffer_test,strlen(buffer_test));

	close(new_socket);

	shutdown(server_fd, SHUT_RDWR);
	free(bufferpage);
	return 0;
}

char* bufferLoader(FILE* file)
{
	if(file==0) return 1;
	fseek(file,0,SEEK_END);
	int length = ftell(file);
	fseek(file, 0, SEEK_SET);

	char* bufferpage = (char*)malloc(sizeof(char)*(length));

	char c;
	int i =0;
	while((c=fgetc(file))!= EOF)
	{
		bufferpage[i]=c;
		i++; 
	}
	fclose(file);
	printf("%s",bufferpage);
	return bufferpage;
}
