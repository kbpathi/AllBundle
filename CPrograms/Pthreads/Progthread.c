#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details. 
#include <pthread.h> 

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition_var = PTHREAD_COND_INITIALIZER;

int i;


void *myThreadIncFunEven(void *vargp) 
{ 
   // Lock mutex and then wait for signal to relase mutex
   pthread_mutex_lock(&mutex); 

    while (i < 30){
        if (i%2 == 0)
	    pthread_cond_wait(&condition_var, &mutex); 
        
	if(i%2 != 0){
           printf("EVEN Thread %d\n", ++i);
           pthread_cond_signal( &condition_var );
        }
    }
    pthread_mutex_unlock(&mutex); 
    return NULL;
}

void *myThreadIncFunOdd(void *vargp) 
{ 
   pthread_mutex_lock(&mutex);

    while (i < 30){
        if (i%2 != 0)
	    pthread_cond_wait(&condition_var, &mutex);
 
        if (i%2 == 0){
           printf("ODD Thread %d\n", ++i);
           pthread_cond_signal( &condition_var );
        }
    }
    pthread_mutex_unlock(&mutex); 
    return NULL; 
}
   
int main() 
{ 
    pthread_t thread_id;
    printf("Before Thread i= %d\n", i); 
    pthread_create(&thread_id, NULL, myThreadIncFunEven, NULL);
    pthread_create(&thread_id, NULL, myThreadIncFunOdd, NULL);
    pthread_join(thread_id, NULL);
    printf("After Thread i=%d\n" , i);
    exit(0);
}
