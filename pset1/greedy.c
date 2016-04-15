/**
 * greedy.c
 * 
 * by Vitaliy Pisnya
 * 
 * Program first asks the user how much change is owed and then spits out the
 * minimum number of coins with which said change can be made.
 */

#include <cs50.h>
#include <stdio.h>

float get_change(void);
int dollar_to_cents(float);
int count_coins(int);

int main(void)
{
    float change;
    int cents, coins;

    printf("O hai! ");

    change = get_change();
    cents = dollar_to_cents(change);
    coins = count_coins(cents);
    
    printf("%i\n", coins);

    return 0;
}

float get_change(void)
{
    float c;

    do
    {
        printf("How much change is owed?\n");
        c = GetFloat();
    }
    while (c < 0.0f);
    
    return c;
}

int dollar_to_cents(float n)
{
    return (int) (n * 100.0f + 0.5f);
}

int count_coins(int cents)
{
    int coins = 0;

    coins += cents / 25;
    cents %= 25;
    coins += cents / 10;
    cents %= 10;
    coins += cents / 5;
    cents %= 5;
    coins += cents;
    
    return coins;
}
