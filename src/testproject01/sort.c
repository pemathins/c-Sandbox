#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 6969
#define SA struct sockaddr*
#define BUFFERMAX 55

int checker(const char *, char *);
int palandromic(const char *);
int armstrong(const char *buffer);
int cube(int);
int armstrong(const char *);

int main(int argc, char *argv[])
{
    int server_fd, new_socket, valread, valwrite;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFERMAX];
    int bufferMessage[BUFFERMAX];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (SA)&address, sizeof(address));

    listen(server_fd, 5);

    new_socket = accept(server_fd, NULL, NULL);

    valread = read(new_socket, buffer, BUFFERMAX);

    printf("%s\n", buffer);

    sort(buffer, bufferMessage);

    valwrite = write(new_socket, bufferMessage, strlen(bufferMessage));

    printf("%s\n", bufferMessage);

    close(new_socket);

    shutdown(server_fd, SHUT_RDWR);

    return 0;
}

int *sort(const char *buffer, const char *bufferMsg)
{
    // binary sort
    int *array = (int*)buffer;
    int len = array[0];
    for (int i = 1; i <len; i++)
    {
        for (int j = 2; j<len; j++)
        {
            if (array[i] > array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    bufferMsg = array; mm,
}


// int checker(const char* buffer,char* bufferMsg)
// {
// 	//change the function as per the question in below condition
// 	if(palandromic(buffer)==0)
// 	{
// 		strcpy(bufferMsg,"OK");
// 		return 0;
// 	}
// 	else
// 	{
// 		strcpy(bufferMsg,"Error");
// 		return 1;
// 	}
// }

// int palandromic(const char* buffer)
// {
// 	char* temp=(char*)malloc(sizeof(char)*BUFFERMAX);
// 	for(int i = 0,j=strlen(buffer)-1; i < strlen(buffer); i++,j--)
// 	{
// 		temp[i] = buffer[j];
// 	}
// 	if(strcmp(buffer,temp)==0)
// 	{
// 		free(temp);
// 		return 0;
// 	}
// 	return 1;
// }

// int cube(int x)
// {
//     return x*x*x;
// }

// int armstrong(const char* buffer)
// {
// 	int sum=0, temp=0,exact=0,tens=1;
// 	printf("%s\n",buffer);
// 	for(int i=strlen(buffer)-1;i>=0;i--)
// 	{
// 	    if(buffer[i]>=48 && buffer[i]<=57)
// 		    temp = ((int)buffer[i])-48;
// 		else
// 		    return -1;

// 		exact += temp*tens;
// 		sum += cube(temp);
// 		printf("value : %c, sum : %d, exact : %d\n",buffer[i],sum,exact);
// 		tens *= 10;
// 		temp =0;
// 	}
// 	if(sum==exact)
// 	return 0;
// 	return -1;
// }