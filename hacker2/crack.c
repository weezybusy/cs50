/**
 * crack.c
 *
 * by Vitaliy Pisnya
 *
 * passwords to crack:
 * ------------------
 * andi:HALRCq0IBXEPM
 * caesar:50zPJlUFIYY0o
 * eli:50MxVjGD7EfY6
 * hdan:50z2Htq2DN2qs
 * jason:50CMVwEqJXRUY
 * john:50TGdEyijNDNY
 * levatich:50QykIulIPuKI
 * rob:50q.zrL5e0Sak
 * skroob:50Bpa7n/23iug
 * zamyla:HAYRs6vZAb4wo

 * Crack these passwords, each of which has been encrypted with C’s DES-based
 * (not MD5-based) crypt function. Specifically, write, in crack.c, a program
 * that accepts a single command-line argument: an encrypted password. If your
 * program is executed without any command-line arguments or with more than one
 * command-line argument, your program should complain and exit immediately,
 * with main returning any non-zero int (thereby signifying an error that our
 * own tests can detect). Otherwise, your program must proceed to crack the
 * given password, ideally as quickly as possible, ultimately printing to
 * standard output the password in the clear followed by \n, nothing more,
 * nothing less, with main returning 0. The underlying design of this program
 * is entirely up to you, but you must explain each and every one of your
 * design decisions, including any implications for performance and accuracy,
 * with profuse comments throughout your source code. Your program must be
 * designed in such a way that it could crack all of the passwords above, even
 * if said cracking might take quite a while. That is to say, it’s okay if your
 * code might take several minutes or days or longer to run. What we demand of
 * you is correctness, not necessarily optimal performance. Your program should
 * certainly work on inputs other than these as well; hard-coding into your
 * program the solutions to the above is not acceptable.
 */

#define _XOPEN_SOURCE
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define PASS_LEN 8

void get_salt(char *, char *);
bool check_dict(char *, char *, char *);
void brut_force(char *, char *, int);
bool look_over(char *, char *, char *, int, int);

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s arg\n", argv[0]);
		return 1;
	}

	char salt[3];
	get_salt(argv[1], salt);

	if (!check_dict(argv[1], salt, "dict.txt"))
	{
		brut_force(argv[1], salt, PASS_LEN);
	}

	return 0;
}

bool check_dict(char *encripted, char *salt, char *dict)
{
	FILE *fp;

	fp = fopen(dict, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Failed open file!\n");
		return 1;
	}

	char key[128];
	char *hash;

	while (fscanf(fp, "%127s", key) == 1)
	{
		if (strlen(key) <= PASS_LEN)
		{
			hash = crypt(key, salt);
			if (strcmp(encripted, hash) == 0)
			{
				printf("%s\n", key);
				fclose(fp);
				return true;
			}
		}
	}
	
	fclose(fp);
	return false;
}

void brut_force(char *enc, char *salt, int pass_len)
{
	char *buf = malloc((pass_len + 1) * sizeof(char));

	memset(buf, 0, pass_len + 1);
	for (int len = 0; len < pass_len; len++)
	{
		if (look_over(enc, salt, buf, 0, len))
		{
			free(buf);
			return;
		}
	}

	free(buf);
}

bool look_over(char *enc, char *salt, char *key, int index, int depth)
{
	for (int i = 0; i < 95; i++)
	{
		key[index] = 32 + i;
		if (index == depth)
		{
			char *hash = crypt(key, salt);
			if (strcmp(enc, hash) == 0)
			{
				printf("%s\n", key);
				return true;
			}
		}
		else
		{
			if (look_over(enc, salt, key, index + 1, depth))
				return true;
		}
	}
	return false;
}

void get_salt(char *s, char *salt)
{
	strncpy(salt, s, 2);
	salt[2] = '\0';
}
