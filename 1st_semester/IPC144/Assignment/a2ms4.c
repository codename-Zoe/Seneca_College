/*
+--------------------------------------------------------*
|           2  0  2  0  ~  F  A  L  L
|                 I  P  C  :  B  T  P
|                 1  4  4  :  1  0  0
|                 ASSIGNMENT #2 MS# 4
|
|   S  E  N  E  C  A               C  O  L  L  E  G  E
|   ========  =======  =====  ========  ======  ======
|      ==     ==      ==        ==     ==      ==   ==
|     ==     ====     ====     ==     ====    ======
|    ==     ==          ==    ==     ==      == ==
|   ==     ======  =====     ==     ======  ==   ==
|                                                         
|  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
|  !!!   DO NOT ALTER THE CONTENTS OF THIS FILE   !!!
|  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
+--------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"

void printSectionHeader(const char *testName);

int main(void)
{
    printSectionHeader("Final A#2-Milestone #4");

    contactManagerSystem();

    return 0;
}

// Display specified test section header
void printSectionHeader(const char *testName)
{
    printf("\n");
    printf("------------------------------------------\n");
    printf("Testing: %s\n", testName);
    printf("------------------------------------------\n");
}


/*
				-------------------------------------------------------------
						   EXPECTED OUTPUT [[ NO SORTING ]]

					**   **  *******    *****    *****   ******  *********
                   ***  **  **   **    **      **   **  **   **     **
                  ** * **  **   **     ****   **   **  *******     **
                 **  ***  **   **        **  **   **  ** **       **
                **   **  *******     *****   *****   **   **     **
				-------------------------------------------------------------

------------------------------------------
Testing: Final A#2-Milestone #4
------------------------------------------
Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 7
*** OUT OF RANGE *** <Enter a number between 0 and 6>: 1

+-----------------------------------------------------------------------------+
|                              Contacts Listing                               |
+-----------------------------------------------------------------------------+
 Rick Grimes
    C: 4161112222   H: 4162223333   B: 4163334444
       11 Trailer Park, King City, A7A 2J2
 Maggie R. Greene
    C: 9051112222   H: 9052223333   B: 9053334444
       55 Hightop House, Bolton, A9A 3K3
 Morgan A. Jones
    C: 7051112222   H: 7052223333   B: 7053334444
       77 Cottage Lane, Peterborough, C7C 9Q9
 Sasha Williams
    C: 9052223333   H: 9052223333   B: 9054445555
       55 Hightop House, Bolton, A9A 3K3
+-----------------------------------------------------------------------------+
Total contacts: 4

(Press Enter to Continue)

Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 2

Please enter the contact's first name: I Should
Do you want to enter a middle initial(s)? (y or n): y n
*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: yes
*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: y
Please enter the contact's middle initial(s): Not Be
Please enter the contact's last name: In This List
Please enter the contact's street number: -77
*** INVALID STREET NUMBER *** <must be a positive number>: 77
Please enter the contact's street name: Cityscape Rd.
Do you want to enter an apartment number? (y or n): no
*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: n y
*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: y
Please enter the contact's apartment number: bison
*** INVALID INTEGER *** <Please enter an integer>: -1200
*** INVALID APARTMENT NUMBER *** <must be a positive number>: 1200
Please enter the contact's postal code: Q8Q 3J3 P3P
Please enter the contact's city: Somewhere City
Please enter the contact's cell phone number: 111b223333
Enter a 10-digit phone number: 1112223333
Do you want to enter a home phone number? (y or n): y n
*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: N
Do you want to enter a business phone number? (y or n): yes
*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: y
Please enter the contact's business phone number: 222-333-4444
Enter a 10-digit phone number: 2223334444
--- New contact added! ---

(Press Enter to Continue)

Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 1

+-----------------------------------------------------------------------------+
|                              Contacts Listing                               |
+-----------------------------------------------------------------------------+
 Rick Grimes
    C: 4161112222   H: 4162223333   B: 4163334444
       11 Trailer Park, King City, A7A 2J2
 Maggie R. Greene
    C: 9051112222   H: 9052223333   B: 9053334444
       55 Hightop House, Bolton, A9A 3K3
 Morgan A. Jones
    C: 7051112222   H: 7052223333   B: 7053334444
       77 Cottage Lane, Peterborough, C7C 9Q9
 Sasha Williams
    C: 9052223333   H: 9052223333   B: 9054445555
       55 Hightop House, Bolton, A9A 3K3
 I Should Not Be In This List
    C: 1112223333   H:              B: 2223334444
       77 Cityscape Rd., Apt# 1200, Somewhere City, Q8Q 3J3
+-----------------------------------------------------------------------------+
Total contacts: 5

(Press Enter to Continue)

Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 2

*** ERROR: The contact list is full! ***

(Press Enter to Continue)

Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 3

Enter the cell number for the contact: 6665555
Enter a 10-digit phone number: 6665551111
*** Contact NOT FOUND ***

(Press Enter to Continue)

Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 3

Enter the cell number for the contact: 9051112222

Contact found:
 Maggie R. Greene
    C: 9051112222   H: 9052223333   B: 9053334444
       55 Hightop House, Bolton, A9A 3K3

Do you want to update the name? (y or n): yes no
*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: y
Please enter the contact's first name: Maggie
Do you want to enter a middle initial(s)? (y or n): y
Please enter the contact's middle initial(s): R.
Please enter the contact's last name: Greene Grimes
Do you want to update the address? (y or n): y
Please enter the contact's street number: 55
Please enter the contact's street name: Hightop House
Do you want to enter an apartment number? (y or n): y
Please enter the contact's apartment number: 222
Please enter the contact's postal code: A9A 3K3
Please enter the contact's city: Bolton
Do you want to update the numbers? (y or n): y
Please enter the contact's cell phone number: 9051112222
Do you want to enter a home phone number? (y or n): n
Do you want to enter a business phone number? (y or n): n
--- Contact Updated! ---

(Press Enter to Continue)

Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 1

+-----------------------------------------------------------------------------+
|                              Contacts Listing                               |
+-----------------------------------------------------------------------------+
 Rick Grimes
    C: 4161112222   H: 4162223333   B: 4163334444
       11 Trailer Park, King City, A7A 2J2
 Maggie R. Greene Grimes
    C: 9051112222   H:              B:           
       55 Hightop House, Apt# 222, Bolton, A9A 3K3
 Morgan A. Jones
    C: 7051112222   H: 7052223333   B: 7053334444
       77 Cottage Lane, Peterborough, C7C 9Q9
 Sasha Williams
    C: 9052223333   H: 9052223333   B: 9054445555
       55 Hightop House, Bolton, A9A 3K3
 I Should Not Be In This List
    C: 1112223333   H:              B: 2223334444
       77 Cityscape Rd., Apt# 1200, Somewhere City, Q8Q 3J3
+-----------------------------------------------------------------------------+
Total contacts: 5

(Press Enter to Continue)

Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 4

Enter the cell number for the contact: 4161112222

Contact found:
 Rick Grimes
    C: 4161112222   H: 4162223333   B: 4163334444
       11 Trailer Park, King City, A7A 2J2

CONFIRM: Delete this contact? (y or n): n

(Press Enter to Continue)

Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 4

Enter the cell number for the contact: 4161112222

Contact found:
 Rick Grimes
    C: 4161112222   H: 4162223333   B: 4163334444
       11 Trailer Park, King City, A7A 2J2

CONFIRM: Delete this contact? (y or n): y
--- Contact deleted! ---

(Press Enter to Continue)

Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 1

+-----------------------------------------------------------------------------+
|                              Contacts Listing                               |
+-----------------------------------------------------------------------------+
 Maggie R. Greene Grimes
    C: 9051112222   H:              B:           
       55 Hightop House, Apt# 222, Bolton, A9A 3K3
 Morgan A. Jones
    C: 7051112222   H: 7052223333   B: 7053334444
       77 Cottage Lane, Peterborough, C7C 9Q9
 Sasha Williams
    C: 9052223333   H: 9052223333   B: 9054445555
       55 Hightop House, Bolton, A9A 3K3
 I Should Not Be In This List
    C: 1112223333   H:              B: 2223334444
       77 Cityscape Rd., Apt# 1200, Somewhere City, Q8Q 3J3
+-----------------------------------------------------------------------------+
Total contacts: 4

(Press Enter to Continue)

Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 2

Please enter the contact's first name: Daryl
Do you want to enter a middle initial(s)? (y or n): n
Please enter the contact's last name: Dixon
Please enter the contact's street number: 11
Please enter the contact's street name: Forest Road
Do you want to enter an apartment number? (y or n): n
Please enter the contact's postal code: Y2Y 2N2
Please enter the contact's city: The Kingdom
Please enter the contact's cell phone number: 9993338888
Do you want to enter a home phone number? (y or n): n
Do you want to enter a business phone number? (y or n): n
--- New contact added! ---

(Press Enter to Continue)

Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 1

+-----------------------------------------------------------------------------+
|                              Contacts Listing                               |
+-----------------------------------------------------------------------------+
 Daryl Dixon
    C: 9993338888   H:              B:           
       11 Forest Road, The Kingdom, Y2Y 2N2
 Maggie R. Greene Grimes
    C: 9051112222   H:              B:           
       55 Hightop House, Apt# 222, Bolton, A9A 3K3
 Morgan A. Jones
    C: 7051112222   H: 7052223333   B: 7053334444
       77 Cottage Lane, Peterborough, C7C 9Q9
 Sasha Williams
    C: 9052223333   H: 9052223333   B: 9054445555
       55 Hightop House, Bolton, A9A 3K3
 I Should Not Be In This List
    C: 1112223333   H:              B: 2223334444
       77 Cityscape Rd., Apt# 1200, Somewhere City, Q8Q 3J3
+-----------------------------------------------------------------------------+
Total contacts: 5

(Press Enter to Continue)

Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 3

Enter the cell number for the contact: 1112223333

Contact found:
 I Should Not Be In This List
    C: 1112223333   H:              B: 2223334444
       77 Cityscape Rd., Apt# 1200, Somewhere City, Q8Q 3J3

Do you want to update the name? (y or n): y
Please enter the contact's first name: Rick
Do you want to enter a middle initial(s)? (y or n): n
Please enter the contact's last name: Grimes
Do you want to update the address? (y or n): n
Do you want to update the numbers? (y or n): n
--- Contact Updated! ---

(Press Enter to Continue)

Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 1

+-----------------------------------------------------------------------------+
|                              Contacts Listing                               |
+-----------------------------------------------------------------------------+
 Daryl Dixon
    C: 9993338888   H:              B:           
       11 Forest Road, The Kingdom, Y2Y 2N2
 Maggie R. Greene Grimes
    C: 9051112222   H:              B:           
       55 Hightop House, Apt# 222, Bolton, A9A 3K3
 Morgan A. Jones
    C: 7051112222   H: 7052223333   B: 7053334444
       77 Cottage Lane, Peterborough, C7C 9Q9
 Sasha Williams
    C: 9052223333   H: 9052223333   B: 9054445555
       55 Hightop House, Bolton, A9A 3K3
 Rick Grimes
    C: 1112223333   H:              B: 2223334444
       77 Cityscape Rd., Apt# 1200, Somewhere City, Q8Q 3J3
+-----------------------------------------------------------------------------+
Total contacts: 5

(Press Enter to Continue)

Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 5

Enter the cell number for the contact: 9052223333

 Sasha Williams
    C: 9052223333   H: 9052223333   B: 9054445555
       55 Hightop House, Bolton, A9A 3K3

(Press Enter to Continue)

Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 5

Enter the cell number for the contact: 9998887777
*** Contact NOT FOUND ***

(Press Enter to Continue)

Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 6

<<< Feature to sort is unavailable >>>

(Press Enter to Continue)

Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 0

Exit the program? (Y)es/(N)o: No yes
*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ny
*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: n

Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 0

Exit the program? (Y)es/(N)o: y

Contact Management System: terminated

*/

