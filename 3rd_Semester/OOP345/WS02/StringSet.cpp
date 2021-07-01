#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "StringSet.h"

using namespace std;
namespace sdds
{
  StringSet::StringSet() {}

  StringSet::StringSet(const char* filename) {
    int i = 0;
    num_str = 0;
    string line;
    ifstream file(filename);
    if (file.is_open()) {
      while (getline(file, line, ' ')) {
        num_str++;
      }
    }
    element = new string[num_str];
    if (file.is_open()) {
      while (getline(file, line, ' ')) {
        element[i] = line;
        i++;
      }
    }
  }

  StringSet::StringSet(const StringSet& src) : StringSet(){
    *this = src;
  }

  StringSet::StringSet(StringSet&& src) noexcept : StringSet() {
    operator=(move(src));
  }

  StringSet& StringSet::operator=(const StringSet& src) {
    if (this != &src) {
      delete[] element;
      element = new string[src.num_str];
      for (size_t i = 0; i < src.num_str; i++) {
        element[i] = src.element[i];
      }
      num_str = src.num_str;
    }
    return *this;
  }

  StringSet& StringSet::operator=(StringSet&& src) noexcept{
    if (this != &src) {
      delete[] element;
      element = src.element;
      num_str = src.num_str;
      src.element = nullptr;
      src.num_str = 0;
    }
    return *this;
  }

  StringSet::~StringSet() {
    delete[] element;
  }

  size_t StringSet::size() {
    return num_str;
  }

  string StringSet::operator[](size_t index) const{
    string temp;
    if (index < num_str) { 
      temp = element[index];
    }
    else {
      temp = "";
    }
    return temp;
  }
}
