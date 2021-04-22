#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "Text.h"

using namespace std;
namespace sdds 
{
   int Text::getFileLength() const {
      int len = 0;
      ifstream fin(m_filename);
      while (fin) {
         fin.get();
         len += !!fin;
      }
      return len;
   }

   const char& Text::operator[](int index)const {
       if (index < getFileLength()) {
           return m_content[index];
       }
       else {
           return this->m_content[index] = '\0';
       }
   }

   Text::Text(const char* filename) {
       if (filename != nullptr) {
           m_filename = nullptr;
           m_content = nullptr;
           m_filename = new char[strlen(filename) + 1];
           strcpy(m_filename, filename);
       }
   }

   Text::~Text() {
       delete[] m_filename;
       delete[] m_content;
   }

   Text::Text(const Text& text) {
       if (text.m_filename != nullptr && text.getFileLength() != 0) {
           m_filename = nullptr;
           m_content = nullptr;
           m_filename = new char[strlen(text.m_filename) + 1];
           m_content = new char[text.getFileLength() + 1];
           strcpy(m_filename, text.m_filename);
           text.m_content[text.getFileLength()] = '\0';
           strcpy(m_content, text.m_content);
       }
   }

   Text& Text::operator=(const Text& text) {
       if (this != &text) {
           if (text.m_filename != nullptr && text.getFileLength() != 0) {
               if (m_filename != nullptr) {
                   delete[] m_filename;
                   m_filename = nullptr;
               }
               m_filename = new char[strlen(text.m_filename) + 1];
               strcpy(m_filename, text.m_filename);
               read();
           }
       }
       return *this;
   }

   void Text::read() {
       int i = 0;
       char ch;
       int len = getFileLength();
       ifstream file(m_filename);
       if (file.is_open()) {
           delete[] m_content;
           m_content = nullptr;
           m_content = new char[len + 1];
           while (i < len){
               ch = file.get();
               m_content[i] = ch;
               i++;
           }
           m_content[len] = '\0';
       }
   }

   void Text::write(std::ostream& os) const {
       if (getFileLength() != 0) {
           for (int i = 0; i < getFileLength(); i++) {
               os << m_content[i];
           }
       }
   }

   ostream& operator<<(ostream& os, const Text& text) {
       text.write(os);
       return os;
   }

}