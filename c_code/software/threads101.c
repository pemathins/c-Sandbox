#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <time.h>
#include <unistd.h>

#define MAXTHREAD 150000

typedef struct THREAD_ARGS {
    int* i;
}THREAD_ARGS;

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int thread_func(int* i)
{
    (*i)++;
    int x = *i;
    unsigned long long int test = factorial(rand()%10)*(1579537);
    
    printf("%d)ctest : %lu\n\n===================\n",*i,test);
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
        /*int thrd_join( thrd_t thr, int *res );*/
        //pthread_join(thread[i],NULL);
        
    }

    fprintf(stdout,"thread count is %d",valueofthreads);

    return 0;

}