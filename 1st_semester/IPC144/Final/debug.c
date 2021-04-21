/*
Example Execution:

Enter a word, synonym, and related factor (example: Structure|House|1)
Enter 'Q' by itself to exit (example: Q)

Add to thesaurus [word|synonym|factor]: Structure|House|1
Add to thesaurus [word|synonym|factor]: Vehicle|Car|1
Add to thesaurus [word|synonym|factor]: Structure|Building|1
Add to thesaurus [word|synonym|factor]: Vehicle|Truck|1
Add to thesaurus [word|synonym|factor]: Feline|Tiger|2
Add to thesaurus [word|synonym|factor]: error

!!! Invalid input !!!
Enter a word, synonym, and related factor (example: Structure|House|1)
Enter 'Q' by itself to exit (example: |)

Add to thesaurus [word|synonym|factor]: Structure|Shed|3
Add to thesaurus [word|synonym|factor]: Q

Thesaurus Data:
 1) Structure
         1. House (Factor:1)
         2. Building (Factor:1)
         3. Shed (Factor:3)
 2) Vehicle
         1. Car (Factor:1)
         2. Truck (Factor:1)
 3) Feline
         1. Tiger (Factor:2)

Application exiting... Goodbye!

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SZ 20
#define MAX_LINE 50
#define MAX_ENTRIES 100

struct Synonym
{
    char name[MAX_SZ + 1];
    int relatedFactor; // 1=highly | 2=moderately | 3=loosely
};

struct WordInfo
{
    char word[MAX_SZ + 1];
    struct Synonym synonyms[MAX_ENTRIES];
    int synonymCount;
};

void clearInputBuffer(void)
{
    while (getchar() != '\n'); 
}

int add(const char word[], const char synonym[], const int relatedFactor, struct WordInfo thesaurus[], int arrSize){
    int addedWord = 0, found = 0, i;

    // lookup for existing word
    for (i = 0; i < arrSize && !found; i++) {
        // found match
        if (!strcmp(word, thesaurus[i].word))         {
            strcpy(thesaurus[i].synonyms[thesaurus[i].synonymCount].name, synonym);
            thesaurus[i].synonyms[thesaurus[i].synonymCount].relatedFactor = relatedFactor;
            thesaurus[i].synonymCount++;
            found = 1; // toggle exit from loop
        }
        // not found and Empty slot: add to thesaurus.word array | set thesaurus.synonymCount to 1 | set result to 1
        else if (thesaurus[i].word[0] == '\n'){ 
            addedWord = 1; // toggle return value to 1 (added)
            found = 1;     // toggle exit from loop
            strcpy(thesaurus[i].word, word);
            strcpy(thesaurus[i].synonyms[relatedFactor].name, synonym);
            thesaurus[i].synonyms[0].relatedFactor = relatedFactor;
            thesaurus[i].synonymCount++; 
        }
    }
    return addedWord;
}

int main(void){
    struct WordInfo thesaurus[MAX_ENTRIES] = { { {0} } };
    int i, j, quitting, numEntries = 0, valid;
    char word[MAX_SZ + 1], synonym[MAX_SZ + 1];
    int relatedFactor;

    // -----------------------------
    // Instructions
    printf("Enter a word, synonym, and related factor (example: Structure|House|1)\n");
    printf("Enter 'Q' by itself to exit (example: Q)\n\n");

    do {
        // -----------------------------
        // Prompt:
        printf("Add to thesaurus [word|synonym|factor]: ");
        valid = scanf("%20[^|\n]|%20[^|]|%d", word, synonym, &relatedFactor);
        clearInputBuffer();
        quitting = (valid = 1 && strcmp("Q", word) == 0); 
        if (quitting) {
            // -----------------------------
            // Display the thesaurus
            printf("\n");
            printf("Thesaurus Data:\n");
            for (i = 0; i < numEntries; i++)
            {
                printf("%2d) %s\n", i + 1, thesaurus[i].word);
                for (j = 0; j < thesaurus[i].synonymCount; j++)
                {
                    printf("\t%2d. %s (Factor:%d)\n", j + 1, thesaurus[i].synonyms[j].name, thesaurus[i].synonyms[j].relatedFactor);
                }
            }
            printf("\n");
        }
        else if (!quitting) {
            // -----------------------------
            // If new word was added, returns 1, otherwise 0
            numEntries += add(word, synonym, relatedFactor, thesaurus, MAX_ENTRIES);
        }
        else {
            // -----------------------------
            // Show error message
            printf("\n");
            printf("!!! Invalid input !!!\n");
            printf("Enter a word, synonym, and related factor (example: Structure|House|1)\n");
            printf("Enter 'Q' by itself to exit (example: |)\n\n");
        }

    } while (!quitting);

    // -----------------------------
    // Show goodbye
    printf("Application exiting... Goodbye!\n");
    return 0;
}