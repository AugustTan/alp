#include	<stdio.h>
#include 	<string.h>
	
char line[100];
int main()
{
	printf("Enter a line: ");
	fgets(line, sizeof(line), stdin);
	
	printf("The length of the line is: %s\n", strlen(line));
	return(0);
}
