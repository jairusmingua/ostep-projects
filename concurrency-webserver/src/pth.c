#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_THREADS 50


void * fakeFunction(void * data)
{
    printf("Thread %u - performing task with value %d !\n", (int)pthread_self(), (int*)data);
    sleep(5);
    printf("Thread %d done task\n", (int)pthread_self());
    pthread_exit(NULL);
}

int main(int argc, char * argv[])
{
    int rc, i, n;

    if(argc < 2) 
    {
        printf("Please add the number of threads to the command line\n");
        exit(1); 
    }
    n = atoi(argv[1]);
    if(n > MAX_THREADS) n = MAX_THREADS;

    for(i = 0; i < n; i++)
    {
        pthread_t thread  = malloc(sizeof(pthread_t));
        rc = pthread_create(&thread, NULL, fakeFunction,&i);
        if(rc)
        {
             printf("\n ERROR: return code from pthread_create is %d \n", rc);
             exit(1);
        }
        //printf("\n I am thread %u. Created new thread (%u) in iteration %d ...\n", 
               // (int)pthread_self(), (int)thread_id[i], i);
        if(i % 5 == 0) sleep(1);
    }

    pthread_exit(NULL);
  
}
