#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// CONSTANTS definition
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define NUM_OF_LINES 42
#define LINE_LENGTH 100
#define CHAR_SET_SIZE 128

void stringToupper(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        str[i] = toupper(str[i]);
    }
}
char query_next_char(char *address, char *input)
{

    // Change to UPPERCASE for desired output
    stringToupper(address);
    stringToupper(input);

    // Address == input
    // FOUND
    if (strcmp(input, address))
    {
        return CHAR_MAX;
    }
    int pos = 0;
    while (pos < (int)strlen(address))
    {
        if (input[pos] != address[pos])
        {
            return address[pos];
        }
        pos++;
    }
    // int upperBound = inputLength < addressLength ? inputLength : inputLength-1;

    // for(int i = 0; i <= upperBound; i++)
    //{
         // Returns the first dissimilar UPPERCASE char from string address based on input
    //     if(input[i] != address[i] && (i != 0 && input[i-1] == address[i-1]))
    //     {
    //         return address[i];

    //    } else if(i == 0 && input == " "){

    //        return address[i];
    //    } else{

    //        return CHAR_MIN;
    //    }
    //}

    return CHAR_MIN;
}

char *check_args(char input[], int argc)
{
    if (argc > 2)
    {
        printf("Too many arguments!\n");
        return NULL;
    }
    else if (argc < 2)
    {
        return " ";
    }
    else
    {
        if ((int)strlen(input) > LINE_LENGTH)
        {
            printf("Argument is too long!\n");
            return NULL;
        }
        return input;
    }
}
int main(int argc, char *argv[])
{
    char *input = check_args(argv[1], argc);
    if (input == NULL)
    {
        return EXIT_FAILURE;
    }
    printf("%s\n", input);

    // Array representing which ascii characters are included in the result
    bool includesChar[CHAR_SET_SIZE];
    for (int i = 0; i < CHAR_SET_SIZE; i++)
    {
        includesChar[i] = false;
    }


    char temp[100];
    char result;
    bool equals;

    while (1)
    {
        equals = false;
        if (fgets(temp, sizeof(temp), stdin) == NULL)
        {
            break;
        }

        // Remove endline at each string
        temp[strcspn(temp, "\n")] = 0;
        result = query_next_char(temp, input);
        if (result != CHAR_MIN)
        {
            includesChar[(int)result] = true;
        }
        else if (result == CHAR_MAX)
        {
            equals = true;
        }
        printf("%c\n", result);
    }

    // kdyz je to jen o jedno pismenko vypsat found: NAZEV
    char enableChar;
    printf("Enable: ");
    for (int i = 0; i < CHAR_SET_SIZE; i++)
    {
        if (includesChar[i])
        {
            enableChar = (char)i;
            printf("%c", enableChar);
        }
    }
    printf("\n");
}