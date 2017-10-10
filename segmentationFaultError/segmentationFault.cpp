/*
	It is interesting that error will appear only in line 15(delete a;),
	but heap destroyed before it.
*/
#include <stdio.h>
int main(int argc, char const *argv[])
{
	int *a = new int;
	for (int i = 0; i < 1050; ++i)
	{
		a[i] = 1;
		printf("%d\n",i );
	}
	printf("Memory Error requeired\n");
	delete a;
	return 0;
}