#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char** argv)
{
	if (argc < 4 || (argc - 1) % 2 == 0) {
		fprintf(stderr, "Usage: calculate <number> <operator> <number> [<operator> <number>]...\n");
		return 1;
	}
	long double result = atof(argv[1]);

	for (int i = 2; i < argc; i += 2) {
		char* operator = argv[i];

		long double operand = atof(argv[i + 1]);

		if (strcmp(operator, "+") == 0) {
			result += operand;
		} 

		else if (strcmp(operator, "-") == 0) {
			result -= operand;
		} 

		else if (strcmp(operator, "x") == 0) {
			result *= operand;
		}

		else if (strcmp(operator, "/") == 0) {

			if (operand == 0) {
				fprintf(stderr, "Error: Division by zero\n");
				return 2;
			}

			result /= operand;
		} 

		else if (strcmp(operator, "%") == 0) {

			if (operand == 0) {
				fprintf(stderr, "Error: Modulo by zero\n");
				return 3;
			}

			result = (long long)result % (long long)operand;

		} 
		else {
			fprintf(stderr, "Error: Unknown operator '%s'\n", operator);
			return 4;
		}
	}
	if (result == (long long)result) {
		printf("%lld\n", (long long)result);
	} 
	else {
		printf("%Lf\n", result);
	}
	return 0;
}
				

 
