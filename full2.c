#include	<stdio.h>
#include	<string.h>

char first[100];
char last[100];

char full[100];
int main()
{
	printf("Enter the first name: ");
	fgets(first, sizeof(first), stdin);
	first[strlen(first)-1] = '\0';
	
	printf("Enter the last name: ");
	fgets(last, sizeof(first), stdin);
	last[strlen(last)-1] = '\0';
	
	strcpy(full, first);
	strcat(full, " ");
	strcat(full, last);
	
	printf("The full name is: %s\n", full);
	return(0);
}
