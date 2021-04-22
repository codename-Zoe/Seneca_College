#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Label.h"

using namespace std;
namespace sdds
{
	void Label::setToDefault() {
		frame[0] = '\0';
		labelStr = nullptr;
	}

	void Label::setFrame(const char* str) {
		if (str != nullptr && strlen(str) == 8) {
			strcpy(frame, str);
		}
	}

	void Label::setLabel(const char* content) {
		if (content != nullptr) {
			delete[] labelStr;
			labelStr = new char[strlen(content) + 1];
			strcpy(labelStr, content);
			if (strlen(content) > 70) {
				labelStr[70] = '\0';
			}
		}
	}

	Label::Label() {
		setToDefault();
		setFrame("+-+|+-+|");
	}

	Label::Label(const char* frameArg) {
		setToDefault();
		setFrame(frameArg);
	}

	Label::Label(const char* frameArg, const char* content) {
		setToDefault();
		setFrame(frameArg);
		setLabel(content);
	}

	void Label::readLabel() {
		char label[70] = { '\0' };
		cin.get(label, 71, '\n');
		setLabel(label);
		clearKeyboard();
	}

	void Label::clearKeyboard() {
		while (getchar() != '\n');
	}

	std::ostream& Label::printLabel()const {
		if (frame[0] != '\0' && labelStr != nullptr) {
			cout << frame[0];
			for (int i = 0; i < strlen(labelStr) + 2; i++) {
				cout << frame[1];
			}
			cout << frame[2] << endl;
			cout << frame[7];
			for (int i = 0; i < strlen(labelStr) + 2; i++) {
				cout << " ";
			}
			cout << frame[3] << endl;
			cout << frame[7];
			cout << " " << labelStr << " ";
			cout << frame[3] << endl;
			cout << frame[7];
			for (int i = 0; i < strlen(labelStr) + 2; i++) {
				cout << " ";
			}
			cout << frame[3] << endl;
			cout << frame[6];
			for (int i = 0; i < strlen(labelStr) + 2; i++) {
				cout << frame[5];
			}
			cout << frame[4];
		}
			return cout;
	}

	Label::~Label() {
		delete[] labelStr;
		labelStr = nullptr;
	}
}