/* compiled by g++ -fpermissive -o changingReturnAdress changingReturnAdress.cpp 
	g++ -v (version of g++):
		gcc version 4.8.4 (Ubuntu 4.8.4-2ubuntu1~14.04.3)
		Target: x86_64-linux-gnu
*/
#include <stdio.h>

void lol();

int main()
{
	printf("Starting main function\n");
	lol();
	printf("Lol function has been called\n");
	return 0;
}

void lol()
{
	long a = 5; // this local variable used for calculating address of place, where stored returning adress
	*(&a + 2) = (int)main; // substituting returning adress at main function first instruction adress
}
