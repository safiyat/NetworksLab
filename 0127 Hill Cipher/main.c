#include <stdio.h>

#define SIZE 100

#define AUTO

void enDeCrypt(const char *input, char *output, const int **key, const int keyLen)
{
	int i, j, temp;
	char *ip, *k;

	ip = (char *) malloc(sizeof(char) * (strlen(input) + 1));
	k = (char *) malloc(sizeof(char) * (strlen(key) + 1));
	strcpy(ip, input);
	strcpy(k, key);
	for(i = 0; i < strlen(input); i++)
	{
		if(i < strlen(key))
			k[]
	}
	while()
	{
		for(i = 0; i < keyLen; i++)
		{
			temp = 0;
			for(j = 0 ; j < keyLen; j++)
				temp += key[i][j] * input[];
			output[] = temp % 26 + 97;
		}
	}
}

int main()
{
	int i, j, n, keyLen;
	char plainText[SIZE], *cipherText, *key;
	printf("Enter the Plain text: ");
	fgets(plainText, SIZE, stdin);
	n = (int) strlen(plainText);
	plainText[n - 1] = '\0';								//Eliminating the newline char
	n--;

#ifdef AUTO
	key = (char *) malloc(sizeof(char) * 10);
	key[0] = 6  + 97;
	key[1] = 24 + 97;
	key[2] = 1  + 97;
	key[3] = 13 + 97;
	key[4] = 16 + 97;
	key[5] = 10 + 97;
	key[6] = 20 + 97;
	key[7] = 17 + 97;
	key[8] = 15 + 97;
	key[9] = '\0';
	keyLen = 3;
#else
	printf("\nEnter the length of keystring: ");
	scanf("%d", &keyLen);
	key = (char *) malloc(sizeof(char) * (keyLen + 1));
	i = 0;
	while( i < keyLen)
		key[i++] = getchar();
	key[i] = '\0';
#endif
	while(n % keyLen)
	{
		strcat(plainText, "$");
		n++;
	}
	cipherText = (char *) malloc(sizeof(char) * (n + 1));
	enDeCrypt(plainText, cipherText, key, keyLen);

	printf("\nCipher text: %s", cipherText);
	return 0;
}
