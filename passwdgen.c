#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int main(int argc, char** argv)
{
	if (argc < 2 || argc > 3)
	{
		printf("Usage: ./a.out <number>\n");
		return 1;
	}
	int length = atoi(argv[1]);
	char* password = malloc(length + 1);
	if(password == NULL)
	{
		printf("Memory allocation failed\n");
		return 2;
	}
	char* ascii = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm<>,./?;:{}[]1234567890!@#$%^&*()_+-=";
	srand(time(NULL));
	for (int i = 0; i < length; i++){
		int randomIndex = rand() % strlen(ascii);
		password[i] = ascii[randomIndex];
	}
	password[length] = '\0';
	printf("%s\n", password);
	return 0;
}
