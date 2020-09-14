#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

int main()
{
    //Functions used
    float count_letters(string w);
    float count_words(string w);
    float count_sentences(string w);

    //****Main****

    //Get user input
    string s = get_string("Text: ");
    
    
    //printf("%i Letter(s)\n", count_letters(s));
    //printf("%i Word(s)\n", count_words(s));
    //printf("%i Sentence(s)\n", count_sentences(s));
    
    float word = count_words(s);
    float letter = count_letters(s);
    float sentence = count_sentences(s);

    //Gets the average number of letters per 100 words

    //Gets the average number of senteces per 100 words

    /*index = 0.0588 * L - 0.296 * S - 15.8
    where L(avgL) is the average number of letters per 100 words in the text,
    and S (avgS) is the average number of sentences per 100 words in the text.*/

    float index = 0.0588 * (100 * letter / word) - 0.296 * (100 * sentence / word) - 15.8;
    float grade = round(index);
    
    if(grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 1 && grade < 16)
    {
        printf("Grade %i\n", (int)grade);
    }
    else
    {
        printf("Grade 16+\n");
    }
}

//****Functions****
//Count the amount of characters
float count_letters(string w)
{
    int count = 0;
    for(int i = 0, sl = strlen(w); i <= sl; i++)
    {
        if(w[i] >= 'A' && w[i] <= 'z')
        {
            count++;
        }
    }
    return count;
}

//Count the amount of words
float count_words(string w)
{
    int count = 1;
    for(int i = 0, sl = strlen(w); i <= sl; i++)
    {
        if(w[i] == 32)
        {
            count++;
        }
    }
    return count;
}

//Count the number of sentences
float count_sentences(string w)
{
    int count = 0;
    for(int i = 0, sl = strlen(w); i <= sl; i++)
    {
        if(w[i] == 33 || w[i] == 46 || w[i] == 63)
        {
            count++;
        }
    }
    return count;
}
