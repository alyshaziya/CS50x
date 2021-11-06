#include<cs50.h>
#include<stdio.h>
#include <math.h>

int main(void)
{
    float change;
    int cents;
    int counter = 0;

// prompt user for change amount
    do
    {
        change = get_float("How much change is owed?: ");
    } 
    while (change < 0);

// convert float to int
    cents = round(change * 100);

// quarter 
    while (cents >= 25)
    {
        counter++;
        cents -= 25;
    }
// dimes
    while (cents >= 10)
    {
        counter++;
        cents -= 10;    
    }
// nickles
    while (cents >= 5)
    {
        counter++;
        cents -= 5; 
    }
//pennies    
    while (cents >= 1)
    {
        counter++;
        cents -= 1;
    }
    printf("%i\n", counter);
    
}