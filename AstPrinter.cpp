#include <iostream>
#include "AstPrinter.h"

using namespace std;

void
AstPrinter::visit(MethodDeclaration *aDeclNode) {

	// verify the integrity of the node
	if (aDeclNode == NULL)
		throw AstException("AstPrinter::visit: MethodDeclaration: NULL argument");

	if (aDeclNode->getBody() == NULL)
		throw AstException("AstPrinter::visit: MethodDeclaration: body is NULL");

	parameterType = 100;

	MethodDesc *e = new MethodDesc(aDeclNode->getName(), aDeclNode->getRetType(), aDeclNode->getParameters()->size(), aDeclNode->getParameters(), aDeclNode->getVariables());
	symTab->install(e);

	doIndent(indent);

	cout << AstNode::kind2string(aDeclNode->getKind()) << ": " << " [" << aDeclNode->getLineNo() << "] " << endl;
	cout.flush();

	doIndent(indent + 1);
	cout << AstNode::type2string(aDeclNode->getRetType()) << " " << aDeclNode->getName() << ": ";

	// print the symbol table entry, if defined
	if (symTab->lookup(aDeclNode->getName()) != NULL) {
		cout << "symbol table reference set";
	} else
		cout << "no symbol table reference";
	cout << endl;

	symTab->openMethodScope();
	vector<int> parameterVector;
	// print (visit) the parameters
	if (aDeclNode->getParameters() != NULL) {
		for (int i = 0; i < aDeclNode->getParameters()->size(); i++) {
			indent++;
			aDeclNode->getParameters()->at(i)->accept(this);
			indent--;
			parameterVector.push_back(parameterType);
		}
	}
	parameterMap.insert(pair<string, vector<int> >(string(aDeclNode->getName()), parameterVector));

	// print (visit) the variables
	if (aDeclNode->getVariables() != NULL) {
		for (int i = 0; i < aDeclNode->getVariables()->size(); i++) {
			indent++;
			aDeclNode->getVariables()->at(i)->accept(this);
			indent--;
		}
	}

	// print (visit) the body
	indent++;
	aDeclNode->getBody()->accept(this);
	indent--;

	if (aDeclNode->getRetType() != returnType) {
		cerr << "***ERROR: Invalid method return type from " << AstNode::type2string(returnType);
		cerr << ", expected " << AstNode::type2string(aDeclNode->getRetType()) << endl;

		errorNum++;
	}

	symTab->closeMethodScope();
}

void
AstPrinter::visit(FieldDeclaration *aDeclNode) {
	// verify the integrity of the node
	if (aDeclNode == NULL)
		throw AstException("AstPrinter::visit: FieldDeclaration: NULL argument");

	FieldDesc *e = new FieldDesc(aDeclNode->getName(), aDeclNode->getType(), aDeclNode->getInitValue());
	symTab->install(e);

	doIndent(indent);

	cout << AstNode::kind2string(aDeclNode->getKind()) << ": " << " [" << aDeclNode->getLineNo() << "] " << endl;

	doIndent(indent + 1);

	cout << aDeclNode->getName() << " " << AstNode::type2string(aDeclNode->getType())
		<< " = " << aDeclNode->getInitValue() << ": ";

	// print the symbol table entry, if defined
	if (symTab->lookup(aDeclNode->getName()) != NULL) {
		cout << "symbol table reference set";
	} else {
		cout << "no symbol table reference";
	}
	cout << endl;
	cout.flush();

	if (aDeclNode->getType() != aDeclNode->getInitLiteral()->getType()) {
		cerr << "***ERROR: Invalid declaration from " << AstNode::type2string(aDeclNode->getInitLiteral()->getType());
		cerr << ", expected " << AstNode::type2string(aDeclNode->getType()) << endl;

		errorNum++;
	}
}

