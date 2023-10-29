#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>

// CONSTANTS definition
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
} State;

void string_to_uppercase(char *str)
{
    if (str != NULL)
    {
        for (int i = 0; str[i]; i++)
            str[i] = toupper((unsigned char) str[i]); // Cast type to better prevent Seg fault
    }
}

int process_address(char address[], char prefix[], char *result, char *enableChar, int *countMatches)
{
    int prefixLength = strlen(prefix);
    int addressLength = strlen(address);
    int differenceInLength = addressLength - prefixLength;

    if(address == NULL || addressLength < prefixLength){
        return UNDEFINED;
    }
    if(differenceInLength < 0){
        *enableChar = 0;
        return NOT_FOUND;
    }
    if(strcmp(prefix, " ") == 0){
        prefixLength = 0;
    }

    if(strncasecmp(prefix, address, prefixLength) == 0)
    {
        (*countMatches)++;

        if(prefixLength == addressLength){
            strcpy(result, address);
            return FOUND;
        }
        if(*countMatches == 1){
            strcpy(result, address);
            *enableChar = address[prefixLength];
            return CHECK_FOUND;
        }
        if(*countMatches > 1){
            *enableChar = address[prefixLength];
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
    if (argc > 2){
        printf("Too many arguments!\n");
        return NULL;
    } else {
        if (strlen(argv) > LINE_LENGTH){
            printf("Argument is too long!\n");
            return NULL;
        }
        return argv;
    }
}
int main(int argc, char *argv[])
{
    // Formatting prefix for easier implementation later
    char *prefix = check_args(argv[1], argc);
    if (prefix == NULL){
        return 1;
    }

    char address[LINE_LENGTH];
    bool includesChar[CHARSET_SIZE] = {false};  // CHARSET_SIZE is set for 128 due to it being made of purely ASCII characters

    char result[LINE_LENGTH] = " ";
    char enableChar = 0;  // Helps enable characters at their given ASCII table index
    int countMatches = 0;
    int outPutCase = ERROR; // Uses enum values for clarity, represents every given outcome used for formatting output

    while (1)
    {
        // LOADS each line and processes each scenario separately using a switch statement
        if(fgets(address, sizeof(address), stdin) != NULL && outPutCase != FOUND)
        {
            string_to_uppercase(address);
            // Remove endline at each end of a string
            address[strcspn(address, "\n")] = 0;

            // sets all desired variables to then later check
            int tryProcessing = process_address(address, prefix, result, &enableChar, &countMatches);

            // UNDEFINED is used as an edge scenario no output is needed in that case
            if(tryProcessing != UNDEFINED){
                outPutCase = tryProcessing;
            }

            switch(outPutCase){
                case ENABLE_NEXT:
                    includesChar[(int)enableChar] = true;
                    break;
                case CHECK_FOUND:
                    includesChar[(int)enableChar] = true;
                    break;
                case NOT_FOUND:
                    break;
            }
        } else {

            // outPutCase's state determines all the formating
            if((outPutCase == CHECK_FOUND || outPutCase == FOUND) != 0){
                printf("Found: %s\n", result);

            } else if(countMatches > 1){
                printf("Enable: ");
                for (int i = FIRST_PRINTABLE_CHAR_INDEX; i < CHARSET_SIZE - 1; i++){
                    if(includesChar[i]){
                        printf("%c", (char)i);
                    }
                }
                printf("\n");

            } else printf("Not found\n");

            return 0;
        }
    }
}
