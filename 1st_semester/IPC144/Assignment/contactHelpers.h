#include "contacts.h"

void clearKeyboard(void);
void pause(void);
int getInt(void);
int getIntInRange(int min, int max);
int yes(void);
int menu(void);
void contactManagerSystem(void);
void getTenDigitPhone(char phoneNum[]);
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]);
void displayContactHeader(void);
void displayContactFooter(int count);
void displayContact(const struct Contact* contact);
void displayContacts(const struct Contact contacts[], int size);
void searchContacts(const struct Contact contacts[], int size);
void addContact(struct Contact contacts[], int size);
void updateContact(struct Contact contacts[], int size);
void deleteContact(struct Contact contacts[], int size);
void sortContacts(struct Contact contacts[], int size);