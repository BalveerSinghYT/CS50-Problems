#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int height;
    int c = 0;
    
    do
    {
        height = get_int("Height: ");
        
    } 
    while (height > 8 || height < 1);
    
    for (int i = 1; i <= height; i++)   //for the rows
    {
        for (int j = (height - i); j > 0; j--)  //for printing space 
        {
            printf(" ");
        }
        
        for (int k = 0; k < i; k++)     //for printing # in columns
        {
            printf("#");
        }
        
        for (int j = 2; j > 0; j--)  //for printing space 
        {
            printf(" ");
        }
        
        for (int k = 0; k < i; k++)     //for printing # in columns
        {
            printf("#");
        }
        printf("\n");
    }
}

