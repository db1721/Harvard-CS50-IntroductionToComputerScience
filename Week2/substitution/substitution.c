#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int valid_key(string A);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("useage: ./substitution key\n");

        return 1;
    }


        int validation = valid_key(argv[1]);
        if (validation == 1)
        {
            printf("Key must contain 26 alphabetical characters!!\n");

            return 1;
        }

            //Prompts user for plaintext
            string u_text = get_string("plaintext: ");
            printf("ciphertext: ");

            for (int c = 0, n = strlen(u_text); c < n ; c++)
            {
                //Prints non-alphabet characters unchanged
                if (u_text[c] < 'A' || (u_text[c] > 'Z' && u_text[c] < 'a') || u_text[c] > 'z')
                {
                    printf("%c", u_text[c]);
                }
                else
                {
                    for (int b = 0; b <= 25; b++)
                    {
                        if (u_text[c] == 65 + b)
                        {
                            char upper = argv[1][b];
                            int up = isupper(upper);
                            if (up == 0)
                            {
                                upper = toupper(upper);
                                printf("%c", upper);
                            }
                            if (up != 0)
                            {
                                printf("%c", upper);
                            }

                        }
                        else if (u_text[c] == 97 + b)
                        {
                            char lower = argv[1][b];
                            int low = islower(lower);
                            if (low == 0)
                            {
                                lower = tolower(lower);
                                printf("%c", lower);
                            }
                            if (low != 0)
                            {
                                printf("%c", lower);
                            }

                        }

                    }

                }

            }
            printf("\n");
            return 0;

}

//If the key input is valid and returns 0 if it is and 1 if it is not
int valid_key(string A)
{
    int input_len = strlen(A);
    if (input_len != 26)
    {
        return 1;
    }
    else
    {

        for (int g = 0; g < 26; g++)
        {
            //Checks if character is non alphabetical
            if (A[g] < 'A' || (A[g] > 'Z' && A[g] < 'a') || A[g] > 'z')
            {
                return 1;
            }
            //Scans all characters before A[g] to see if it has already been used
            for (int k = (g - 1); k >= 0; k--)
            {
                if (A[k] == A[g])
                {
                    return 1;
                }
                //Checks if different case of the same character has been used
                if (A[k] == A[g] + 32)
                {
                    return 1;
                }
                if (A[k] == A[g] - 32)
                {
                    return 1;
                }
            }
            //Scans all characters after A[g] to check if it has been used already
            for (int l = (g + 1); l < 26; l++)
            {
                if (A[l] == A[g])
                {
                    return 1;
                }
                //Checks if a different case of the same letter is used
                if (A[l] == A[g]  + 32)
                {
                    return 1;
                }
                if (A[l] == A[g] - 32)
                {
                    return 1;
                }
            }

        }
        return 0;
    }

}