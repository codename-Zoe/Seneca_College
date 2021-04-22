#define _CRT_SECURE_NO_WARNINGS
#include "cstring.h"

namespace sdds
{
	void strCpy(char* des, const char* src) {
		int i = 0;
		while ((des[i] = src[i]) != '\0') {
			i++;
		}
	}

	void strnCpy(char* des, const char* src, int len) {
		int length = strLen(src); 
		if (length < len) {  
			*des = *src; 
			des[length] = '\0';
		}
		else if (length >= len) {
			for (int i = 0; i < len; i++) {  
				des[i] = src[i];
			}
		}
	}

	int strCmp(const char* s1, const char* s2) {
		int i = 0;
		int comp = 0;
		while ((s1[i] != '\0' && s2[i] != '\0' && comp == 0)) {
			if (s1[i] != s2[i]) {
				if (s1[i] > s2[i]) {
					comp = 1;
				}
				else if (s1[i] < s2[i]) {
					comp = -1;
				}
			}
			i++;
		}
		return comp;
	}

	int strnCmp(const char* s1, const char* s2, int len) {	
		int comp = 0;
		for (int i = 0; i < len; i++) {
			if (s1[i] != s2[i] && s1[i] > s2[i]) {
				comp = 1;
			}
			else if (s1[i] != s2[i] && s1[i] < s2[i]) 
				comp = -1;
			}
		}
		return comp;
	}

	int strLen(const char* s) {
		int i = 0;
		while (s[i] != '\0') {
			i++;
		}
		return i;
	}

	const char* strStr(const char* str1, const char* str2) {
		do {
			const char* org = str1;
			const char* pat = str2;
			while (*str1 && *pat && *str1 == *pat) { 
				str1++;
				pat++;
			}
			if (!*pat) {
				return org;
			}
			str1 += 1;
		} while (*str1);
		return nullptr;
	}

	void strCat(char* des, const char* src) {
		int i = 0;
		int len = strLen(des);
		while (src[i] != '\0') {
			des[len] = src[i];
			len++;              
			i++;              
		}
		des[len] = '\0';
	}
}