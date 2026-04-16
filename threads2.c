#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <pthread.h>
#include <time.h>
#define THREADS 4
uint32_t counter = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
void* count_to_int_max(void* arg){
	for (uint32_t i = 0; i < 1000000; i++) {
		pthread_mutex_lock(&lock);
		counter++;	
		pthread_mutex_unlock(&lock);
	}
	return NULL;
}
int main(void){
	pthread_t threads[THREADS];
	for (int i = 0; i < THREADS; i++) {
		pthread_create(&threads[i], NULL, count_to_int_max, NULL);	
	}
	for (int i = 0; i < THREADS; i++){
		pthread_join(threads[i], NULL);
	}
	printf("Done! Counter = %u\n", counter);
	return 0;
}