void
AstPrinter::visit(ParameterDeclaration *aDeclNode) {

	// verify the integrity of the node
	if (aDeclNode == NULL)
		throw AstException("AstPrinter::visit: ParameterDeclaration: NULL argument");

	parameterType = aDeclNode->getType();

	indexNum++;

	ParameterDesc *e = new ParameterDesc(aDeclNode->getName(), aDeclNode->getType(), indexNum);
	symTab->install(e);

	doIndent(indent);

	cout << AstNode::kind2string(aDeclNode->getKind()) << ": " << " [" << aDeclNode->getLineNo() << "] " << endl;

	doIndent(indent + 1);

	cout << aDeclNode->getName() << " " << AstNode::type2string(aDeclNode->getType()) << ": ";

	// print the symbol table entry, if defined
	if (symTab->lookup(aDeclNode->getName()) != NULL) {
		cout << "symbol table reference set";
	} else {
		cout << "no symbol table reference";
	}
	cout << endl;
	cout.flush();
}

void
AstPrinter::visit(VariableDeclaration *aDeclNode) {

	// verify the integrity of the node
	if (aDeclNode == NULL)
		throw AstException("AstPrinter::visit: VariableDeclaration: NULL argument");

	indexNum++;

	VariableDesc *e = new VariableDesc(aDeclNode->getName(), aDeclNode->getType(), aDeclNode->getInitValue(), indexNum);
	symTab->install(e);

	doIndent(indent);

	cout << AstNode::kind2string(aDeclNode->getKind()) << ": " << " [" << aDeclNode->getLineNo() << "] " << endl;

	doIndent(indent + 1);

	cout << aDeclNode->getName() << " " << AstNode::type2string(aDeclNode->getType())
		<< " = " << aDeclNode->getInitValue() << ": ";

	// print the symbol table entry, if defined
	if (symTab->lookup(aDeclNode->getName()) != NULL) {
		cout << "symbol table reference set";
	} else {
		cout << "no symbol table reference";
	}
	cout << endl;
	cout.flush();

	int type = aDeclNode->getType();
	switch (type) {
		case 1:
			if (type != aDeclNode->getInitLiteral()->getType()) {
				cerr << "***ERROR: Invalid declaration from " << AstNode::type2string(aDeclNode->getInitLiteral()->getType());
				cerr << ", expected " << AstNode::type2string(type) << endl;

				errorNum++;
			}
			break;
		case 2:
			if (aDeclNode->getInitLiteral()->getType() < 1 && aDeclNode->getInitLiteral()->getType() > 2) {
				cerr << "***ERROR: Invalid declaration from " << AstNode::type2string(aDeclNode->getInitLiteral()->getType());
				cerr << ", expected " << AstNode::type2string(type) << endl;

				errorNum++;
			}
			break;
		case 5:
			if (aDeclNode->getInitLiteral()->getType() != 8) {
				cerr << "***ERROR: Invalid array declaration from " << AstNode::type2string(aDeclNode->getInitLiteral()->getType());
				cerr << ", expected null" << endl;

				errorNum++;
			}
			break;
		case 6:
			if (aDeclNode->getInitLiteral()->getType() != 8) {
				cerr << "***ERROR: Invalid array declaration from " << AstNode::type2string(aDeclNode->getInitLiteral()->getType());
				cerr << ", expected null" << endl;

				errorNum++;
			}
			break;
	}    
}

void
AstPrinter::visit(ClassDeclaration *aDeclNode) {

	// verify the integrity of the node
	if (aDeclNode == NULL)
		throw AstException("AstPrinter::visit: ClassDeclaration: NULL argument");
		
	string cName = string(aDeclNode->getName()) + ".java";
	
	if(cName.compare(fileName) != 0) {
		cout << "***ERROR: Class name and file name is not match." << endl;
		errorNum++;
		//exit(1);
	}

	//errorNum = 0;
	indexNum = -1;
	symTab = new SymTab();
	ClassDesc *e = new ClassDesc(aDeclNode->getName(), aDeclNode->getMembers());
	symTab->install(e);

	doIndent(indent);
	cout << AstNode::kind2string(aDeclNode->getKind()) << ": " << aDeclNode->getName()
		<< " [" << aDeclNode->getLineNo() << "] " << endl;
	cout.flush();

	symTab->openClassScope();

	// check if members are present
	if (aDeclNode->getMembers() == NULL) {
		doIndent(indent + 1);
		cout << "No members" << endl;
		cout.flush();
	} else {
		// print (visit) members
		for (int i = 0; i < aDeclNode->getMembers()->size(); i++) {
			// check if this member is really there
			if (aDeclNode->getMember(i) == NULL)
				throw AstException("AstPrinter::visit: DCLASS: member is NULL");
			// now, visit the next class member
			indent++;
			aDeclNode->getMember(i)->accept(this);
			indent--;
		}
	}
	
	if (errorNum != 0) {
		cout << "\nNumber of Semantic Errors: " << errorNum << "\n" << endl;
	} else {
		cout << "\nNo Semantic Errors.\n" << endl;
	}
}

