//Read Documentation below

#include<stdio.h>
#include<cs50.h>
#include<math.h>

int cardlen(long cardno);
void Card_Type(int length, long cardno);
long power(int x, int y);
bool checksum(long ccn);
int main(void)
{
    long number = 0;
    int length = 0;
    do
    {
        number = get_long("Number: ");
    }
    while (number < 0);
    
    length = cardlen(number);
    if ((length == 13 || length == 14 || length == 15 || length == 16) && checksum(number))
    {
        Card_Type(length, number);
    }
    else
    printf("INVALID\n");
}

int cardlen(long cardno)
{
    if (cardno >= power(10,15)) return 16;
    if (cardno >= power(10,14)) return 15;
    if (cardno >= power(10,13)) return 14;
    if (cardno >= power(10,12)) return 13;
    else
    {
        return 0;
    }
}

void Card_Type(int length, long cardno)
{
    if (length != 0)
    {
        //visa card
        if((cardno/power(10,15))==4 || cardno/power(10,14) == 4 || cardno/power(10,13) == 4)
        printf("VISA\n");
        else if(cardno/power(10,14)==51 || cardno/power(10,14)==52 || cardno/power(10,14)==53 || cardno/power(10,14)==54 || cardno/power(10,14)==55)
        printf("MASTERCARD\n");
        else if(cardno/power(10,13)==34 || cardno/power(10,13)==35 || cardno/power(10,13)==36 || cardno/power(10,13)==37)
        printf("AMEX\n");
        else 
        printf("INVALID\n");
    }
}

bool checksum(long ccn)
{
    int sum = 0;
    for(int i=0; ccn!=0; i++, ccn = ccn/10)
    {
        if(i%2 ==0)
            sum = sum + (ccn%10);
        else
        {
            int digit = 2*(ccn%10);
            sum = sum + (digit / 10 + digit % 10);
        }
    }
    return (sum % 10) == 0;
}

long power(int x, int y)
{
    long d = x;
    for(int i=1; i<y; i++)
    {
         d = d * x;
    }
    return d;
}







/*credit cards
      Card Type      |   Start  | Length(digit)
    ___________________________________________
    American Express | 34 or 37 |   15
    Master card      | 51 to 55 |   16
    Visa card        |  4       |   13-16
    ___________________________________________

    Method to find Checksum
    !. Multiply every other digit by 2, from second last digit & add those products digit together.
    2. Add the sum of product to the sum of digits that weren't multiplied by 2.
    3. If the last digit of end result is 0, the number is valid.
*/
