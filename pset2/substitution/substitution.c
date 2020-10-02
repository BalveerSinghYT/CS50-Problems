#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int validate_key(string argv);
void encrypt_message(string argv, string ptext);

//---------------------- MAIN ----------------------
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    
    if(validate_key(argv[1]) == 1)
        return 1;
    
    string plaintext = get_string("plaintext: ");
    string ciphertext;
    printf("ciphertext: ");
    encrypt_message(argv[1], plaintext);
    
    return 0;
}

//---------------------- ENCRYPT MESSAGE ----------------------
void encrypt_message(string argv, string ptext)
{
    int note;
    int ptext_size = strlen(ptext);
    string encrypt = "h";
    char text;
    string alpha_array = {"abcdefghijklmnopqrstuvwxyz"};
    string Alpha_Array = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    for (int i=0; i<ptext_size; i++)
    {
        for (int j=0; j<26; j++)
        {
            if (ptext[i] == (char) 97 + j || ptext[i] == (char) 65+j) // check at what place character is present in real alpha_array
            {
                if(isupper(ptext[i]))
                    printf("%c", toupper(argv[j]));
                    
                else if(islower(ptext[i]))
                    printf("%c", tolower(argv[j]));
            }
            
            else if (ptext[i] == (char)48+j )
            {
                if(j>10)
                {
                    break;
                }
                printf("%c", ptext[i]);
            }
        }
        
        if (ptext[i] == ',' || ptext[i] == ' ')
            printf("%c", ptext[i]);

        else if (ptext[i] == '!' || ptext[i] == '.')
            printf("%c", ptext[i]);
            
    }
    printf("\n");
    
}

//---------------------- VALIDATE KEY ----------------------
int validate_key(string argv)
{
    int count = 0;
    int repeat = 0;

    //**** Covert all chracter to upper ****
    int k=0;
    char ch;
    char str[26];
    strcpy(str,argv);
    //printf("str= %s\n", str);
    char s[26];
    while (k<27)
    {
        ch = str[k];
        s[k] = (char)toupper(ch);
        k++;
    }
    //---- **** ----
    
    //printf("%s\n", s);
    for (int i=0; i<26; i++)
    {
        for (int j=0; j<26; j++) // compare each chracter to all capital & small alphabets
        {
            if ((int)argv[i] == 65+j || (int)argv[i] == 97+j)
            {
                count++;        // count help us to idetifiy all character are alphabets
            }
            
        }
        //printf("%i\n", count);

        for (int j=0; j<26; j++) // check how many times a chracter is repeating
        {
            if((int)s[i] == s[j])
            {
                repeat++;
                if(repeat>1)
                {
                    printf("Key chracter should not be repeated\n");
                    return 1;
                }
            }
        }
        repeat = 0;
    }

    if(count == 26)
        return 0;

    else
    {
        printf("Key should not contain any numeric chracter\n");
        return 1;
    }
}