void
AstPrinter::visit(LiteralExpression *anExpNode) {
	// verify the integrity of the node
	if (anExpNode == NULL)
		throw AstException("AstPrinter::visit: NULL argument in LiteralExpression");

	doIndent(indent);

	cout << AstNode::kind2string(anExpNode->getKind()) << ": " << " [" << anExpNode->getLineNo() << "] " << endl;
	cout.flush();

	doIndent(indent + 1);

	cout << anExpNode->getLiteral() << " " << AstNode::type2string(anExpNode->getType()) << endl;
}

void
AstPrinter::visit(ReferenceExpression *anExpNode) {
	// verify the integrity of the node
	if (anExpNode == NULL)
		throw AstException("AstPrinter::visit: ReferenceExpression: NULL argument");

	doIndent(indent);

	cout << AstNode::kind2string(anExpNode->getKind()) << ": " << " [" << anExpNode->getLineNo() << "] " << endl;
	cout.flush();

	doIndent(indent + 1);
	cout << anExpNode->getName() << ": ";

	// print the symbol table info
	if (symTab->lookup(anExpNode->getName()) != NULL) {
		cout << "symbol table reference set" << endl;
		int type = symTab->lookup(anExpNode->getName())->getType();
		anExpNode->setType(type);		
	}
	else {
		cout << "no symbol table reference" << endl;
		cerr << "***ERROR: " << anExpNode->getName() << " is not declared." << endl;

		errorNum++;
	}

	// print (visit) the index expression, if provided
	if (anExpNode->getExpression() != NULL) {
		indent = indent + 2;
		anExpNode->getExpression()->accept(this);
		indent = indent - 2;
	}    
}

void
AstPrinter::visit(NewExpression *anExpNode) {
	// verify the integrity of the node
	if (anExpNode == NULL)
		throw AstException("AstPrinter::visit: NewExpression: NULL argument");

	if (anExpNode->getExpression() == NULL)
		throw AstException("AstPrinter::visit: NewExpression: size expression is NULL");

	doIndent(indent);

	cout << AstNode::kind2string(anExpNode->getKind()) << ": " << AstNode::type2string(anExpNode->getBaseType());
	cout << " [" << anExpNode->getLineNo() << "] " << endl;

	// now, increase the indent level and visit, i.e. print the size expression
	indent++;
	anExpNode->getExpression()->accept(this);
	indent--;


	int type = anExpNode->getExpression()->getType();
	if (type != 1 && type != 5) {
		cerr << "***ERROR: Invalid array initialization from "<< AstNode::type2string(type);
		cerr << ", expected " << AstNode::type2string(1) << endl;

		errorNum++;
	}   
	int baseType = anExpNode->getBaseType();
	if (baseType == 5)
		anExpNode->setType(5);
	else if (baseType == 6)
		anExpNode->setType(6);
	else {
		cerr << "***ERROR: Not a valiad array type: " << AstNode::type2string(baseType) << endl;

		errorNum++;
	}
}

