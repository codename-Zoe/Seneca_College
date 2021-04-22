#ifndef SDDS_LIST_H_
#define SDDS_LIST_H_
#include <iostream>
#include "Collection.h"

using namespace std;
namespace sdds
{
	template<typename T, typename K>
	bool search(Collection<T>& obj, T* arr, int num, const K key) {
		bool flag = false;
		for (int i = 0; i < num; i++) {
			if (arr[i] == key) {
				obj.add(arr[i]);
				flag = true;
			}
		}
		return flag;
	}

	template<typename T>
	void listArrayElements(const char* title, const T& arr, int element) {
		cout << title << endl;
		for (int i = 0; i < element; i++) {
			cout << i + 1 << ": " << arr[i] << endl;
		}
	}
}

#endif