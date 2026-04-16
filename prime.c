#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include <stdlib.h>
#include <limits.h>
#define THREADS 4
int count = 0;
typedef struct {
	int start;
	int end;
} ThreadData;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int prime(int num){
	if (num < 2) return false; /* 0 and 1 are not prime */
	for (int i = 2; i * i <= num; i++){
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
int main(int argc, char** argv){

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <upper_limit>\n", argv[0]);
		return 1;
	}
	int upper = atoi(argv[1]); /* Convert the command line argument to an integer */
	if(upper <= 0){
		fprintf(stderr, "Please enter a positive integer as the upper limit.\n");
		return 2;
	}
	/*for(int i = 0; i < 100; i++) 	if (prime(i))  printf("%d\n", i); */
	pthread_t threads[THREADS];  
	for (int i = 0; i < THREADS; i++){
		ThreadData* data = malloc(sizeof(ThreadData)); /* Allocate memory for thread data */
		if (data == NULL) {
			fprintf(stderr, "Memory allocation failed\n");
			return 3;
		}
		data->start = i * (atoi(argv[1]) / THREADS); /* Calculate the start of the range for this thread */
		data->end = (i + 1) * (atoi(argv[1]) / THREADS); /* Calculate the end of the range for this thread */
		if (pthread_create(&threads[i], NULL, thread_func, data) != 0) {
			fprintf(stderr, "Error creating thread %d\n", i);
			free(data); /* Free the allocated memory if thread creation fails */
			return 4;
		}
	}

	for (int i = 0; i < THREADS; i++){
		pthread_join(threads[i], NULL);
	}
	printf("Total prime numbers between 0 and %d: %d\n", upper, count);
	return 0;
}
