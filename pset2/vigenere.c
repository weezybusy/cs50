/**
 * vigenere.c
 * 
 * by Vitaliy Pisnya
 * 
 * Program encrypts messages using Vigenère’s cipher.
 */

#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void encode(string, string);
bool not_alpha(string);
int count_shift(string, int);

int main(int argc, string argv[])
{
	if (argc != 2)
	{
		printf("Usage: %s arg\n", argv[0]);
		return 1;
	}
	
	if (not_alpha(argv[1]))
	{
		printf("Key must be alphabetical!\n");
		return 1;
	}

	string k = argv[1];
	string p = GetString();
	encode(p, k);

	printf("%s\n", p);

	return 0;
}

bool not_alpha(string str)
{
	int len = strlen(str);

	for (int i = 0; i < len; i++)
	{
		if (!isalpha(str[i]))
		{
			return true;
		}
	}
	
	return false;
}

void encode(string str, string k)
{
	int str_len = strlen(str);
	int shift;
	
	for (int i = 0, skip_space = i; i < str_len; i++)
	{
		shift = count_shift(k, skip_space);

		if (isalpha(str[i]) && isupper(str[i]))
		{
			str[i] = ((str[i] + shift) % 65) % 26 + 'A';
		}
		else if (isalpha(str[i]) && islower(str[i]))
		{
			str[i] = ((str[i] + shift) % 97) % 26 + 'a';
		}
		else
		{
			str[i] = str[i];
			--skip_space;
		}

		++skip_space;
	}
}

int count_shift(string k, int index)
{
	int len = strlen(k);

	for (int i = 0; i < len; i++)
	{
		k[i] = tolower(k[i]);
	}
	
	return k[index % len] % 97;
}
