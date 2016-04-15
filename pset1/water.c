/**
 * water.c
 * 
 * by Vitaliy Pisnya
 * 
 * Program prompts the user for the length of his or her shower in minutes
 * (as a positive integer) and then prints the equivalent number of bottles of 
 * water (as an integer).
 */
 
#include <stdio.h>
#include "cs50.h"

int get_minutes(void);
int count_bottles(int);

int main(void)
{
    int minutes;
    int bottles;

    minutes = get_minutes();
    bottles = count_bottles(minutes);
    
    printf("bottles %d\n", bottles);

    return 0;
}

int get_minutes(void)
{
    int m;

    do
    {
        printf("minutes: ");
        m = GetInt();
    }
    while (m < 1);
    
    return m;
}
    
int count_bottles(int m)
{
    return m * 1.5 * 128 / 16;
}