void
AstPrinter::visit(UnaryExpression *anExpNode) {
	// verify the integrity of the node
	if (anExpNode == NULL)
		throw AstException("AstPrinter::visit: UnaryExpression: NULL argument");

	if (anExpNode->getOperand() == NULL)
		throw AstException("AstPrinter.visit: UnaryExpression: operand is NULL");

	doIndent(indent);

	cout << AstNode::kind2string(anExpNode->getKind()) << ": " << " [" << anExpNode->getLineNo() << "] " << endl;
	cout.flush();

	doIndent(indent + 1);
	cout << AstNode::operator2string(anExpNode->getOperator());
	if (anExpNode->isPostfix())
		cout << " postfix" << endl;
	else
		cout << " prefix" << endl;

	// now, increase the indent level and visit, i.e. print the operand
	indent++;
	anExpNode->getOperand()->accept(this);
	indent--;

	int type = anExpNode->getOperand()->getType();
	if (type != 1 && type != 2 && type != 5 && type != 6) {
		cerr << "***ERROR: Invalid unary expression type from " << AstNode::type2string(type);
		cerr << ", expected numeric type." << endl;

		errorNum++;
	} else {
		if (type == 2 || type == 6) {
			anExpNode->setType(2);
		}
		else {
			anExpNode->setType(1);
		}
	}    
}

void
AstPrinter::visit(BinaryExpression *anExpNode) {
	// verify the integrity of the node
	if (anExpNode == NULL)
		throw AstException("AstPrinter::visit: BinaryExpression: NULL argument");

	if (anExpNode->getLeftOperand() == NULL)
		throw AstException("AstPrinter.visit: EBINARY left operand is NULL");

	if (anExpNode->getRightOperand() == NULL)
		throw AstException("AstPrinter.visit: EBINARY right operand is NULL");

	doIndent(indent);

	cout << AstNode::kind2string(anExpNode->getKind()) << ": " << " [" << anExpNode->getLineNo() << "] " << endl;
	cout.flush();

	doIndent(indent + 1);
	cout << AstNode::operator2string(anExpNode->getOperator()) << endl;
	cout.flush();

	// now, increase the indent level and visit, i.e. print (visit) the left and right operands
	indent++;
	anExpNode->getLeftOperand()->accept(this);
	anExpNode->getRightOperand()->accept(this);
	indent--;

	int ltype = anExpNode->getLeftOperand()->getType();
	int rtype = anExpNode->getRightOperand()->getType();
	int oper = anExpNode->getOperator();

	if (ltype != 1 && ltype != 2 && ltype != 5 && ltype != 6) {
		cerr << "***ERROR: Invalid type of left operand from " << AstNode::type2string(ltype);
		cerr << ", expected numeric type." << endl;

		errorNum++;
	} 

	if (rtype != 1 && rtype != 2 && rtype != 5 && rtype != 6) {
		cerr << "***ERROR: Invalid type of right operand from " << AstNode::type2string(rtype);
		cerr << ", expected numeric type." << endl;

		errorNum++;
	}
	if (oper >= 4 && oper <=9 ) {
		anExpNode->setType(3);
	} else {
		if (rtype == 2 || rtype == 6 || ltype == 2 || ltype == 6)
			anExpNode->setType(2);
		else
			anExpNode->setType(1);
	}
}

void
AstPrinter::visit(CastExpression *anExpNode) {
	// verify the integrity of the node
	if (anExpNode == NULL)
		throw AstException("AstPrinter::visit: CastExpression: NULL argument");

	if (anExpNode->getOperand() == NULL)
		throw AstException("AstPrinter::visit: ECAST operand is NULL");

	doIndent(indent);

	cout << AstNode::kind2string(anExpNode->getKind()) << ": " << " [" << anExpNode->getLineNo() << "] " << endl;
	cout.flush();

	doIndent(indent + 1);
	cout << AstNode::type2string(anExpNode->getCastToType()) << endl;

	// now, increase the indent level and visit, i.e. print the cast expression
	indent++;
	anExpNode->getOperand()->accept(this);
	indent--;

	int castType = anExpNode->getCastToType();
	int opType = anExpNode->getOperand()->getType();

	if (opType == 1 || opType == 2 || opType == 5 || opType == 6) {
		if (castType == 1 || castType == 5)
			anExpNode->setType(1);
		else
			anExpNode->setType(2);
	} else {		
		cerr << "***ERROR: Invalid type of cast operand";
		cerr << ", expected numeric type." << endl;

		errorNum++;
	}
}

