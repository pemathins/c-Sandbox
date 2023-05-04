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
#define BUFFER_MAX_SIZE_IN 409600
#define GET "GET "
#define POST "POST"
#define ERR "X0"

typedef struct User
{
	int id;
	char name[35];
} User;

char* webPageLoader(FILE*);

char* request(char*);

int main(int argc, char* argv[])
{
	int server_fd, new_socket, valread, valwrite;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	char buffer_in_get[BUFFER_MAX_SIZE_IN] = { 0 };
	char buffer_final[BUFFER_MAX_SIZE_IN];
	char bufferTest[55];
	
	//load the web page
	FILE* authFile = fopen("./Login_Page/login.html", "r");
	FILE* loginDashboardFile = fopen("Dashboard.html", "r");

	// returns a heap allocated buffer so please free it the escape memory leaks
	char* bufferpage = webPageLoader(authFile);

	sprintf(buffer_final,HEADER_W_CONTENT,strlen(bufferpage),bufferpage);
	printf("\n%s",buffer_final);
	
	server_fd = socket(AF_INET, SOCK_STREAM, 0);
;
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	bind(server_fd, (SA)&address, sizeof(address));

	listen(server_fd, 1);
	for(int i=0;;i++)
	{

		char* sendfile,fileDir[100]="./Login_Page";
		memset(buffer_in_get,0,BUFFER_MAX_SIZE_IN);

		
		new_socket = accept(server_fd, NULL, NULL);

		// get the request from the client 
		valread = read(new_socket, buffer_in_get, BUFFER_MAX_SIZE_IN);

		fprintf(stdout,"Buffer_IN_GET after free :\n%s\n\ni count : %d\n\n",buffer_in_get,i);

		

		// Send the web page to the user 
		if(i==0)
			valwrite = write(new_socket, buffer_final,strlen(buffer_final));
		if(i>0)
		{
			if(strcmp(request(buffer_in_get),GET)==0)
			{
				sscanf(buffer_in_get,"%*c%*c%*c%*c%100[^ ]",fileDir+12);
				printf("\nfilename riquested : |%s\n", fileDir);
				FILE *SenderPage = fopen(fileDir,"rb");
				sendfile = webPageLoader(SenderPage);

			}
			valwrite = write(new_socket, sendfile,strlen(sendfile));
		}
			

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
	printf("\nfile to sent [========================================]100\n\n%s\n",buffer);
	return buffer;
}


char* request(char* buffer)
{
	char temp[4];
	strncpy(temp, buffer,4);
	if(strcmp(temp,GET))
	return GET;
	if(strcmp(temp,POST))
	return POST;
	return ERR;

}


char* loginChecker(char* getRequest)
{
	
	char* buffer;
	return buffer;
}