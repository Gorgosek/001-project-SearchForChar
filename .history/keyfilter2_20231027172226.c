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

char query_next_char(char address[LINE_LENGTH], char *input){

    toupper(address);
    toupper(input);
    //char solution;
    int inputLength = (int)strlen(input);
    int addressLength = (int)strlen(address);



    if(inputLength > addressLength){
        return CHAR_MAX;
    }

    bool sameLength = inputLength == addressLength ? true : false;
    int upperBound = inputLength < addressLength ? (int)inputLength : (int)inputLength-1; 

    for(int i = 0; i <= upperBound; i++)
    {
        if(tolower(input[i]) != tolower(address[i]) && (i != 0 && tolower(input[i-1]) == tolower(address[i-1])))
        {
            return toupper(address[i]);
        }
    }

    if(sameLength){
        return CHAR_MIN;
    }

    return 0;
}


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
    char temp[100];
    while(1)
    {
        if(fgets(temp, sizeof(temp), stdin) == NULL){
            break;
        }
        
        // Remove endline at each string
        temp[strcspn(addresses[position], "\n")] = 0;

        printf("%d\n", position);
    }
}