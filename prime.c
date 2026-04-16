#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include <stdlib.h>
#define THREADS 4
int count = 0;
typedef struct {
	int start;
	int end;
} ThreadData;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int prime(int num){
	if (num < 2) return false; /* 0 and 1 are not prime */
	for (int i = 2; i < num; i++){
		if(num % i == 0){ 
			return false;
		}
	}
	pthread_mutex_lock(&mutex);
	printf("%d is a prime number.\n", num);
	count++;
	pthread_mutex_unlock(&mutex);
	return true;
}
void* thread_func(void* arg){
	ThreadData* data = (ThreadData*)arg; /* Cast the argument to ThreadData pointer */
	for (int i = data->start; i < data->end; i++){ /* Check for prime numbers in the assigned range */
		prime(i); /* Call the prime function for each number in the range */
	}
	free(arg);
	return NULL;
}
int main(void){

	/*for(int i = 0; i < 100; i++) 	if (prime(i))  printf("%d\n", i); */
	pthread_t threads[THREADS];  
	for (int i = 0; i < THREADS; i++){
		ThreadData* data = malloc(sizeof(ThreadData)); /* Allocate memory for thread data */
		data->start = i * 25; /* Each thread will check a range of 25 numbers */
		data->end = (i + 1) * 25; /* End of the range for the thread */
		pthread_create(&threads[i], NULL, thread_func, data); /* Create a thread to execute the thread function */
	}

	for (int i = 0; i < THREADS; i++){
		pthread_join(threads[i], NULL);
	}
	printf("Total prime numbers between 0 and 100: %d\n", count);
	return 0;
}
