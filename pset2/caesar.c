/**
 * caesar.c
 * 
 * by Vitaliy Pisnya
 * 
 * Implementation of Caesar’s cipher
 */

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void encode(string, int);

int main(int argc, string argv[])
{
	if (argc != 2)
	{
		printf("Usage: %s key.\n", argv[0]);
		return 1;
	}
	
	int k = atoi(argv[1]);

	if (k < 0)
	{
		fprintf(stderr, "It must be a non-negative number!\n");
		return 1;
	}
	
	string msg = GetString();
	encode(msg, k);

	printf("%s\n", msg);

	return 0;
}

void encode(string str, int k)
{
	int len = strlen(str);
	
	for (int i = 0; i < len; i++)
	{
		if (isalpha(str[i]) && isupper(str[i]))
		{
			str[i] = ((str[i] + k) % 65) % 26 + 'A';
		}
		else if (isalpha(str[i]) && islower(str[i]))
		{
			str[i] = ((str[i] + k) % 97) % 26 + 'a';
		}
		else
		{
			str[i] = str[i];
		}
	}
}
