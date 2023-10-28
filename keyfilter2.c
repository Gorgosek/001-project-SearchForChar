#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <strings.h>

// CONSTANTS definition
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define NUM_OF_LINES 42
#define LINE_LENGTH 101
#define CHARSET_SIZE 128
#define FIRST_PRINTABLE_CHAR_INDEX 32 // Stop printing unwanted characters from the ascii table

typedef enum{
    ENABLE_NEXT,
    FOUND,
    NOT_FOUND,
    CHECK_FOUND,
    ERROR,
    UNDEFINED
} Outcome;

void string_to_uppercase(char *str)
{
    if (str != NULL)
    {
        for (int i = 0; str[i]; i++){
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

int process_address(char address[], char input[], char *result, char *cPtr, int *countMatches)
{
    if(address == NULL){
        return ERROR;
    }
    int inputLength = strlen(input);
    int addressLength = strlen(address);
    int differenceInLength = addressLength - inputLength;
    if(differenceInLength < 0){
        *cPtr = 0;
        return NOT_FOUND;
    } else if(strcmp(input, " ") == 0){
        inputLength = 0;
    }

    if(strncasecmp(input, address, inputLength) == 0)
    {
        (*countMatches)++;

        if(inputLength == addressLength){
            strcpy(result, address);
            return FOUND;
        }
        if(*countMatches == 1){
            strcpy(result, address);
            *cPtr = address[inputLength];
            return CHECK_FOUND;
        }
        if(*countMatches > 1){
            *cPtr = address[inputLength];
            strcpy(result, " ");
            return ENABLE_NEXT;
        }
    }
    return UNDEFINED;
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
    char address[LINE_LENGTH];
    bool includesChar[CHARSET_SIZE] = {false};

    char result[LINE_LENGTH] = " ";
    char c = 0;
    int countMatches = 0;
    int outPutCase = ERROR;

    while (1)
    {
        //TODO weird return
        if(fgets(address, sizeof(address), stdin) == NULL || outPutCase == FOUND) {
            if((outPutCase == CHECK_FOUND || outPutCase == FOUND) != 0){
                printf("Found: %s\n", result);
            } else if(countMatches > 1){
                printf("Enable: ");
                for (int i = FIRST_PRINTABLE_CHAR_INDEX; i < CHARSET_SIZE - 1; i++)
                {
                    if(includesChar[i]){
                        printf("%c", (char)i);
                    }
                }
                printf("\n");
            } else{
                printf("Not found\n") ;

            }
            return 0;
        } else {
            string_to_uppercase(address);
            // Remove endline at each end of a string
            address[strcspn(address, "\n")] = 0;

            int tryProcessing = process_address(address, input, result, &c, &countMatches);
            // sets all desired variables to then later check
            if(tryProcessing != UNDEFINED){
                outPutCase = tryProcessing;
            }
            switch(outPutCase){
                case ENABLE_NEXT:
                    includesChar[(int)c] = true;
                    break;
                case CHECK_FOUND:
                    includesChar[(int)c] = true;
                    break;
                case NOT_FOUND:
                    break;
                case ERROR:
                    break;
            }
        }
    }
}
