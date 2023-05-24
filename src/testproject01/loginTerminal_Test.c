#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void help();

int main(int argc,char* argv[])
{
    char* usr = "Talisman4425";
    char* pd = "XtF8hV4M2";
    int attempt=0;
    int cred = 0;
    
    for(int i=1;i<argc;i++)
    {
        if(strcmp(argv[i],"-h")==0 || strcmp(argv[i],"--help")==0)
        {
            help();
            return 0;
        }
        if(strcmp(argv[i],"-U")==0 || strcmp(argv[i],"--User")==0)
        {
            attempt++;
            if(strcmp(usr,argv[i+1])==0)
            {    
                cred++;
            }
        }
        if(strcmp(argv[i],"-P")==0 || strcmp(argv[i],"--password")==0)
        {
            attempt++;
            if(strcmp(pd,argv[i+1])==0)
            {
                cred++;
            }
        }
        if(attempt>2)
        {
            printf("Invalid Login contest.\n");
            return 0;
        }
             

        if(attempt==2 && cred==2)
        {
            printf("Login Success!\n");
            return 0;
        }
        
        
    }
    printf("Invalid Login\n");
    return 0;

}

void help()
{
    printf("\t    -v     Version of the current application.\n\
            -H      Helps to show the help menu\n\
            -p      run a program.\n\
            -O      Opens a directory enter the path name.\n\
            -T      Displayes the time of the running code.\n");
}