#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <pthread.h>
#define THREADS 4
long long count = 0;
typedef struct {
	long long start;
	long long end;
} ThreadData;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int prime(int num){
	if (num < 2) return 0; /* 0 and 1 are not prime */
	for (int i = 2; i * i <= num; i++){
		if(num % i == 0){ 
			return 0;
		}
	}
	pthread_mutex_lock(&mutex);
	printf("%d is a prime number.\n", num);
	count++;
	pthread_mutex_unlock(&mutex);
	return 1;
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

	if (argc != 2 || atoll(argv[1]) > LLONG_MAX) {
		fprintf(stderr, "Usage: %s <upper_limit>\n", argv[0]);
		return 1;
	}
	long long upper = atoll(argv[1]); /* Convert the command line argument to an integer */
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
		data->start = i * (upper / THREADS); /* Calculate the start of the range for this thread */
		data->end = (i == THREADS - 1) ? upper + 1 : (i + 1) * (upper / THREADS); /* Calculate the end of the range for this thread, ensuring the last thread covers any remaining numbers */
		if (pthread_create(&threads[i], NULL, thread_func, data) != 0) {
			fprintf(stderr, "Error creating thread %d\n", i);
			free(data); /* Free the allocated memory if thread creation fails */
			return 4;
		}
	}
	for (int i = 0; i < THREADS; i++){
		pthread_join(threads[i], NULL);
	}	
	pthread_mutex_destroy(&mutex); /* Destroy the mutex after use */
	printf("Total prime numbers between 0 and %lld: %lld\n", upper, count);
	return 0;
}
