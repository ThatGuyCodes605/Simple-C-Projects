#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <limits.h>

#define NUM_THREADS sysconf(_SC_NPROCESSORS_ONLN)  

void* maths(void* threadid) {
		long tid = (long)threadid;
		printf("Thread %ld starting...\n", tid);
		// do some maths
		int result = 0;
		for (int i = 0; i < INT_MAX; i++) {
				result += i;
		}
		printf("Thread %ld finished with result %d\n", tid, result);
		pthread_exit(NULL);
}
int main(void)
{
		/*
			myturn(); // this will never return, so yourturn() will never be called 
			yourturn(); // this will never be reached 
		*/	
		// To fix this, we can use threads:
		pthread_t threads[NUM_THREADS];
		/* do some maths */
		for (long i = 0; i < NUM_THREADS; i++) {
				pthread_create(&threads[i], NULL, maths, (void*)i);
		}
		/* wait for all threads to finish */
		for (int i = 0; i < NUM_THREADS; i++) {
				pthread_join(threads[i], NULL);
		}

		
		return 0;
}
