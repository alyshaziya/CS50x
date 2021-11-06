#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int main(void)
{
    // declaring variables
    string s = get_string("Text: ");
    int letters = 0;
    int words = 1;
    int sentences = 0;


    for (int i = 0; i < strlen(s); i++)

    {
        // check for alphanumeric characters
        if isalpha(s[i])
        {
            letters++;
        }
        // check for whitespace, tab, newline
        if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
        {
            words++;
        }
        // check for end of sentences
        if (s[i] == '.' || s[i] == '?' || s[i] == '!')
        {
            sentences++;
        }
    }
    // assign int to float, calculate coleman index
    float w = words;
    float L = letters / w * 100;
    float S = sentences / w * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int idx = round(index);

    // print grades
    if (idx >= 1 && idx <= 16)
    {
        printf("Grade %i\n", idx);
    }
    else
    {
        if (idx >= 16)
        {
            printf("Grade 16+\n");
        }
        if (idx < 1)
        {
            printf("Before Grade 1\n");
        }
    }

}