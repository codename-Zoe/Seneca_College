#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_

namespace sdds {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;
      bool isValid();

      //type conversion operators
      operator bool() const;
      operator int() const;
      operator double() const;

      //unary member operator
      bool operator~() const;

      //Binary member operators
      Account& operator=(const int);
      Account& operator=(Account&);
      Account& operator+=(const double);
      Account& operator-=(const double);
      Account& operator<<(Account& account);
      Account& operator>>(Account& account);
   };

   //Binary helper operators
   double operator+(const Account&, const Account&);
   double operator+=(double&, const Account&);
   
}
#endif