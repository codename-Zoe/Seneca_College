#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "contactHelpers.h"

#define MAXCONTACTS 5

struct Contact contact[MAXCONTACTS] = {
    {
    { "Rick", {'\0'}, "Grimes" },
    { 11, "Trailer Park", 0, "A7A 2J2", "King City" },
    { "4161112222", "4162223333", "4163334444" }
    },{
    { "Maggie", "R.", "Greene" },
    { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
    { "9051112222", "9052223333", "9053334444" }
    },{
    { "Morgan", "A.", "Jones" },
    { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
    { "7051112222", "7052223333", "7053334444" }
    },{
    { "Sasha", {'\0'}, "Williams" },
    { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
    { "9052223333", "9052223333", "9054445555" }
    }, };

void clearKeyboard(void){
    while (getchar() != '\n');
}

void pause(void){
    printf("(Press Enter to Continue)");
    while (getchar() != '\n') {
        clearKeyboard();
    }
    printf("\n");
}

int getInt(void){
    int integer;
    char newline = 'x';

    while (newline != '\n')
    {
        scanf("%d%c", &integer, &newline);
        if (newline != '\n'){
            clearKeyboard();
            printf("*** INVALID INTEGER ***"
                " <Please enter an integer>: ");
        }
    }
    return integer;
}

int getIntInRange(int min, int max){
    int num;
    num = getInt();
    while (num < min || num > max) {
        printf("*** OUT OF RANGE ***"
        " <Enter a number between %d and %d>: ", min, max);
        num = getInt();
    }
    return num;
}

int yes(void){
    char yesNo = 'x';
    char newline = 'x';
    int returnValue = 0;

    scanf(" %c%c", &yesNo, &newline);

    while ((newline != '\n') ||
        (yesNo != 'Y' && yesNo != 'y' && yesNo != 'N' && yesNo != 'n')) {
        clearKeyboard();
        printf("*** INVALID ENTRY ***"
            " <Only (Y)es or (N)o are acceptable>: ");
        scanf(" %c%c", &yesNo, &newline);
    }
    if (yesNo == 'y' || yesNo == 'Y') {
        returnValue = 1;
    }
    else if (yesNo == 'n' || yesNo == 'N') {
        returnValue = 0;
    }
    return returnValue;
}

int menu(void){
    int menuNum;

    printf("Contact Management System\n");
    printf("-------------------------\n");
    printf("1. Display contacts\n");
    printf("2. Add a contact\n");
    printf("3. Update a contact\n");
    printf("4. Delete a contact\n");
    printf("5. Search contacts by cell phone number\n");
    printf("6. Sort contacts by cell phone number\n");
    printf("0. Exit\n");
    printf("\n");
    printf("Select an option:> ");

    menuNum = getIntInRange(0, 6);
    printf("\n");
    return menuNum;
}

void contactManagerSystem(void){
    int userSelect, keepgoing = 0;
    while (keepgoing != 1) {
        userSelect = menu();
        if (userSelect >= 1 && 6 >= userSelect) {
            switch (userSelect) {
            case 1:
                displayContacts(contact, MAXCONTACTS);
                pause();
                break;

            case 2:
                addContact(contact, MAXCONTACTS);
                pause();
                break;

            case 3:
                updateContact(contact, MAXCONTACTS);
                pause();
                break;

            case 4:
                deleteContact(contact, MAXCONTACTS);
                pause();
                break;

            case 5:
                searchContacts(contact, MAXCONTACTS);
                pause();
                break;

            case 6:
                printf("<<< Feature to sort is unavailable >>>\n\n");
                pause();
                break;

            default:
                keepgoing = 0;
            }
        }
        else {
            printf("Exit the program? (Y)es/(N)o: ");
            if (yes()) {
                printf("\n");
                printf("Contact Management System: terminated\n");
                keepgoing = 1;
            }
            else {
                printf("\n");
                keepgoing = 0;
            }
        }
    }
    return;
}

void getTenDigitPhone(char phoneNum[]){
    int i, needInput = 0;
    while (needInput == 0) {
        scanf("%[^\n]", phoneNum);
        clearKeyboard();
        for (i = 0; i < 10; i++) {
            if (isdigit(phoneNum[i]) == 0 || strlen(phoneNum) != 10) {
                printf("Enter a 10-digit phone number: ");
                scanf("%[^\n]", phoneNum);
                clearKeyboard();
            }
            else {
                needInput = 1;
            }
        }
    }
}

int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]){
    int i, index = -1;
    for (i = 0; i < size; i++){
        if (!strcmp(contacts[i].numbers.cell, cellNum)){
            index = i;
            break;
        }
    }
    return index;
}

void displayContactHeader(void){
    printf("+----------------------------------------"
           "-------------------------------------+\n");
    printf("|%30cContacts Listing%31c|\n", ' ', ' ');
    printf("+----------------------------------------"
           "-------------------------------------+\n");
}

void displayContactFooter(int count){
    printf("+----------------------------------------"
           "-------------------------------------+\n");
    printf("Total contacts: %d\n\n", count);
}

void displayContact(const struct Contact* contact){    
    if (strlen((*contact).name.middleInitial) == 0) {
        printf(" %s %s\n", (*contact).name.firstName, (*contact).name.lastName);
    }
    else {
        printf(" %s %s %s\n", (*contact).name.firstName,
        (*contact).name.middleInitial, (*contact).name.lastName);
    }
    printf("%4cC: %-10s%3cH: %-10s%3cB: %-10s\n", ' ', 
    (*contact).numbers.cell,' ', (*contact).numbers.home,
    ' ', (*contact).numbers.business);
    printf("%7c%d %s, ", ' ', (*contact).address.streetNumber, (*contact).address.street);
    if ((*contact).address.apartmentNumber > 0) {
        printf("Apt# %d, ", (*contact).address.apartmentNumber);
    }
    printf("%s, %s\n", (*contact).address.city, (*contact).address.postalCode);
}

void displayContacts(const struct Contact contacts[], int size){
    int i, count = 0;
    displayContactHeader();
    for (i = 0; i < size; i++) {
        if (strlen(contacts[i].numbers.cell) > 0) {
            displayContact(&contacts[i]);
            count++;
        }
    }
    displayContactFooter(count);
}

void searchContacts(const struct Contact contacts[], int size){
    int index;
    char cellNum[11] = { 0 };
    
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(cellNum); 
    index = findContactIndex(contacts, size, cellNum);

    if (index > -1) {
        printf("\n");
        displayContact(&contact[index]);
        printf("\n");
    }
    else {
        printf("*** Contact NOT FOUND ***\n\n");
    }
}

void addContact(struct Contact contacts[], int size){
    int i, keepgoing = 1, count = 0;
    while (keepgoing == 1) {
        for (i = 0; i < size; i++) {
            if (strlen(contacts[i].numbers.cell) == 0) {
                getContact(&contacts[i]);
                printf("--- New contact added! ---\n\n");
                keepgoing = 0;
            }
            else {
                count++;
            }
        }
        if (count == MAXCONTACTS) {
            printf("*** ERROR: The contact list is full! ***\n\n");
            keepgoing = 0;
        }
    }
 }

void updateContact(struct Contact contacts[], int size){
    char cellNum[11] = { 0 };
    int index;

    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(cellNum);
    index = findContactIndex(contacts, size, cellNum);

    if (index > -1) {
        printf("\n");
        printf("Contact found:\n");
        displayContact(&contacts[index]);
        printf("\n");    
        printf("Do you want to update the name? (y or n): ");
        if (yes()) {
            getName(&contacts[index].name);
        }

        printf("Do you want to update the address? (y or n): ");
        if (yes()) {
            getAddress(&contacts[index].address);
        }

        printf("Do you want to update the numbers? (y or n): ");
        if (yes()) {
            getNumbers(&contacts[index].numbers);
        }
        printf("--- Contact Updated! ---\n\n");
    }
    else {
        printf("*** Contact NOT FOUND ***\n\n");
    }
}

void deleteContact(struct Contact contacts[], int size){
    char cellNum[11] = { 0 };
    int index;

    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(cellNum);
    index = findContactIndex(contacts, size, cellNum);
    
    if (strcmp(cellNum, contacts[index].numbers.cell) == 0) {
        printf("\n");
        printf("Contact found:\n");
        displayContact(&contacts[index]);
        printf("\n");
        printf("CONFIRM: Delete this contact? (y or n): ");
        if (yes()) {
            printf("--- Contact deleted! ---\n");
            *contacts[index].numbers.cell = '\0';
        }
    }
    else {
        printf("*** Contact NOT FOUND ***\n");
    }
    printf("\n");
}