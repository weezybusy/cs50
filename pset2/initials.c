/**
 * initials.c
 * 
 * by Vitaliy Pisnya
 * 
 * The program prompts a user for their name and then outputs their initials in
 * uppercase with no spaces or periods.
 */

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int main(void)
{
	string name = GetString();
	
	for (int i = 0; name[i] != '\0'; i++)
	{
		if (i == 0)
		{
			printf("%c", toupper(name[i]));
		}
		else if (isspace(name[i]))
		{
			printf("%c", toupper(name[i + 1]));
		}
	}
	putchar('\n');
	
	return 0;
}
