#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

struct textStruct
{
		char *text;
		int len;
};

void scan(struct textStruct *t)
{
	int i = 0;
	char ch;
	while((ch = getchar()) != '\n')
	{
		if(!isalpha(ch))
			continue;
		ch = tolower(ch);
		t->text = (char *)realloc(t->text, sizeof(char)*(i+1));
		t->text[i++] = ch - 97;
	}
	t->len = i;
}

void print(struct textStruct *t)
{
	int i = 0;
	while(i < t->len)
	{
		putc(t->text[i++] + 97, stdout);
	}
	putc('\n', stdout);
}

void multiply(struct textStruct *input, struct textStruct *key, struct textStruct *output)
{
	int i, j, *P, **K, *C, kLen;
	kLen = sqrt(key->len);
	P = (int *) malloc(sizeof(int) * input->len);
	K = (int **) malloc(sizeof(int *) * kLen);
	for(i = 0; i < kLen; i++)
	{
		K[i] = (int *) malloc(sizeof(int) * kLen);
		if(K[i] == NULL)
		{
			printf("Unable to allocate memory!!!\n");
			return;
		}
	}
	C = (int *) malloc(sizeof(int) * input->len);
	for(i = 0; i < kLen; i++)
	{
		P[i] = input->text[i];
		for(j = 0; j < kLen; j++)
		{
			K[i][j] = key->text[i*kLen + j];
		}
	}

	for(i = 0; i < kLen; i++)
	{
		C[i] = 0;
		for(j = 0 ; j < kLen; j++)
			C[i] += K[i][j] * P[j];
	}
	output->text = (char *) malloc(sizeof(char) * input->len);
	for(i = 0; i < input->len; i++)
		output->text[i] = C[i] % 26;
	output->len = input->len;
}

int main(void)
{
	struct textStruct plainText, cipherText, key;
	plainText.text = key.text = cipherText.text = NULL;
	printf("Enter the plain text: ");
	scan(&plainText);

	printf("\nEnter the key: ");
	scan(&key);

	printf("\n\npt: ");
	print(&plainText);
	printf("Key: ");
	print(&key);

	multiply(&plainText, &key, &cipherText);

	while(1)
	{
		printf("\nCipher text: ");
		print(&cipherText);

		printf("\nEnter the decryption key: ");
		scan(&key);
		if(key.len == 0)
			break;
		multiply(&cipherText, &key, &plainText);
		printf("Decrypted Text: ");
		print(&plainText);
	}
	return 0;
}
