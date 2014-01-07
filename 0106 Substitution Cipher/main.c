#include <stdio.h>
#include <stdlib.h>

int main()
{
	int len, key, i;
	char *plainText, *cipherText, ch;
	plainText = NULL;
	len = 1;			// Extra space for the terminating '\0' character.
	printf("Enter the plain text (delimited by '#'):\n");
	while((ch = getchar()) != '#')
	{
		len++;
		plainText = (char *) realloc(plainText, sizeof(char) * len);
		plainText[len - 2] = ch;
	}
	plainText[len - 1] = '\0';
	
	printf("\nEnter the displacement key: ");
	scanf("%d", &key);
	key %= 26;
	printf("Effective key: %d\n\n", key);
	
	cipherText = (char *) malloc(sizeof(char) * len);
	
	for(i = 0; i < (len - 1); i++)
	{
		if(plainText[i] < 32)
		{
			cipherText[i] = plainText[i];
			continue;
		}
		ch = plainText[i] + key;
		if(ch > 126)
			ch = 31 + (ch - 126);
		cipherText[i] = ch;
	}
	cipherText[len - 1] = '\0';
	
	while(1)
	{
		printf("\n\tCipherText:\n%s", cipherText);
		printf("\nEnter the displacement key (negative to exit): ");
		scanf("%d", &key);
		if(key < 0)
			return 0;
		key %= 26;
		printf("\n\tPlain Text:\n");
		for(i = 0; i < (len - 1); i++)
		{
			ch = cipherText[i];
			if(ch < 32)
			{
				putchar(ch);
				continue;
			}
			ch -= key;
			if(ch < 32)
				ch = 126 - (31 - ch);
			putchar(ch);
		}
		printf("\n\n");
	}
	return  0;
}
