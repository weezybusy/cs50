/**
 * credit.c -- program prompts the user for a credit card number and then
 * reports (via printf) whether it is a valid American Express, MasterCard,
 * or Visa card number, per the definitions of each’s format herein.
 * 
 *  American Express:
 *      - has 15-digit numbers
 *      - all numbers start with 34 or 37
 * 
 *  MasterCard:
 *      - has 16-digit numbers
 *      - all numbers start with 51, 52, 53, 54, or 55
 * 
 *  Visa:
 *      - has 13- and 16-digit numbers
 *      - all numbers start with 4
 * 
 *  Checksum algorithm:
 * 
 *      1. Multiply every other digit by 2, starting with the number’s
 *         second-to-last digit, and then add those products' digits together.
 * 
 *      2. Add the sum to the sum of the digits that weren’t multiplied by 2.
 * 
 *      3. If the total’s last digit is 0 (or, put more formally, if the total
 *         modulo 10 is congruent to 0), the number is valid!
 * 
 * Author: Vitaliy Pisnya
 * Date: April 8, 2016
 */

#include <stdio.h>
#include <stdbool.h>
#include "cs50.h"

typedef unsigned long long ull;
typedef unsigned int ui;

ull get_number(void);
ui count_digits(ull);
ui get_head_num(ull, ui);
ull power(ui, ui);
ui sum(ull, ui);
bool validate_sum(ui);

int main(void)
{
    ull card_number;
        
    ui digits,
       head_num,
       total_sum;
    bool checksum;
    
    card_number = get_number();
    digits = count_digits(card_number);
    head_num = get_head_num(card_number, digits);
    total_sum = sum(card_number, digits);
    checksum = validate_sum(total_sum);

    if (digits == 15 && (head_num == 34 || head_num == 37) && checksum)
    {
        printf("AMEX\n");
    }
    else if (digits == 16 && (head_num > 50 && head_num < 56) && checksum)
    {
        printf("MASTERCARD\n");
    }
    else if ((digits == 13 || digits == 16) && (head_num / 10 == 4) && checksum)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}

ull get_number(void)
{
    ull n;

    do
    {
        printf("Number: ");
        n = GetLongLong();
    }
    while (n < 1);
    
    return n;
}
    
ui count_digits(ull n)
{
    ui count = 0;

    while (n != 0)
    {
        n /= 10;
        count++;
    }

    return count;
}

ui get_head_num(ull n, ui d)
{
    return n / power(10, d - 2);
}

ull power(ui n, ui d)
{
    ull val = 1;

    for (ui i = 1; i <= d; i++)
    {
        val *= n;
    }
    
    return val;
}

ui sum(ull n, ui d)
{
    ui sum1 = 0,
       sum2 = 0;

    for (ui i = d; i > 0; i--)
    {
        ull t = power(10, i - 1);
        ui digit = n / t;
        n %= t;
        
        if (i % 2 == 0)
        {
            digit *= 2;

            if (digit / 10 > 0)
                digit = ((digit / 10) + (digit % 10));
            
            sum1 += digit;
        }
        else
        {
            sum2 += digit;
        }
    }

    return sum1 + sum2;
}

bool validate_sum(ui n)
{
    return n % 10 == 0;
}