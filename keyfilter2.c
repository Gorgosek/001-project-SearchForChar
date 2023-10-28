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
#define LINE_LENGTH 101
#define CHARSET_SIZE 128

typedef enum{
    ENABLE_NEXT,
    PROCESS_FOUND,
    NOT_FOUND
} Outcome;

typedef struct{
    Outcome scenario;
    char lastChar;
    char *atAddress;
} Result;


void string_to_uppercase(char *str)
{
    if (str != NULL)
    {
        for (int i = 0; str[i]; i++)
        {
            str[i] = toupper((unsigned char)str[i]);
        }
    }
}

bool are_strings_equal(char address[], char input[])
{
    bool areEqual = strcmp(input, address) == 0;
    bool sameLength = strlen(input) == strlen(address) ? true : false;

    return areEqual && sameLength ? true : false;
}

Result process_address(char address[], char input[])
{
    int inputLastChar = (int)strlen(input);

    if (are_strings_equal(address, input))
    {
        return (Result){PROCESS_FOUND, input[inputLastChar-1], address};
    }

    int pos = 0;
    while (toupper(input[pos]) == address[pos] || input[pos] == ' ')
    {
        pos++;
        if (input[pos-1] == ' ' && pos-1 == 0)
        {
            return (Result){ENABLE_NEXT, address[pos-1], address};
        }
        else if (toupper(input[pos]) != address[pos] && pos == inputLastChar)
        {
            //TODO zakopany pes asi typico uz mi jebe
            if ((int)strlen(address) - 1 == inputLastChar)
            {
                return (Result){PROCESS_FOUND, address[pos], address};
            }
            return (Result){ENABLE_NEXT, address[pos], address};
        }
    }

    return (Result){NOT_FOUND, 0, address};
}

int output_relay(char input[])
{
    char address[LINE_LENGTH];
    Result result;
    bool includesChar[CHARSET_SIZE];

    for (int i = 0; i < CHARSET_SIZE; i++)
    {
        includesChar[i] = false;
    }

    //string_to_uppercase(input);

    int timesEnabled = 0;
    char *enabledAtAddress;

    while (fgets(address, sizeof(address), stdin) != NULL)
    {
        string_to_uppercase(address);
        // Remove endline at each string
        address[strcspn(address, "\n")] = 0;

        result = process_address(address, input);
        switch(result.scenario){
            case ENABLE_NEXT:
                includesChar[(int)result.lastChar] = true;
                timesEnabled++;
                strcpy(enabledAtAddress, result.atAddress);
                break;
            case PROCESS_FOUND:
                printf("Found: %s\n", address);
                return 0;
            break;
            case NOT_FOUND:
            break;
        }
    }

    if (result.scenario == NOT_FOUND && timesEnabled == 0)
    {
        printf("Not found\n");
        return 0;
    }
    else if(timesEnabled == 1){
        printf("Found: %s\n", enabledAtAddress);
    }
    else if (timesEnabled > 0)
    {
        char enableChar;

        printf("Enable: ");
        for (int i = 0; i < CHARSET_SIZE; i++)
        {
            if (includesChar[i])
            {
                enableChar = (char)i;
                printf("%c", enableChar);
            }
        }
        printf("\n");
    }

    return 0;
}

char *check_args(char *argv, int argc)
{
    if(argv == NULL || strcmp(argv, "") == 0 || argc < 2){
        return " ";
    }
    if (argc > 2)
    {
        printf("Too many arguments!\n");
        return NULL;
    }
    else {
        if ((int)strlen(argv) > LINE_LENGTH)
        {
            printf("Argument is too long!\n");
            return NULL;
        }
        return argv;
    }
}
int main(int argc, char *argv[])
{
    char *input = check_args(argv[1], argc);
    if (input == NULL)
    {
        return EXIT_FAILURE;
    }
    output_relay(input);
}
