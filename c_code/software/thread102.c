#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <time.h>
#include <unistd.h>

#define MAXTHREAD 150000
#define MAX_USERS 3500
#define DJSON_USER_LOGIN "{'Id':%d,'Name':'%*c35[^\\0]','PassHash':'%s','emailin':'%*c23[^@]'}\n"
#define SJSON_USER_LOGIN "{'Id':%d,'Name':'%s','PassHash':'%s','emailin':'%s'}\n"
int factorial(int);

typedef struct LoginUser 
{
    unsigned int id;
    const char* Name;
    const char* Password;
    const char* emailid;
} LoginUser;

int LoadDataUser()
{
    FILE* u_userData = fopen("user.dat","rb");
    LoginUser user[MAX_USERS];
    int i=0;
    while(feof(u_userData)!=0)
    {
        fscanf(u_userData,DJSON_USER_LOGIN,user[i].id,user[i].Name,user[i].Password,user[i].emailid);
        i++;
    }
}

int thread_func(void* i)
{
    (*(int*)i)++;
    int x = *(int*)i;
    unsigned long long int test = factorial(rand()%10)*(1579537);
    
    printf("%d)ctest : %lu\n\n===================\n",*(int*)i,test);
    sleep(5);
    return 0;
}

int main()
{
    int valueofthreads=0;

    thrd_t thread[MAXTHREAD];
    for(int i=0;i<MAXTHREAD;i++)
    {       

        /*int thrd_create( thrd_t *thr, thrd_start_t func, void *arg );*/

        thrd_create(&thread[i], thread_func,&valueofthreads);

        /*int thrd_join( thrd_t thr, int *res );*/
        //thrd_join(thread[i], NULL);
        
        //pthread_join(thread[i],NULL);
        
    }

    fprintf(stdout,"thread count is %d",valueofthreads);

    return 0;

}

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}
