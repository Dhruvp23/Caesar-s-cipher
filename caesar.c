#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string digit);
void rotate(int d);


int main(int argc, string argv[])
{

    if( argc == 2)                            //checking command-line arguments
    {
        bool temp = only_digits(argv[1]);
        int k = atoi(argv[1]);              //Key for cipher encryption frm string to int

        if (temp == true)
        {
            rotate(k);                  //rotate encryption function
        }
        else
        {
            printf("Usage: ./caesar key \n");
            return 1;
        }
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key \n");       //invalid input
        return 1;
    }
}

void rotate(int d)
{
    string plaintext = get_string("plainText:  ");                     //Get Plaintext
    int n = strlen(plaintext);                                         // Length of String
    char cipher[26] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};                  // ASCII Chart
    int index;
    char out[n];

    for( int i = 0; i <= n; i++)
    {
        if (plaintext[i] >= 65 && plaintext[i] <= 90)                    //For UpperCase Letter
        {
            int Pi = plaintext[i] - 65;
            index = (Pi + d) % 26;          //Cipher Formula
            out[i] = cipher[index];
        }
         else if (plaintext[i] >= 97 && plaintext[i] <= 122)           //For LowerCase Letter
        {
            int Pi = plaintext[i] - 97;
            index = (Pi + d) % 26;
            out[i] = cipher[index] + 32;
        }
        else                                                            //For Special Characters
        {
            out[i] = plaintext[i];
        }
    }
    printf("ciphertext: %s\n", out);
}




bool only_digits(string digit)
{
    int count = 0;
    for( int i = 0; i < strlen(digit); i++)
    {
    if (isdigit(digit[i]))            //isdgit check any digits in string char/char
        {
            count = count +1;
        }
        else
        {
            return 0;
        }
    }

    if (count == strlen(digit))
    {
        return true;
    }
    else
    {
        return false;
    }

}