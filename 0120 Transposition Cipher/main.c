#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KSIZE 10

//#define DEBUG

void rankify1(int* rank,const char *key)
{
	int i, j, min, len;
	char temp[KSIZE];
	strcpy(temp, key);
	len = strlen(temp);
	for(i = 0; i < len; i++)
	{
		for(j = 0; j < len; j++)
			if(temp[j] != 1)
			{
				min = j;
				break;
			}
		for(j = 0; j < len; j++)
		{
			if(temp[min]>temp[j] && temp[j]!=1)
				min = j;
		}
		rank[i] = min;
		temp[min] = 1;
	}
}

void rankify2(int* rank,const char *key)
{
	int i, j, min, len;
	char temp[KSIZE];
	strcpy(temp, key);
	len = strlen(temp);
	for(i = 0; i < len; i++)
	{
		for(j = 0; j < len; j++)
			if(temp[j] != 1)
			{
				min = j;
				break;
			}
		for(j = 0; j < len; j++)
		{
			if(temp[min]>temp[j] && temp[j]!=1)
				min = j;
		}
		rank[min] = i;
		temp[min] = 1;
	}
}

int main()
{
	int len, i, rank[KSIZE], flag, curpos, j, row;
	char *plainText, *cipherText, ch, key[KSIZE];
	plainText = NULL;
	len = 1;			// Extra space for the terminating '\0' character.
	printf("Enter the plain text:\n");
	while(!isspace(ch = getchar()))
	{
		len++;
		plainText = (char *) realloc(plainText, sizeof(char) * len);
		plainText[len - 2] = ch;
	}
	plainText[len - 1] = '\0';
	
	do
	{
		flag = 0;
		printf("\nEnter the encryption key: ");
		scanf("%s", key);
		for(i = 0; i < (strlen(key) - 1) && !flag; i++)
		{
			for(j = i + 1; j < strlen(key); j++)
			{
				if(key[i] == key[j])
				{
					flag = 1;
					printf("Invalid key!!!\n");
					break;
				}
			}
		}
	}while(flag);
#ifdef DEBUG
	printf("\nPlainText: %s\t\tKey: %s\n", plainText, key);
#endif
	
	while(strlen(plainText) % strlen(key))
	{
		len++;
		plainText = (char *) realloc(plainText, sizeof(char) * len);
		strcat(plainText, "$");
	}
	
	cipherText = (char *) malloc(sizeof(char) * len);
	
	rankify1(rank, key);

	len = strlen(key);
#ifdef DEBUG	
	printf("\nKey: %s, len: %d, rank:\n", key, len);
	for(i = 0; i < len; i++)
		printf("\nrank[%d] = %d", i, rank[i]);
#endif
	
	for(i = j = 0 ; i < len; i++)
	{
		curpos = rank[i];
		while(curpos < strlen(plainText))
		{
			cipherText[j++] = plainText[curpos];
			curpos += len;
		}
	}
	cipherText[j] = '\0';
	
	printf("\nCipher Text:\n%s\n", cipherText);

	getchar();

	while(1)
	{
		printf("\nCipher Text: %s\n", cipherText);
		do
		{
			flag = 0;
			printf("Enter the encryption key (\"end\" to terminate): ");
			scanf("%s", key);
			if(!strcmp(key, "end"))
				return 0;
			for(i = 0; i < (strlen(key) - 1) && !flag; i++)
			{
				for(j = i + 1; j < strlen(key); j++)
				{
					if(key[i] == key[j])
					{
						flag = 1;
						printf("Invalid key!!!\n");
						break;
					}
				}
			}
		}while(flag);
		rankify2(rank, key);
		
		len = strlen(key);
		
		row = strlen(cipherText) / len;
		
		for( i = 0; i < len; i++)
		{
			rank[i] *= row;
		}
		
		printf("\nDecrypted Plaintext: ");
		for( i = 0; i < row; i++)
		{
			for( j = 0; j < len; j++)
			{
				if(cipherText[rank[j]] != '$')
					printf("%c", cipherText[rank[j]]);
				rank[j]++;
			}
		}
		printf("\n\n");
	}
	return  0;
}
