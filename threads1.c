#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
void* my_turn(void* arg){
	int* ptr = (int *)malloc(sizeof(int)); /* allocates 4 bytes of RAM to the heap */
	*ptr = 0; /* sets the VALUE of the pointer to 0 */
	for (int c = 0; c < 100; c++) {
		printf("%d:My turn!\n", c);
		(*ptr)++; /* add to the VALUE by 1 */
	}	
	return ptr; /* returns the ADDRESS of the pointer */
}
void your_turn(){  
	for (int c = 0; c < 100; c++) {
		printf("%d:your turn!\n",c);
	}
}
int main(void){
	pthread_t thread1; /* creates new thread called thread1 */
	int* result; /* creates a int pointer called result */
	pthread_create(&thread1, NULL, my_turn, NULL); /* assigns the new thread to a function called my_turn with zero arguments */ 

	your_turn(); /* runs the your turn funtion on the main thread */

	pthread_join(thread1, (void*)&result ); /* makes sure the thread finnished before the program exits and stores the return value of the funtion into a pointer called result */ 
	printf("Thread done! *result = %d\n", *result);  

	return 0;
}
