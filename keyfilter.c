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

char query_next_char(char address[LINE_LENGTH], char *query);

//TODO: Vyresit  redundance and sort shit
//// MEZERU neresit, Vice Argumentu neresit, Vypisovat vse velkymi pismeny, pocitaji se vsechny znaky z ascii
//// Optimalizace a refaktorace a upresneni nazvu promennych :)

int main(int argc, char *argv[])
{
    bool isChar[256];
    char *query = "";
    if(argc > 2)
    {
        printf("Too many arguments!");
        return EXIT_FAILURE;
    }
    if(argc == 2){
        query = argv[1];
    }

    // VARIABLES
    char addresses[42][LINE_LENGTH]; // TODO: mb try *adresy[LINE_LENGTH] and then sizeof(blabla)
    // (void) argv;

    int position = 0;

    while(1)
    {
        if(fgets(addresses[position], sizeof(addresses[0]), stdin) == NULL){
            break;
        }
        
        // Remove endline at each string
        addresses[position][strcspn(addresses[position], "\n")] = 0;

        position++;
        printf("%d\n", position);
    }

    char enable[100];
    char testOut;

    for(int i = 0; i < position; i++)
    {
        testOut = query_next_char(addresses[i], query);
        if(testOut != 0 && testOut != CHAR_MIN && testOut != CHAR_MAX)
        {
            enable[i] = testOut;
        }
    }
    // Finishes the char
    enable[position] = '\0';
    for(int i = 0; i < (int)strlen(enable); i++){
       if(enable[i]){
            isChar[(int)enable[i]] = true;
        }
        
    }
    char reTypeLetter;
    for(int i = 0; i < 256; i++){
        if(isChar[i] == true){
            reTypeLetter = (char)i;
            printf("%c", reTypeLetter);
        }
    }

 //   for(int i = 0; i < position; i++)
 //   {
 //       printf("%c",enable[i]);
 //   }
 //       printf("\n");

    return EXIT_SUCCESS;
}



char query_next_char(char address[LINE_LENGTH], char *query){

    //char solution;
    int queryLength = (int)strlen(query);
    int addressLength = (int)strlen(address);

    if(queryLength > addressLength){
        return CHAR_MAX;
    }

    bool sameLength = queryLength == addressLength ? true : false;
    int upperBound = queryLength < addressLength ? (int)queryLength : (int)queryLength-1; 

    for(int i = 0; i <= upperBound; i++)
    {
        if(tolower(query[i]) != tolower(address[i]) && (i != 0 && tolower(query[i-1]) == tolower(address[i-1])))
        {
            return toupper(address[i]);
        }
    }

    if(sameLength){
        return CHAR_MIN;
    }

    return 0;
}
