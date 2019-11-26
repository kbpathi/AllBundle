#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details. 
#include <pthread.h> 
int i;

void *myThreadIncFun(void *vargp) 
{ 
    sleep(1);
    while (i < 30)
        printf("MYTHREAD Increment Function %d\n", ++i); 
    return NULL; 
}
   
int main() 
{ 
    pthread_t thread_id; 
    printf("Before Thread i= %d\n", i); 
    pthread_create(&thread_id, NULL, myThreadIncFun, NULL); 
    while (i <30 )
        printf("MAIN Increment Function %d\n", ++i);
    pthread_join(thread_id, NULL); 
    printf("After Thread i=%d\n" , i); 
    exit(0); 
}
