#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_

namespace sdds
{
    class Food {
        char foodName[31];
        int calorie;
        int consumption;
        void setName(const char* name);
    public:
        void setEmpty();
        void set(const char* name, int calorie, int time);
        int getCalorie()const;
        bool isValid()const;
        void display()const;
    };
}

#endif
