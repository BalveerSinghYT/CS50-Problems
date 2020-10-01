#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<math.h>

int count_letter(string input, int length);
int count_word(string input, int length);
int count_sentance(string input, int length);
float grade(float L, float S);

int main(void)
{
    float avg_L = 0;
    float avg_S = 0;
    int output = 0;
    string text = get_string("Text: ");
    int len = strlen(text); //   n is the length of string
    //count word, setences
    int L = count_letter(text, len);
    int W = count_word(text, len);
    int S = count_sentance(text, len);
    /*
    printf("Letters: %i\n", L);
    printf("Words: %i\n", W);
    printf("Sentencs: %i\n", S);
    */  
    avg_L = ((float)L / (float)W) * 100;
    avg_S = ((float)S / (float)W) * 100;

    output = roundf(grade(avg_L, avg_S));
    if (output <= 1)
        printf("Before Grade 1\n");
    else if (output >= 16)
        printf("Grade 16+\n");
    else
        printf("Grade %i\n", output);
    
}

int count_letter(string input, int length)
{
    int countl = 0;
    for (int i = 0; i <= length; i++)
    {
        if (((int)input[i] <= 90 && (int)input[i] >= 65) || ((int)input[i] >= 96 && (int)input[i] <= 122))
            countl++;
        else
            continue;
    }
    return countl;
}

int count_word(string input, int length )
{
    int countw = 1;
    for (int i = 0; i <= length; i++)
    {
        if (input[i] == ' ' && input[i+1] != ' ')
            countw++;
        else
            continue;
            
    }
    return countw;
}

int count_sentance(string input, int length)
{
    int counts = 0;
    for (int i = 0; i <= length; i++)
    {
        if (input[i] == '.' || input[i] == '!'|| input[i] == '?')
            counts++;
        else
            continue;
    }
    return counts;
}
float grade(float L, float S)
{
    float index = 0;                //This was the mistake float instead of int
    index = 0.0588 * L - 0.296 * S - 15.8;
    return index;
}