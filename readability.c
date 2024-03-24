#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

float count_letters_average(int flength, string word);
float count_sentences_average(int flength, string word);

int main(void)
{
    string text = get_string("Text: ");

    int tlength = strlen(text);

    float lettersAverage = count_letters_average(tlength, text);
    float sentencesAverage = count_sentences_average(tlength, text);

    float index = 0.0588 * lettersAverage - 0.296 * sentencesAverage - 15.8;

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %.0f\n", round(index));
    }
}

float count_letters_average(int flength, string word)
{
    int lcount = 0;

    for (int i = 0; i < flength; i++)
    {
        if ((word[i] >= 65 && word[i] <= 90) | (word[i] >= 97 && word[i] <= 122))
        {
            lcount++;
        }
    }

    int scount = 0;

    for (int i = 0; i < flength; i++)
    {
        if (word[i] == ' ')
        {
            scount++;
        }
    }

    return 100.0 / (scount + 1) * (lcount);
}

float count_sentences_average(int flength, string word)
{
    int scount = 0;

    for (int i = 0; i < flength; i++)
    {
        if (word[i] == ' ')
        {
            scount++;
        }
    }

    int sencount = 0;

    for (int i = 0; i < flength; i++)
    {
        if (word[i] == '.' | word[i] == '!' | word[i] == '?')
        {
            sencount++;
        }
    }

    return 100.0 / (scount + 1) * sencount;
}
