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

    //Change to UPPERCASE for desired output
    toupper(address);
    toupper(input);

    // Readability
    int inputLength = (int)strlen(input);
    int addressLength = (int)strlen(address);

    if(inputLength > addressLength){
        return CHAR_MAX;
    }

    bool sameLength = inputLength == addressLength ? true : false;
    int upperBound = inputLength < addressLength ? inputLength : inputLength-1; 

    for(int i = 0; i <= upperBound; i++)
    {
        // Returns the first dissimilar UPPERCASE char from string address based on input
        if(input[i] != address[i] && (i != 0 && input[i-1] == address[i-1]))
        {
            return address[i];

        } else if(i == 0 && input == " "){

            return address[i];
        }
    }

    // Address == input
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

    // Array representing which ascii characters are included in the result 
    bool includesChar[CHAR_SET_SIZE];
    for(int i = 0; i < CHAR_SET_SIZE; i++){
        includesChar[i] = false;
    }

    char addresses[42][LINE_LENGTH]; // TODO: mb try *adresy[LINE_LENGTH] and then sizeof(blabla)

    int position = 0;
    char temp[100];
    char result;

    while(1)
    {
        if(fgets(temp, sizeof(temp), stdin) == NULL){
            break;
        }
        
        // Remove endline at each string
        temp[strcspn(temp, "\n")] = 0;
        result = query_next_char(temp, input);
        includesChar[(int)result] == true;
        printf("%d + %c\n", position, result);
    }

    char enableChars[128];
    for(int i = 0; i < CHAR_SET_SIZE; i++){
        if(includesChar[i])
        enableChars[i] += (char)i;

    }
    printf("Enable: %128s\n", enableChars);


}