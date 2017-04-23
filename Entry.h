#ifndef __ENTRY_H__
#define __ENTRY_H__

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>

#include "Ast.h"

using namespace std;

enum Kind {
    classDesc,
    fieldDesc,
    methodDesc,
    parameterDesc,
    variableDesc,
    null,
};

class Entry {
	protected:
		const char * name;	
		int kind;		
		int type;
		int retType;
		int numPara;
		const char * initValue;		
		vector<Declaration *> *parameterList;
		vector<Declaration *> *variableList;
		vector<Declaration *> *memberList;
		int IOMPtype;
		int index;
		
	public:
		int getKind();
		string getName();
		string getInitValue();
		int getType();
		int getNoArguments();
		int getReturnType();
		vector<Declaration *> *getParameters();
		vector<Declaration *> *getVariables();
		vector<Declaration *> *getMembers();
		int getIOMPtype();
		int getIndex();		
};

class ReturnEntry : public Entry {
	
	public:
		ReturnEntry(const char *);
};

class VariableDesc : public Entry {

	public:
		VariableDesc(const char *, int, const char *, int);
};

class ParameterDesc : public Entry {

	public:
		ParameterDesc(const char *, int, int);
};

class FieldDesc : public Entry {

	public:
		FieldDesc(const char *, int, const char *);
};

class MethodDesc : public Entry {

	public:
		MethodDesc(const char *, int, int, vector<Declaration *> *, vector<Declaration *> *);
		MethodDesc(const char *, int, int, int);
};

class ClassDesc : public Entry {

	public:
		ClassDesc(const char *, vector<Declaration *> *);
};

#endif