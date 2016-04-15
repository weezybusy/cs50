/**
 * initials.c
 * 
 * Vitaliy Pisnya
 * vitaliy.pisnya@gmail.com
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
	
	for (int i = 1; name[i] != '\0'; i++)
	{
		if (!isspace(name[i - 1]) && i - 1 == 0)
		{
			printf("%c", toupper(name[i - 1]));
		}
		else if (isspace(name[i - 1]) && !isspace(name[i]))
		{
			printf("%c", toupper(name[i]));
		}
	}
	putchar('\n');
	
	return 0;
}