#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "LabelMaker.h"

using namespace std;
namespace sdds {
	Label* label = nullptr;

	void LabelMaker::setToDefault() {
		label = nullptr;
	}

	LabelMaker::LabelMaker(int noOfLabels) {
		setToDefault();
		numLabels = noOfLabels;
		label = new Label[noOfLabels];
	}

	void LabelMaker::readLabels() {
		cout << "Enter " << numLabels << " labels:" << endl;
		for (int i = 0; i < numLabels; i++) {
			cout << "Enter label number " << i + 1 << endl;
			cout << "> ";
			label[i].readLabel();
		}
	}

	void LabelMaker::printLabels() {
		for (int i = 0; i < numLabels; i++) {
			label[i].printLabel();
			cout << endl;
		}
	}

	LabelMaker::~LabelMaker() {
		delete[] label;
		label = nullptr;
	}
}