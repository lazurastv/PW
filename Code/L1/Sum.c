#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *v[])
{
	int n = argc - 1;
	int sum = 0;
	int i = 1;
	while (n-- > 0)
		sum += atoi(v[i++]);
	printf("%d\n", sum);
}
