#include<stdio.h>
#include<cs50.h>
#include<math.h>

int main(void)
{
    int count = 0;
    int coins = 0;
    // quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢)
    float dollar;
    
    //Wrong input, prompting again & again
    do
    {
        dollar = get_float("How much change is owed? \n");
    }
    while (dollar <= 0 || dollar > 1000);
    
    printf("Owed: $%.2f\n", dollar);
    
    //converting dollars into cents
    float cents = roundf(dollar * 100);
    
    printf("Total cents = %f\n", cents);
    
    //conditions for selection of best coin
    while (cents != 0)
    {
        if (cents >= 25)
        { 
            count = count + 25;
            cents = cents - 25;
        }
        else if (cents > 9 && cents < 25)
        {
            count = count + 10;
            cents = cents - 10;
        }
        else if (cents > 4 && cents < 10)
        {
            count = count + 5;
            cents = cents - 5;
        }
        else 
        {
            count = count + 1;
            cents = cents - 1;
        }
        coins++;
    }
    printf("Number of coins to pay: %i\n", coins);
}