void
AstPrinter::visit(MethodCallExpression *anExpNode) {

	// verify the integrity of the node
	if (anExpNode == NULL)
		throw AstException("AstPrinter::visit: NULL argument in MethodCallExpression");

	doIndent(indent);

	cout << AstNode::kind2string(anExpNode->getKind()) << ": " << " [" << anExpNode->getLineNo() << "] " << endl;
	cout.flush();

	doIndent(indent + 1);
	if (anExpNode->getClassName() != NULL)
		cout << anExpNode->getClassName() << ".";
	cout << anExpNode->getMethodName() << ": ";

	if (anExpNode->getClassName() == NULL) {
		if (symTab->lookup(anExpNode->getMethodName()) != NULL) {
			int kind = symTab->lookup(anExpNode->getMethodName())->getKind();
			if (kind != 2) {
				cerr << "***ERROR: Not a method." << endl;
				errorNum++;
			} else {
				cout << "symbol table reference set" << endl;
			}
		}
		else {
			cout << "no symbol table reference" << endl;
			cerr << "***ERROR: No such method." << endl;
			errorNum++;
		}
	} else {
		if (symTab->lookup(anExpNode->getMethodName()) && symTab->lookup(anExpNode->getClassName()) != NULL) {
			cout << "symbol table reference set" << endl;
		}
		else {
			cout << "no symbol table reference" << endl;
			cerr << "***ERROR: No such method." << endl;
			errorNum++;
		}
	}

	cout.flush();

	// check if any arguments have been provided
	if (anExpNode->getArguments() == NULL) {
		if (symTab->lookup(anExpNode->getMethodName()) != NULL) {
			if (symTab->lookup(anExpNode->getMethodName())->getNoArguments() == 0) {
				doIndent(indent + 1);
				cout << "No arguments" << endl;
			} else {
				cerr << "***ERROR: the number of parameter is not match." << endl;
				errorNum++;
			}
		}	
	} else {
		// visit (print) method call arguments
		for (int i = 0; i < anExpNode->getArguments()->size(); i++) {
			indent++;
			anExpNode->getArgument(i)->accept(this);
			indent--;
		}
		if (symTab->lookup(anExpNode->getMethodName()) != NULL) {
			int arguNum = anExpNode->getNoArguments();		
			int arguNumT = symTab->lookup(anExpNode->getMethodName())->getNoArguments();

			if (arguNum != arguNumT) {
				cerr << "***ERROR: the number of parameter is not match." << endl;
				errorNum++;
			} else {
				for (int i = 0; i < arguNum; i++) {
					int arguType = anExpNode->getArgument(i)->getType();
					int arguTypeT;

					map<string, vector<int> >::iterator it;
					it = parameterMap.find(string(anExpNode->getMethodName()));

					if (it == parameterMap.end()) {
						arguTypeT = symTab->lookup(anExpNode->getMethodName())->getIOMPtype();
					} else 	{				
						vector<int> t = it->second;
						arguTypeT = t.at(i);
					}

					if (arguTypeT == 5 && arguType == 1) {
						arguType = 5;
					}

					if (arguTypeT == 1 && arguType == 5) {
						arguType = 1;
					}

					if (arguTypeT == 6 && arguType == 2) {
						arguType = 6;
					}

					if (arguTypeT == 2 && arguType == 6) {
						arguType = 2;
					}

					if (arguTypeT == 1 && arguType == 2) {
						cerr << "***ERROR: the type of parameter is not match." << endl;
						errorNum++;
					} else if (arguTypeT == 1 && arguType == 6) {
						cerr << "***ERROR: the type of parameter is not match." << endl;
						errorNum++;
					} else {
						anExpNode->setType(symTab->lookup(anExpNode->getMethodName())->getReturnType());
					}					
				}			
			}	
		} 
	}
}

