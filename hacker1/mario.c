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

void print_pyramid(int h)
{
    for (int i = 1; i <= h; i++)
    {
        for (int j = h - i; j > 0; j--)
            putchar(' ');

        for (int j = 0; j < i; j++)
            putchar('#');

        printf("  ");
        
        for (int j = 0; j < i; j++)
            putchar('#');

        putchar('\n');
    }
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
