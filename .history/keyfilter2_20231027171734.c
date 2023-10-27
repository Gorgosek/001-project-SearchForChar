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

char* check_args(char input[], int argc)
{
    if (argc > 2)
    {
        printf("Too many arguments!");
        return CHAR_MIN;
    } else if (argc < 2){
        return " ";
    } else {
        if (strlen(input) > LINE_LENGTH)
        {
            return CHAR_MIN;
        }
        return input;

    }
}
int main(int argc, char *argv[])
{
    char *input = check_args(argv[1], argc);
    if(input == CHAR_MIN)
    {
        return EXIT_FAILURE;
    }

    bool includesChar[CHAR_SET_SIZE];
    char addresses[42][LINE_LENGTH]; // TODO: mb try *adresy[LINE_LENGTH] and then sizeof(blabla)

    int position = 0;
}