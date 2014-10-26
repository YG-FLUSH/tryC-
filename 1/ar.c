#include <stdio.h>

int main()
{
	char *a="s";
		char *b="s";
	if(a==b)
	printf("Y%x",a);
	else 
	printf("N%x  %x,%x  %x",a,&a,b,&b);
} 