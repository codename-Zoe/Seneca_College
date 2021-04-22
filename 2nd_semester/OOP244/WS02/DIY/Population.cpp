#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Population.h"
#include "File.h"

using namespace std;
namespace sdds
{
    int numofPost, total = 0;
    Poprepo* poprepo = nullptr;

    void sort() {  // sort the population in ascending order
        int i, j;
        Poprepo temp;
        for (i = numofPost - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (poprepo[j].population > poprepo[j + 1].population) {
                    temp = poprepo[j];
                    poprepo[j] = poprepo[j + 1];
                    poprepo[j + 1] = temp;
                }
            }
        }
    }

    bool load(const char* filename) {
        bool ok = false;
        int i = 0;
        if (openFile(filename)) {
            numofPost = noOfRecords();
            poprepo = new Poprepo[numofPost];
            while (i < numofPost) {
                load(poprepo[i]);
                i++;
            }
            if (numofPost != i) {
                cout << " Error: incorrect number of records read; the data is possibly corrupted!" << endl;
            }
            else {
                ok = true;
            }
            closeFile();
        }
        else {
            cout << "Could not open data file: " << filename << endl;
        }
        return ok;
    }

    bool load(Poprepo& poprepo) {
        bool ok = false;
        char postalcode[6];

        if (read(postalcode) && read(poprepo.population)) {
            poprepo.postalCode = new char[strlen(postalcode) + 1];
            strcpy(poprepo.postalCode, postalcode);
            ok = true;
        }
        return ok;
    }

    void display(const Poprepo& poprepo) {
            cout << poprepo.postalCode << ":  " << poprepo.population;
    }

    void display() {
        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;
        sort();
        for (int i = 0; i < numofPost; i++) {
            cout << i + 1 << "- ";
            display(poprepo[i]);   
            cout << endl;
            total += poprepo[i].population;
        }
        cout << "-------------------------" << endl;
        cout << "Population of Canada: " << total << endl;
    }

    void deallocateMemory() {
        for (int i = 0; i < numofPost; i++) {
            delete[] poprepo[i].postalCode;
        }
        delete[] poprepo;
        poprepo = nullptr;
    }
}