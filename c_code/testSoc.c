// programming
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define PORT 6969
#define SA struct sockaddr*
#define BUFFER_MAX_SIZE_IN 500000
#define GET "GET "
#define POST "POST"
#define ERR "X0"
#define HOMEPAGE "/"
#define IP_ADDRESS "192.168.0.1"
#define PERROR_FL -1
#define HEADER_W_CONTENT "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: %d\r\n\r\n%s"

clock_t start, end;
double cpu_time_used;

char* webPageLoaderToBuffer(FILE*);
char* requestTypeChecker(char*);
int fileLoader(char*,char[]);
void clientMessageCheck(char*,const char*,const char*);
void freeMemory(int num, ...);

int main(int argc, char* argv[])
{
	int server_fd, new_socket, valread, valwrite;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	char buffer_in_get[BUFFER_MAX_SIZE_IN] = { 0 };
	char buffer_final[BUFFER_MAX_SIZE_IN],previousBuffer[BUFFER_MAX_SIZE_IN];
	
	//load the web page
	int filesloager = fileLoader(HOMEPAGE,buffer_final);
	
	server_fd = socket(AF_INET, SOCK_STREAM, 0);
;
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	bind(server_fd, (SA)&address, sizeof(address));

	start = ((double)clock())/ CLOCKS_PER_SEC;

	char* sendfile,fileDir[100]="./Login_Page";
	memset(buffer_in_get,0,BUFFER_MAX_SIZE_IN);
	char home[15] = HOMEPAGE;
	fileLoader(sendfile, buffer_final);

	

	listen(server_fd, 5);

	
	for(int i=0;;i++)
	{
		
		// Connection made on new_socket with the accept finction
		new_socket = accept(server_fd,NULL, NULL);

		// get the request from the client 
		
		valread = read(new_socket, buffer_in_get, BUFFER_MAX_SIZE_IN);
		strcpy(previousBuffer,buffer_in_get);

		if(strcmp(previousBuffer,buffer_in_get)!=0)
		    printf("| ok | Recived from Browser Message |\n%s\n",buffer_in_get);

	        valwrite = write(new_socket, buffer_final,strlen(buffer_final));
		
		end =((double)clock())/ CLOCKS_PER_SEC;
		printf("%0.8f",end-start);
		if((end-start)>15)
			close(new_socket);
	}
	shutdown(server_fd, SHUT_RDWR);
	
    // cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

	return 0;
}

void clientMessageCheck(char* buffer_in,const char* header,const char* buffer_final)
{
	const char* home=header;
	fprintf(stdout,"Buffer_IN_GET after Accept in new_socket :\n%s\n\n",buffer_in);

	sscanf(buffer_in,"%*c%*c%*c%*c%14[^HTTP/1.1]",home+12);
	printf("\nhome checker : |%s|\n", home);
    if(strcmp(home,"/")==0)
    {
        sprintf(stdout, "Ok\n",NULL);
        if(fileLoader(buffer_final, header)==0)
            sprintf(stdout, "Ok\n",NULL);
    }
    else
        sprintf(stdout, "error no load\n",NULL);
}

//This function takes two paramaters char*,const char*. returns values PERROR_FL(-1) in error, 0 in successful loading of file
int  fileLoader(char* Homepage, char buffer_final[])
{
	FILE* authFile = fopen("./software/login.html", "r");
	if(authFile == 0)
		return PERROR_FL;
	
	// returns a heap allocated buffer so please free it to the escape memory leaks
	Homepage = webPageLoaderToBuffer(authFile);

	sprintf(buffer_final,HEADER_W_CONTENT,strlen(Homepage),Homepage);

	return 0;
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
	return buffer;
}

/* This variadic function takes int as number of buffers sent, char* list of buffer pointers in as parameters to be freed from the heap
*/  
// void freeMemory(int num, ...) {
//     va_list args;
//     va_start(args, num);
//     for (int i = 0; i < num; i++) {
//         char n = va_arg(args,char);
// 		free(n);
//         printf("%i %p  is free.",i, n);
//     }
//     va_end(args);
//     printf("\n");
// }