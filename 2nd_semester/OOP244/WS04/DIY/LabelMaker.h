#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H
#include "Label.h"

namespace sdds {
	class LabelMaker {
		Label* label;
		int numLabels;
		void setToDefault();
	public:
		LabelMaker(int noOfLabels);
		void readLabels();
		void printLabels();
		~LabelMaker();
	};
}

#endif