void
AstPrinter::visit(AssignStatement *anStmtNode) {
	int type = 8;
	// verify the integrity of the node
	if (anStmtNode == NULL)
		throw AstException("AstPrinter::visit: AssignStatement: NULL argument");

	if (anStmtNode->getExpression() == NULL)
		throw AstException("PrintStatementVisitor::visit: AssignStatement: NULL expression");

	doIndent(indent);

	cout << AstNode::kind2string(anStmtNode->getKind()) << ": " << " [" << anStmtNode->getLineNo() << "] " << endl;
	cout.flush();

	doIndent(indent + 1);
	cout << anStmtNode->getLHSName() << ": ";

	// print the symbol table entry, if defined
	if (symTab->lookup(anStmtNode->getLHSName()) != NULL) {
		cout << "symbol table reference set" << endl;

		int kind = symTab->lookup(anStmtNode->getLHSName())->getKind();
		if (kind == 4 || kind == 3 || kind == 1) {
			type = symTab->lookup(anStmtNode->getLHSName())->getType();
		} else {
			cerr << "***ERROR: Invalid left-hand-side element";
			cerr << ", expected FIELD, PARAMETER, VARIABLE." << endl;
			errorNum++;
		}
	}
	else {
		cout << "no symbol table reference" << endl;
		cerr << "***ERROR: " << anStmtNode->getLHSName() << " is not declared." << endl;
		errorNum++;
	}

	// print (visit) the index expression, if given
	if (anStmtNode->getIndex() != NULL) {
		indent = indent + 2;
		anStmtNode->getIndex()->accept(this);
		indent = indent - 2;
	}

	// print (visit) the right-hand side expression
	indent++;
	anStmtNode->getExpression()->accept(this);
	indent--;

	int rtype = anStmtNode->getExpression()->getType();
	if (type == 1 || type == 5)
		type = 1;
	if (type == 2 || type == 6)
		type = 2;
	if (rtype == 1 || rtype == 5)
		rtype = 1;
	if (rtype == 2 || rtype == 6)
		rtype = 2;

	if (type == 1) {
		if (rtype != 1) {
			cerr << "***ERROR: Can not assign " << AstNode::type2string(rtype) << " to " << AstNode::type2string(type) << endl;
			errorNum++;
		}
	} else if (type == 2) {
		if (rtype == 0 || rtype > 2) {
			cerr << "***ERROR: Can not assign " << AstNode::type2string(rtype) << " to " << AstNode::type2string(type) << endl;
			errorNum++;
		}
	} else {
		if (rtype != type) {
			cerr << "***ERROR: Can not assign " << AstNode::type2string(rtype) << " to " << AstNode::type2string(type) << endl;
			errorNum++;
		}
	}

}

void
AstPrinter::visit(WhileStatement *anStmtNode) {
	// verify the integrity of the node
	if (anStmtNode == NULL)
		throw AstException("AstPrinter::visit: WhileStatement: NULL argument");

	if (anStmtNode->getExpression() == NULL)
		throw AstException("AstPrinter::visit: WhileStatement: expression is NULL");

	if (anStmtNode->getBodyStatement() == NULL)
		throw AstException("AstPrinter::visit: WhileStatement: statement is NULL");

	doIndent(indent);

	cout << AstNode::kind2string(anStmtNode->getKind()) << ": " << " [" << anStmtNode->getLineNo() << "] " << endl;
	cout.flush();

	// print (visit) the control expression
	indent++;
	anStmtNode->getExpression()->accept(this);
	indent--;

	int type = anStmtNode->getExpression()->getType();
	if (type != 3) {
		cerr << "***ERROR: Control expression is " << AstNode::type2string(type) << ", expected " << AstNode::type2string(3) << endl;
		errorNum++;
	}

	// now, print (visit) the while statement body
	indent++;
	anStmtNode->getBodyStatement()->accept(this);
	indent--;
}

