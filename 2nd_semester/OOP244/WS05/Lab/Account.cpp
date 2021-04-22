#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }

   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }

   Account::Account(int number, double balance) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }

   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }

   bool Account::isValid() {
       if (m_number >= 10000 && m_number <= 99999 && m_balance >= 0) {
           return true;
       }
       else {
           return false;
       }
   }

   Account::operator bool() const {
       if (m_number >= 10000 && m_number <= 99999 && m_balance >= 0) {
           return true;
       }
       else {
           return false;
       }
   }

   Account::operator int() const {
       return m_number;
   }

   Account::operator double() const {
       return m_balance;
   }

   bool Account::operator ~() const {
       if (m_number == 0) {
           return true;
       }
       else {
           return false;
       }
   }

   Account& Account::operator=(const int number) {
       if (m_number == 0) {
           m_number = number;
       }
       else if (number < 10000 || number > 99999) {
           setEmpty();
       }
       return *this;
   }

   Account& Account::operator=(Account& account) {
       if (m_number == 0 && account.isValid()) {
           m_number = account.m_number;
           m_balance = account.m_balance;
           account.m_number = 0;
           account.m_balance = 0.0;
       }
       return *this;
   }

   Account& Account::operator+=(const double deposit) {
       if (isValid() && deposit >= 0) {
           m_balance += deposit;
       }
       return *this;
   }

   Account& Account::operator-=(const double withdraw) {
       if (isValid() && withdraw > 0) {
           if (m_balance - withdraw > 0) {
               m_balance -= withdraw;
           }
       }
       return *this;
   }

   Account& Account::operator<<(Account& account) {
       if (isValid() && account.m_balance > 0) {
           if (this != &account) {
               m_balance += account.m_balance;
               account.m_balance = 0.0;
           }
       }
       return *this;
   }

   Account& Account::operator>>(Account& account) {
       if (isValid() && account.m_balance > 0) {
           if (this != &account) {
               account.m_balance += m_balance;
               m_balance = 0.0;
           }
       }
       return *this;
   }

   double operator+(const Account& leftOp, const Account& rightOp) {
       double sum;
       if (leftOp.operator int() > 0 && rightOp.operator int() > 0) {
           sum = leftOp.operator double() + rightOp.operator double();
       }
       else {
           sum = 0;
       }
       return sum;
   }

   double operator+=(double& leftOp, const Account& rightOp) {
       if (leftOp >= 0 && rightOp.operator int() > 0) {
           leftOp += rightOp.operator double();
       }
       return leftOp;
   }

}