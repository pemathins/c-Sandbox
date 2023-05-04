#include <stdio.h>
#include <string.h>

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

// Diffrent way of loading file
	// fgets(pagebuffer, sizeof pagebuffer,file)

	// while(!feof(file))
	// {==0)
	// 	sscanf(pagebuffer,"\n",);
	// 	fgets(pagebuffer, sizeof pagebuffer,file);
	// }

	// fclose(file);;

	// strcat(buffer_test,user_Name,);

	// Creating socket file descriptor