/* 
						------------------------------------------
						   EXPECTED OUTPUT [[ WITH SORTING ]]

							 *****    *****   ******  *********
							**      **   **  **   **     **
							****   **   **  *******     **
							  **  **   **  ** **       **
						  *****   *****   **   **     **
						------------------------------------------

------------------------------------------
Testing: Final A#2-Milestone #4
------------------------------------------
Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 7
*** OUT OF RANGE *** <Enter a number between 0 and 6>: 1

+-----------------------------------------------------------------------------+
|                              Contacts Listing                               |
+-----------------------------------------------------------------------------+
 Rick Grimes
    C: 4161112222   H: 4162223333   B: 4163334444
       11 Trailer Park, King City, A7A 2J2
 Maggie R. Greene
    C: 9051112222   H: 9052223333   B: 9053334444
       55 Hightop House, Bolton, A9A 3K3
 Morgan A. Jones
    C: 7051112222   H: 7052223333   B: 7053334444
       77 Cottage Lane, Peterborough, C7C 9Q9
 Sasha Williams
    C: 9052223333   H: 9052223333   B: 9054445555
       55 Hightop House, Bolton, A9A 3K3
+-----------------------------------------------------------------------------+
Total contacts: 4

(Press Enter to Continue)

Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 2

Please enter the contact's first name: I Should
Do you want to enter a middle initial(s)? (y or n): y n
*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: yes
*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: y
Please enter the contact's middle initial(s): Not Be
Please enter the contact's last name: In This List
Please enter the contact's street number: -77
*** INVALID STREET NUMBER *** <must be a positive number>: 77
Please enter the contact's street name: Cityscape Rd.
Do you want to enter an apartment number? (y or n): no
*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: n y
*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: y
Please enter the contact's apartment number: bison
*** INVALID INTEGER *** <Please enter an integer>: -1200
*** INVALID APARTMENT NUMBER *** <must be a positive number>: 1200
Please enter the contact's postal code: Q8Q 3J3 P3P
Please enter the contact's city: Somewhere City
Please enter the contact's cell phone number: 111b223333
Enter a 10-digit phone number: 1112223333
Do you want to enter a home phone number? (y or n): y n
*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: N
Do you want to enter a business phone number? (y or n): yes
*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: y
Please enter the contact's business phone number: 222-333-4444
Enter a 10-digit phone number: 2223334444
--- New contact added! ---

(Press Enter to Continue)

Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 1

+-----------------------------------------------------------------------------+
|                              Contacts Listing                               |
+-----------------------------------------------------------------------------+
 Rick Grimes
    C: 4161112222   H: 4162223333   B: 4163334444
       11 Trailer Park, King City, A7A 2J2
 Maggie R. Greene
    C: 9051112222   H: 9052223333   B: 9053334444
       55 Hightop House, Bolton, A9A 3K3
 Morgan A. Jones
    C: 7051112222   H: 7052223333   B: 7053334444
       77 Cottage Lane, Peterborough, C7C 9Q9
 Sasha Williams
    C: 9052223333   H: 9052223333   B: 9054445555
       55 Hightop House, Bolton, A9A 3K3
 I Should Not Be In This List
    C: 1112223333   H:              B: 2223334444
       77 Cityscape Rd., Apt# 1200, Somewhere City, Q8Q 3J3
+-----------------------------------------------------------------------------+
Total contacts: 5

(Press Enter to Continue)

Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 2

*** ERROR: The contact list is full! ***

(Press Enter to Continue)

Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 3

Enter the cell number for the contact: 6665555
Enter a 10-digit phone number: 6665551111
*** Contact NOT FOUND ***

(Press Enter to Continue)

Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 3

Enter the cell number for the contact: 9051112222

Contact found:
 Maggie R. Greene
    C: 9051112222   H: 9052223333   B: 9053334444
       55 Hightop House, Bolton, A9A 3K3

Do you want to update the name? (y or n): yes no
*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: y
Please enter the contact's first name: Maggie
Do you want to enter a middle initial(s)? (y or n): y
Please enter the contact's middle initial(s): R.
Please enter the contact's last name: Greene Grimes
Do you want to update the address? (y or n): y
Please enter the contact's street number: 55
Please enter the contact's street name: Hightop House
Do you want to enter an apartment number? (y or n): y
Please enter the contact's apartment number: 222
Please enter the contact's postal code: A9A 3K3
Please enter the contact's city: Bolton
Do you want to update the numbers? (y or n): y
Please enter the contact's cell phone number: 9051112222
Do you want to enter a home phone number? (y or n): n
Do you want to enter a business phone number? (y or n): n
--- Contact Updated! ---

(Press Enter to Continue)

Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 1

+-----------------------------------------------------------------------------+
|                              Contacts Listing                               |
+-----------------------------------------------------------------------------+
 Rick Grimes
    C: 4161112222   H: 4162223333   B: 4163334444
       11 Trailer Park, King City, A7A 2J2
 Maggie R. Greene Grimes
    C: 9051112222   H:              B:           
       55 Hightop House, Apt# 222, Bolton, A9A 3K3
 Morgan A. Jones
    C: 7051112222   H: 7052223333   B: 7053334444
       77 Cottage Lane, Peterborough, C7C 9Q9
 Sasha Williams
    C: 9052223333   H: 9052223333   B: 9054445555
       55 Hightop House, Bolton, A9A 3K3
 I Should Not Be In This List
    C: 1112223333   H:              B: 2223334444
       77 Cityscape Rd., Apt# 1200, Somewhere City, Q8Q 3J3
+-----------------------------------------------------------------------------+
Total contacts: 5

(Press Enter to Continue)

Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 4

Enter the cell number for the contact: 4161112222

Contact found:
 Rick Grimes
    C: 4161112222   H: 4162223333   B: 4163334444
       11 Trailer Park, King City, A7A 2J2

CONFIRM: Delete this contact? (y or n): n

(Press Enter to Continue)

Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 4

Enter the cell number for the contact: 4161112222

Contact found:
 Rick Grimes
    C: 4161112222   H: 4162223333   B: 4163334444
       11 Trailer Park, King City, A7A 2J2

CONFIRM: Delete this contact? (y or n): y
--- Contact deleted! ---

(Press Enter to Continue)

Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 1

+-----------------------------------------------------------------------------+
|                              Contacts Listing                               |
+-----------------------------------------------------------------------------+
 Maggie R. Greene Grimes
    C: 9051112222   H:              B:           
       55 Hightop House, Apt# 222, Bolton, A9A 3K3
 Morgan A. Jones
    C: 7051112222   H: 7052223333   B: 7053334444
       77 Cottage Lane, Peterborough, C7C 9Q9
 Sasha Williams
    C: 9052223333   H: 9052223333   B: 9054445555
       55 Hightop House, Bolton, A9A 3K3
 I Should Not Be In This List
    C: 1112223333   H:              B: 2223334444
       77 Cityscape Rd., Apt# 1200, Somewhere City, Q8Q 3J3
+-----------------------------------------------------------------------------+
Total contacts: 4

(Press Enter to Continue)

Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 2

Please enter the contact's first name: Daryl
Do you want to enter a middle initial(s)? (y or n): n
Please enter the contact's last name: Dixon
Please enter the contact's street number: 11
Please enter the contact's street name: Forest Road
Do you want to enter an apartment number? (y or n): n
Please enter the contact's postal code: Y2Y 2N2
Please enter the contact's city: The Kingdom
Please enter the contact's cell phone number: 9993338888
Do you want to enter a home phone number? (y or n): n
Do you want to enter a business phone number? (y or n): n
--- New contact added! ---

(Press Enter to Continue)

Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 1

+-----------------------------------------------------------------------------+
|                              Contacts Listing                               |
+-----------------------------------------------------------------------------+
 Daryl Dixon
    C: 9993338888   H:              B:           
       11 Forest Road, The Kingdom, Y2Y 2N2
 Maggie R. Greene Grimes
    C: 9051112222   H:              B:           
       55 Hightop House, Apt# 222, Bolton, A9A 3K3
 Morgan A. Jones
    C: 7051112222   H: 7052223333   B: 7053334444
       77 Cottage Lane, Peterborough, C7C 9Q9
 Sasha Williams
    C: 9052223333   H: 9052223333   B: 9054445555
       55 Hightop House, Bolton, A9A 3K3
 I Should Not Be In This List
    C: 1112223333   H:              B: 2223334444
       77 Cityscape Rd., Apt# 1200, Somewhere City, Q8Q 3J3
+-----------------------------------------------------------------------------+
Total contacts: 5

(Press Enter to Continue)

Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 3

Enter the cell number for the contact: 1112223333

Contact found:
 I Should Not Be In This List
    C: 1112223333   H:              B: 2223334444
       77 Cityscape Rd., Apt# 1200, Somewhere City, Q8Q 3J3

Do you want to update the name? (y or n): y
Please enter the contact's first name: Rick
Do you want to enter a middle initial(s)? (y or n): n
Please enter the contact's last name: Grimes
Do you want to update the address? (y or n): n
Do you want to update the numbers? (y or n): n
--- Contact Updated! ---

(Press Enter to Continue)

Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 1

+-----------------------------------------------------------------------------+
|                              Contacts Listing                               |
+-----------------------------------------------------------------------------+
 Daryl Dixon
    C: 9993338888   H:              B:           
       11 Forest Road, The Kingdom, Y2Y 2N2
 Maggie R. Greene Grimes
    C: 9051112222   H:              B:           
       55 Hightop House, Apt# 222, Bolton, A9A 3K3
 Morgan A. Jones
    C: 7051112222   H: 7052223333   B: 7053334444
       77 Cottage Lane, Peterborough, C7C 9Q9
 Sasha Williams
    C: 9052223333   H: 9052223333   B: 9054445555
       55 Hightop House, Bolton, A9A 3K3
 Rick Grimes
    C: 1112223333   H:              B: 2223334444
       77 Cityscape Rd., Apt# 1200, Somewhere City, Q8Q 3J3
+-----------------------------------------------------------------------------+
Total contacts: 5

(Press Enter to Continue)

Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 5

Enter the cell number for the contact: 9052223333

 Sasha Williams
    C: 9052223333   H: 9052223333   B: 9054445555
       55 Hightop House, Bolton, A9A 3K3

(Press Enter to Continue)

Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 5

Enter the cell number for the contact: 9998887777
*** Contact NOT FOUND ***

(Press Enter to Continue)

Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 6

--- Contacts sorted! ---

(Press Enter to Continue)

Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 1

+-----------------------------------------------------------------------------+
|                              Contacts Listing                               |
+-----------------------------------------------------------------------------+
 Rick Grimes
    C: 1112223333   H:              B: 2223334444
       77 Cityscape Rd., Apt# 1200, Somewhere City, Q8Q 3J3
 Morgan A. Jones
    C: 7051112222   H: 7052223333   B: 7053334444
       77 Cottage Lane, Peterborough, C7C 9Q9
 Maggie R. Greene Grimes
    C: 9051112222   H:              B:           
       55 Hightop House, Apt# 222, Bolton, A9A 3K3
 Sasha Williams
    C: 9052223333   H: 9052223333   B: 9054445555
       55 Hightop House, Bolton, A9A 3K3
 Daryl Dixon
    C: 9993338888   H:              B:           
       11 Forest Road, The Kingdom, Y2Y 2N2
+-----------------------------------------------------------------------------+
Total contacts: 5

(Press Enter to Continue)

Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 0

Exit the program? (Y)es/(N)o: No yes
*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ny
*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: n

Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 0

Exit the program? (Y)es/(N)o: y

Contact Management System: terminated

*/