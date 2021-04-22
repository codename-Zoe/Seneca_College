#ifndef _SDDS_FILE_H 
#define _SDDS_FILE_H

namespace sdds
{
	struct ShoppingRec;
	bool openFileForRead();
	bool openFileForOverwrite();
	void closeFile();
	bool freadShoppingRec(ShoppingRec* rec);
	void fwriteShoppintRec(const ShoppingRec* rec);
}

#endif