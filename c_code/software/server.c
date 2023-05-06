// programming
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include "libweb.a"

#define PORT 6969
#define SA struct sockaddr*
#define BUFFER_MAX_SIZE_IN 500000
#define GET "GET "
#define POST "POST"
#define ERR "X0"
#define HOMEPAGE "./Login_Page/ "
#define IP_ADDRESS "192.168.0.1"
#define PERROR_FL -1


char* webPageLoaderToBuffer(FILE*);

char* requestTypeChecker(char*);

int fileLoader(char*,char[]);

void freeMemory();

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
	int filesloager = fileLoader(HOMEPAGE,buffer_final);
	
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

		char home[15] = HOMEPAGE;
		new_socket = accept(server_fd,NULL, NULL);

		// get the request from the client 
		valread = read(new_socket, buffer_in_get, BUFFER_MAX_SIZE_IN);

		fprintf(stdout,"Buffer_IN_GET after free :\n%s\n\ni count : %d\n\n",buffer_in_get,i);

		sscanf(buffer_in_get,"%*c%*c%*c%*c%14[^ ]",home+12);
		printf("\nhome checker : |%s\n", home);	
		
		// Send the web page to the client Browser
		if(strcmp(home,HOMEPAGE)==0){
	
			valwrite = write(new_socket, buffer_final,strlen(buffer_final));

		}

		else if(i>0 && (strcmp(home,HOMEPAGE)!=0))
		{
			if(strcmp(requestTypeChecker(buffer_in_get),GET)==0)
			{
				sscanf(buffer_in_get,"%*c%*c%*c%*c%100[^ ]",fileDir+12);
				printf("\nfilename riquested : |%s\n", fileDir);
				FILE *SenderPage = fopen(fileDir,"rb");
				sendfile = webPageLoaderToBuffer(SenderPage);

			}
			valwrite = write(new_socket, sendfile,strlen(sendfile));
		}
			

		close(new_socket);
	}
	shutdown(server_fd, SHUT_RDWR);

	freeMemory(1,buffer_final);
	return 0;
}
//This function takes two paramaters char*,const char*. returns values PERROR_FL(-1) in error, 0 in successfull loading of file
int  fileLoader(char* Homepage, char buffer_final[])
{
	FILE* authFile = fopen("./Login_Page/login.html", "r");
	if(authFile == 0)
		return PERROR_FL;
	

	// returns a heap allocated buffer so please free it to the escape memory leaks
	char* bufferpage = webPageLoaderToBuffer(authFile);

	sprintf(buffer_final,HEADER_W_CONTENT,strlen(bufferpage),bufferpage);
	printf("\n%s",buffer_final);

	return buffer_final;
}


// This function takes the parameters FILE* to the file and returns char* upon successful loading to the buffer
char* webPageLoaderToBuffer(FILE* file)
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
	if(i == strlen(buffer))
		printf("\nfile to buffer [========================================]100\%\n\n%s\n",buffer);
	return buffer;
}



char* requestTypeChecker(char* buffer)
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

/* This variadic function takes int as number of buffers sent, char* list of buffer pointers in as parameters to be freed from the heap
*/  
void freeMemory(int num, ...) {
    va_list args;
    va_start(args, num);
    for (int i = 0; i < num; i++) {
        char* n = va_arg(args, char*);
		free(n);
        printf("%i %p  is free.",i, n);
    }
    va_end(args);
    printf("\n");
}