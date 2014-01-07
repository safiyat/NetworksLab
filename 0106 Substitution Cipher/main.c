#include <stdio.h>

int main()
{
	int len, key;
	char *plainText, *cipherText;
	plainText = NULL;
	len = 1;			// Extra space for the terminating '\0' character.
	printf("Enter the plain text (delimited by '#'):\n");
	while((ch = getchar()) != '#')
	{
		len++;
		plainText = (char *) realloc(sizeof(char) * len);
		plainText[len - 2] = ch;
	}
	plainText[len - 1] = '\0';
	
	printf("\nEnter the displacement key: ");
	scanf("%d", &key);
	
	cipherText = (char *) malloc(sizeof(char) * len);
	
	for(i = 0; i < (len - 1); i++)
	{
	}
}
