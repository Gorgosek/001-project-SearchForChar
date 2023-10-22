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

//TODO: Vyresit  redundance and shit
//// MEZERU neresit, Vice Argumentu neresit, Vypisovat vse velkymi pismeny, pocitaji se vsechny znaky z ascii
//// Optimalizace a refaktorace a upresneni nazvu promennych :)

int main(int argc, char *argv[])
{
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

    for(int i = 0; i < position; i++)
    {
        enable[i] = query_next_char(addresses[i], query);
    }

    for(int i = 0; i < position; i++)
    {
        printf("%c",enable[i]);
    }

    //printf("%s\n", query);

    //for(int i = 0; i < position; i++){
    //    if(i < position)
    //    {
    //        printf("%d.:%s\n", i, addresses[i]);
    //    } else {
    //        break;
    //    }

    //}

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
