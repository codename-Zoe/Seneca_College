#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"

void getName(struct Name* name)
{
    printf("Please enter the contact's first name: ");
    scanf("%30[^\n]", name->firstName);
    clearKeyboard();

    printf("Do you want to enter a middle initial(s)? (y or n): ");

    if (yes()) {
        printf("Please enter the contact's middle initial(s): ");
        scanf("%6[^\n]", name->middleInitial);
        clearKeyboard();
    }
    else {
        int i;
        for (i = 0; i < 10; i++) {
            name->middleInitial[i] = '\0';
        }
    }
    printf("Please enter the contact's last name: ");
    scanf("%35[^\n]", name->lastName);
    clearKeyboard();
}

void getAddress(struct Address* address)
{
    printf("Please enter the contact's street number: ");
    address->streetNumber = getInt();
    if (address->streetNumber < 0) {
        printf("*** INVALID STREET NUMBER ***"
            " <must be a positive number>: ");
        address->streetNumber = getInt();
    }
    printf("Please enter the contact's street name: ");
    scanf("%40[^\n]", address->street);
    clearKeyboard();

    printf("Do you want to enter an apartment number? (y or n): ");

    if (yes()) {
        printf("Please enter the contact's apartment number: ");
        address->apartmentNumber = getInt();
        if (address->apartmentNumber < 0) {
            printf("*** INVALID APARTMENT NUMBER ***"
                " <must be a positive number>: ");
            address->apartmentNumber = getInt();
        }
    }
    else {
        int i;
        for (i = 0; i < 10; i++) {
            address->apartmentNumber = '\0';
        }
    }

    printf("Please enter the contact's postal code: ");
    scanf("%7[^\n]", address->postalCode);
    clearKeyboard();

    printf("Please enter the contact's city: ");
    scanf("%40[^\n]", address->city);
    clearKeyboard();
}

void getNumbers(struct Numbers* numbers)
{
    printf("Please enter the contact's cell phone number: ");
    getTenDigitPhone(numbers->cell);

    printf("Do you want to enter a home phone number? (y or n): ");

    if (yes()) {
        printf("Please enter the contact's home phone number: ");
        getTenDigitPhone(numbers->home);
    }
    else {
        int i;
        for (i = 0; i < 10; i++) {
            numbers->home[i] = '\0';
        }
    }

    printf("Do you want to enter a business phone number? (y or n): ");
    if (yes()) {
        printf("Please enter the contact's business phone number: ");
        getTenDigitPhone(numbers->business);
    }
    else {
        int i;
        for (i = 0; i < 10; i++) {
            numbers->business[i] = '\0';
        }
    }
}

void getContact(struct Contact* contact)
{
    getName(&contact->name);
    getAddress(&contact->address);
    getNumbers(&contact->numbers);
}