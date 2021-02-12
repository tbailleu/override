#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(void)
{
	char buffer [100];

	fgets(buffer, 100, stdin);
	strlwr(buffer);
	printf(buffer);
	exit(0);
}
