//
//  main.c
//  HillCipher
//
//  Created by admin on 27/01/14.
//  Copyright 2014 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100
#define AUTO

int main (int argc, const char * argv[])
{
    int n, **key, i, *cipherText, j, sum;
    char plainText[SIZE];
    // insert code here...
    printf("Enter the PlainText: ");
    fgets(plainText, SIZE, stdin);
    n = (int) strlen(plainText) - 1;
#ifdef AUTO
    while(n%3)
    {
        strcat(plainText, "$");
        n++;
    };
#endif
    key = (int **) malloc(sizeof(int *) * n);
    cipherText = (int *) malloc(sizeof(int) * n);
    for(i = 0; i < n; i++)
    {
        key[i] = (int *) malloc(sizeof(int) * n);
        cipherText[i] = 0;
        plainText[i] -= 97;
    }
#ifndef AUTO
    printf("\nEnter the %dx%d key:\n", n, n);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            scanf("%d", &key[i][j]);
    }
#else
    key[0][0] = 17;
    key[0][1] = 17;
    key[0][2] = 5;
    key[1][0] = 21;
    key[1][1] = 18;
    key[1][2] = 21;
    key[2][0] = 2;
    key[2][1] = 2;
    key[2][2] = 19;
#endif
    for(i = 0; i < n; i++)
    {
        for(j = 0 ; j < n; j++)
            cipherText[i] += key[i][j] * plainText[j];
    }
    printf("\nCipher Text: ");
    for(i = 0; i < n; i++)
    {
        putchar(cipherText[i] % 26 + 97);
//        printf(" %d ", cipherText[i] % 26);
    }
    
#ifndef AUTO
    printf("\nEnter the %dx%d key for decryption:\n", n, n);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            scanf("%d", &key[i][j]);
    }
#else
    key[0][0] = 4;
    key[0][1] = 9;
    key[0][2] = 15;
    key[1][0] = 15;
    key[1][1] = 7;
    key[1][2] = 6;
    key[2][0] = 24;
    key[2][1] = 0;
    key[2][2] = 17;
#endif
    printf("\nDecrypted Plain Text:\n");
    for(i = 0; i < n; i++)
    {
        sum = 0;
        for(j = 0 ; j < n; j++)
        {
            printf("->%d", sum);
            sum += key[i][j] * cipherText[j];
        }
        printf(" %d\n", sum);
//        putchar(sum);
    }
    printf("\n");
    return 0;
}

