#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H

namespace sdds {
	class Label {
		char frame[9];
		char* labelStr;
		int labelNum;
		void setToDefault();
		void setFrame(const char* str);
		void setLabel(const char* content);
	public:
		Label();
		Label(const char* frameArg);
		Label(const char* frameArg, const char* content);
		void readLabel();
		void clearKeyboard();
		std::ostream& printLabel()const;
		~Label();
	};
}

#endif