void
AstPrinter::visit(ForStatement *anStmtNode) {
	// verify the integrity of the node
	if (anStmtNode == NULL)
		throw AstException("AstPrinter::visit: ForStatement: NULL argument");

	if (anStmtNode->getInit() == NULL)
		throw AstException("AstPrinter::visit: ForStatement: initiatlization expression is NULL");

	if (anStmtNode->getTerm() == NULL)
		throw AstException("AstPrinter::visit: ForStatement: termination expression is NULL");

	if (anStmtNode->getUpd() == NULL)
		throw AstException("AstPrinter::visit: ForStatement: update expression is NULL");

	if (anStmtNode->getBodyStatement() == NULL)
		throw AstException("AstPrinter::visit: ForStatement: statement is NULL");

	doIndent(indent);

	cout << AstNode::kind2string(anStmtNode->getKind()) << ": " << " [" << anStmtNode->getLineNo() << "] " << endl;
	cout.flush();

	doIndent(indent + 1);

	cout << anStmtNode->getLHSName() << ": ";

	// print the symbol table entry, if defined
	if (symTab->lookup(anStmtNode->getLHSName()) != NULL)
		cout << "symbol table reference set" << endl;
	else {
		cout << "no symbol table reference" << endl;
		cerr << "***ERROR: " << anStmtNode->getLHSName() << " is not declared." << endl;
		errorNum++;
	}	

	// print (visit) the index expression, if given
	if (anStmtNode->getIndex() != NULL) {
		indent++;
		anStmtNode->getIndex()->accept(this);
		indent--;
	}

	// print (visit) the initialization expression
	indent++;
	anStmtNode->getInit()->accept(this);
	indent--;

	int type;
	if (symTab->lookup(anStmtNode->getLHSName()) != NULL) {
		int kind = symTab->lookup(anStmtNode->getLHSName())->getKind();
		if (kind == 4 || kind == 3 || kind == 1) {
			type = symTab->lookup(anStmtNode->getLHSName())->getType();
		} else {
			cerr << "***ERROR: Invalid left-hand-side element of initialization part";
			cerr << ", expected FIELD, PARAMETER, VARIABLE." << endl;
			errorNum++;
		}

		int rtype = anStmtNode->getInit()->getType();
		if (type == 1 || type == 5)
			type = 1;
		if (type == 2 || type == 6)
			type = 2;
		if (rtype == 1 || rtype == 5)
			rtype = 1;
		if (rtype == 2 || rtype == 6)
			rtype = 2;

		if (type == 1) {
			if (rtype != 1) {
				cerr << "***ERROR: Can not assign " << AstNode::type2string(rtype) << " to " << AstNode::type2string(type) << endl;
				errorNum++;
			}
		} else if (type == 2) {
			if (rtype == 0 || rtype > 2) {
				cerr << "***ERROR: Can not assign " << AstNode::type2string(rtype) << " to " << AstNode::type2string(type) << endl;
				errorNum++;
			}
		} else {
			if (rtype != type) {
				cerr << "***ERROR: Can not assign " << AstNode::type2string(rtype) << " to " << AstNode::type2string(type) << endl;
				errorNum++;
			}
		}	
	}

	// print (visit) the termination expression
	indent++;
	anStmtNode->getTerm()->accept(this);
	indent--;

	int ttype = anStmtNode->getTerm()->getType();
	if (ttype != 3) {
		cerr << "***ERROR: termination expression is " << AstNode::type2string(ttype) << ", expected " << AstNode::type2string(3) << endl;
		errorNum++;
	}

	// print (visit) the update expression
	indent++;
	anStmtNode->getUpd()->accept(this);
	indent--;

	// now, visit the while statement body
	indent++;
	anStmtNode->getBodyStatement()->accept(this);
	indent--;


}

