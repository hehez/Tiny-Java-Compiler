#ifndef __SYMTAB_H__
#define __SYMTAB_H__

#include "Entry.h"

extern int errorNum;

class SymTab {

	private:
		map<string, Entry *> pkgScope;
		map<string, Entry *> classMap;
		map<string, Entry *> currentMap;
		map<string, Entry *> SimpleIOMap;

	public:
		SymTab();
		~SymTab();

		void openClassScope();
		void openMethodScope();
		void closeMethodScope();
		void install(Entry *);
		Entry *lookup(const char *);

};

#endif