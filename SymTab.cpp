#include "SymTab.h"

using namespace std;

SymTab::SymTab() {

    MethodDesc* readInt = new MethodDesc("readInt", 1, 0, 0);
    MethodDesc* readFloat = new MethodDesc("readFloat", 2, 0, 0);
    MethodDesc* println = new MethodDesc("println", 0, 0, 0);
    MethodDesc* printInt = new MethodDesc("printInt", 0, 1, 1);
    MethodDesc* printFloat = new MethodDesc("printFloat", 0, 1, 2);
    MethodDesc* printString = new MethodDesc("printString", 0, 1, 4);
	
	SimpleIOMap.insert(pair<string, Entry*>(readInt->getName(), readInt));
	SimpleIOMap.insert(pair<string, Entry*>(readFloat->getName(), readFloat));
	SimpleIOMap.insert(pair<string, Entry*>(println->getName(), println));
	SimpleIOMap.insert(pair<string, Entry*>(printInt->getName(), printInt));
	SimpleIOMap.insert(pair<string, Entry*>(printFloat->getName(), printFloat));
	SimpleIOMap.insert(pair<string, Entry*>(printString->getName(), printString));

    ClassDesc* SimpleIO = new ClassDesc("SimpleIO", NULL);

    pkgScope.insert(pair<string, Entry*>(SimpleIO->getName(), SimpleIO));
    currentMap = pkgScope;

}

SymTab::~SymTab() {
    pkgScope.clear();
    classMap.clear();
    currentMap.clear();
}

void
SymTab::openClassScope() {
    
    pkgScope = currentMap;
    currentMap = classMap;
}

void
SymTab::openMethodScope() {
    map<string, Entry *> methodScope;
    classMap = currentMap;
    currentMap = methodScope;
}

void
SymTab::closeMethodScope() {
    currentMap = classMap;
}

void
SymTab::install(Entry* e) {
    map<string, Entry*>::iterator it;
    it = currentMap.find(e->getName());
    if (it != currentMap.end()) {
        printf("***ERROR: Duplicate Entry.\n");
		errorNum++;
	}	
    else
        currentMap.insert(pair<string, Entry*>(e->getName(), e));
}

Entry*
SymTab::lookup(const char* name) {
    map<string, Entry*>::iterator it;
    it = currentMap.find(name);
    if (it == currentMap.end()) {
        it = classMap.find(name);
        if (it == classMap.end()) {
            it = pkgScope.find(name);
            if (it == pkgScope.end()) {
				it = SimpleIOMap.find(name);
				if (it == SimpleIOMap.end()) {				
					return NULL;
				} else 
					return it->second;
            } else
                return it->second;
        } else
            return it->second;
    } else
        return it->second;
}