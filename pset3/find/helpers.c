/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (values[middle] == value)
        {
            return true;
        }
        else if (values[middle] < value)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int swaps = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (values[j] > values[j + 1])
            {
                int tmp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = tmp;
                swaps++;
            }
        }
        if (!swaps)
        {
            break;
        }
    }
    return;
}