void
AstPrinter::visit(IfStatement *anStmtNode) {
	// verify the integrity of the node
	if (anStmtNode == NULL)
		throw AstException("AstPrinter::visit: IfStatement: NULL argument");

	if (anStmtNode->getExpression() == NULL)
		throw AstException("AstPrinter::visit: IfStatement: expression is NULL");

	if (anStmtNode->getThenStatement() == NULL)
		throw AstException("AstPrinter::visit: IfStatement: then statement is NULL");

	doIndent(indent);

	cout << AstNode::kind2string(anStmtNode->getKind()) << ": " << " [" << anStmtNode->getLineNo() << "] " << endl;
	cout.flush();

	// print (visit) the control expression
	indent++;
	anStmtNode->getExpression()->accept(this);
	indent--;

	int controlType = anStmtNode->getExpression()->getType();
	if (controlType != 3) {
		cerr << "***ERROR: Control expression is " << AstNode::type2string(controlType) << ", expected " << AstNode::type2string(3) << endl;
		errorNum++;
	}

	// print (visit) the if's then statement
	indent++;
	anStmtNode->getThenStatement()->accept(this);
	indent--;

	// print (visit) the if's else statement, if present
	if (anStmtNode->getElseStatement() != NULL) {
		indent++;
		anStmtNode->getElseStatement()->accept(this);
		indent--;
	}


}

void
AstPrinter::visit(ReturnStatement *anStmtNode) {
	// verify the integrity of the node
	if (anStmtNode == NULL)
		throw AstException("AstPrinter::visit: NULL argument in ReturnStatement");

	doIndent(indent);

	cout << AstNode::kind2string(anStmtNode->getKind()) << ": " << " [" << anStmtNode->getLineNo() << "] " << endl;
	cout.flush();

	returnType = 0;

	// print (visit) the return value expression
	if (anStmtNode->getExpression() != NULL) {
		indent++;
		anStmtNode->getExpression()->accept(this);
		indent--;
		if (anStmtNode->getExpression()->getType() == 0) {
			string name = anStmtNode->getEntry()->getName();
			const char *c = name.c_str();
			if (symTab->lookup(c) != NULL) 
				returnType = symTab->lookup(c)->getReturnType();
		} else {
			returnType = anStmtNode->getExpression()->getType();
		}
	}
}

void
AstPrinter::visit(BlockStatement *anStmtNode) {
	// verify the integrity of the node
	if (anStmtNode == NULL)
		throw AstException("AstPrinter::visit: BlockStatement: NULL argument");

	if (anStmtNode->getStatements() == NULL)
		throw AstException("AstPrinter::visit: BlockStatement: statements are NULL");

	doIndent(indent);

	cout << AstNode::kind2string(anStmtNode->getKind()) << ": " << " [" << anStmtNode->getLineNo() << "] " << endl;
	cout.flush();

	// visit (print) all statements
	for (int i = 0; i < anStmtNode->getStatements()->size(); i++) {

		// check if this Statement is OK to visit
		if (anStmtNode->getStatements()->at(i) == NULL)
			throw AstException("AstPrinter::visit: BlockStatement: operand statement at position %d is NULL");

		// visit the block's next statement
		indent++;
		anStmtNode->getStatements()->at(i)->accept(this);
		indent--;
	}
}

void
AstPrinter::visit(MethodCallStatement *anStmtNode) {
	// verify the integrity of the node
	if (anStmtNode == NULL)
		throw AstException("AstPrinter::visit: MethodCallStatement: NULL argument");

	if (anStmtNode->getExpression() == NULL)
		throw AstException("PrintStatementVisitor::visit: MethodCallStatement: MethodCallExpression is NULL");

	doIndent(indent);

	cout << AstNode::kind2string(anStmtNode->getKind()) << ": " << " [" << anStmtNode->getLineNo() << "] " << endl;
	cout.flush();

	// print (visit) the MethodCallExpression (MethodCallStatement serves as a wrapper only)
	indent++;
	anStmtNode->getExpression()->accept(this);
	indent--;
}

void
AstPrinter::visit(EmptyStatement *anStmtNode) {
	// verify the integrity of the node
	if (anStmtNode == NULL)
		throw AstException("AstPrinter::visit: EmptyStatement: NULL argument");

	doIndent(indent);

	cout << AstNode::kind2string(anStmtNode->getKind()) << ": " << " [" << anStmtNode->getLineNo() << "] " << endl;
	cout.flush();
}
