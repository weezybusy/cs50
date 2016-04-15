/**
 * mario.c
 * 
 * by Vitaliy Pisnya
 * 
 * Prints a half-pyramid using hashes (#) for blocks.
 */

#include <stdio.h>
#include <cs50.h>

int get_height(void);
void print_pyramid(int);

int main(void)
{
    int height;
    
    height = get_height();
    print_pyramid(height);

    return 0;
}

int get_height(void)
{
    int h;

    do
    {
        printf("Height: ");
        h = GetInt();
    }
    while (h < 0 || h > 23);
    
    return h;
}

void print_pyramid(int h)
{
    for (int i = 1; i <= h; i++)
    {
        for (int j = h - i; j > 0; j--)
            printf(" ");

        for (int j = 0; j < i + 1; j++)
            printf("#");
            
        printf("\n");
    }
}
