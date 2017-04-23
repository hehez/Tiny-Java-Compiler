#include "Entry.h"

using namespace std;

int
Entry::getKind() {
    return kind;
}

string
Entry::getName() {
    return string(name);
}

string
Entry::getInitValue() {
    return string(initValue);
}

int
Entry::getType() {
    return type;
}

int
Entry::getNoArguments() {
	return numPara;
}

int
Entry::getReturnType() {
	return retType;
}

vector<Declaration *> *
Entry::getParameters() {
	return variableList;
}

vector<Declaration *> *
Entry::getVariables() {
	return parameterList;
}

vector<Declaration *> *
Entry::getMembers() {
	return memberList;
}

int
Entry::getIOMPtype() {
	return IOMPtype;
}

int Entry::getIndex() {
	return index;
}

ReturnEntry::ReturnEntry(const char* name) {
    this->name = name;
}

VariableDesc::VariableDesc(const char* name, int type, const char *initValue, int index) {
    this->name = name;
    this->type = type;
    this->initValue = initValue;
    this->kind = variableDesc;
	this->index = index;
}

ParameterDesc::ParameterDesc(const char* name, int type, int index) {
    this->name = name;
    this->type = type;
    this->kind = parameterDesc;
	this->index = index;
}

FieldDesc::FieldDesc(const char *name, int type, const char *initValue) {
    this->name = name;
    this->type = type;
    this->initValue = initValue;
    this->kind = fieldDesc;
}

MethodDesc::MethodDesc(const char *name, int retType, int numPara, vector<Declaration *> *parameterList, vector<Declaration *> *variableList) {
    this->name = name;
    this->retType = retType;
    this->numPara = numPara;
    this->parameterList = parameterList;
    this->variableList = variableList;
    this->kind = methodDesc;
}

MethodDesc::MethodDesc(const char *name, int retType, int numPara, int IOMPtype) {
    this->name = name;
    this->retType = retType;
    this->numPara = numPara;
    this->IOMPtype = IOMPtype;
}



ClassDesc::ClassDesc(const char* name, vector<Declaration *> *memberList) {
    this->name = name;
    this->memberList = memberList;
    this->kind = classDesc;
}