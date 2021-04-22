#ifndef SDDS_CALORIELIST_H_
#define SDDS_CALORIELIST_H_

#include "Food.h"
namespace sdds
{
    class CalorieList{
        Food* food;
        int noOfMeal;
        int mealsAdded;
        void setEmpty();
        double totalCal()const;
        bool isValid()const;
        void Title()const;
        void footer()const;
        public:
        void init(int size);
        bool add(const char* item_name, int calories, int when);
        void display()const;
        void deallocate();
    };
}
#endif 