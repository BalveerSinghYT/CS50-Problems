#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int check_key_valid(string str);

int main(int argc, string argv[])
{
    if (argc == 2 && check_key_valid(argv[1]))
    {
        printf("%s\n", argv[1]);
        
        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");
        for (int i = 0; i < strlen(plaintext); i++)
        {
            char text = plaintext[i];
            if(isupper(text))
            {
                int c = ((((int)text - 65) + atoi(argv[1])) % 26) + 65;
                printf("%c",c);    
            }
            else if (islower(text))
            {
                int c = ((((int)text - 97) + atoi(argv[1])) % 26) + 97;
                printf("%c", c);
            }
            else
                printf("%c",text);
            
        }
        printf("\n");
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

int check_key_valid(string str)
{
    for (int i=0; i < strlen(str); i++)
    {
        char key = str[i];
        if (!isdigit(key))
            return 0;
    }
    return 1;
}
