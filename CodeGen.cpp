
#include "CodeGen.h"

using namespace std;

void
CodeGen::emitInstruction(const char *name) {
	jsm << "  " << name << endl;
}

void
CodeGen::emitInstruction(const char *name, int index) {
	jsm << "  " << name << " " << index << endl;
}

void
CodeGen::emitInstruction(const char *name, const char *label) {
	jsm << "  " << name << " " << label << endl;
}

void
CodeGen::emitField(const char *name, string fieldSpec) {
	jsm << "  " << name << " " << fieldSpec << endl;
}

void
CodeGen::emitField(const char *name, string fieldSpec, string typeSpec) {
	jsm << "  " << name << " " << fieldSpec << " " << typeSpec << endl;
}

void 
CodeGen::emitLabel(int num) {
	jsm << "Label" << num << ":" << endl;
}

void 
CodeGen::emitLabel(const char *name, int num) {
	jsm << "  " << name << " Label" << num << endl;
}

void 
CodeGen::emitMethodcall(string methodC) {
	jsm << "  " << "invokestatic " << methodC << endl;
}

void 
CodeGen::visit( MethodDeclaration *aDeclNode )
{
	// verify the integrity of the node
	if( aDeclNode == NULL )
		throw AstException( "CodeGen::visit: MethodDeclaration: NULL argument" );

	if( aDeclNode->getBody() == NULL )
		throw AstException( "CodeGen::visit: MethodDeclaration: body is NULL" );
	
	parameterType = 100;
	
	MethodDesc *e = new MethodDesc(aDeclNode->getName(), aDeclNode->getRetType(), aDeclNode->getParameters()->size(), aDeclNode->getParameters(), aDeclNode->getVariables());
	symTab->install(e);

	symTab->openMethodScope();
	vector<int> parameterVector;
	
	string returnT;
	switch(aDeclNode->getRetType()) {
		case 0:
			returnT = "V";
			break;
		case 1:
			returnT = "I";
			break;
		case 2:
			returnT = "F";
			break;
		case 5:
			returnT = "[I";
			break;
		case 6:
			returnT = "[F";
			break;	
	}
	
	paraDes = "";
	methodDes = "";
	int numV = aDeclNode->getVariables()->size();
	int numP = aDeclNode->getParameters()->size();
	
	// print (visit) the parameters
	if( aDeclNode->getParameters() != NULL ) {
		for( int i = 0; i < aDeclNode->getParameters()->size(); i++ ) {
			aDeclNode->getParameters()->at( i )->accept( this );
			parameterVector.push_back(parameterType);
		}
	}
	
	methodDes = string(aDeclNode->getName()) + "(" + paraDes + ")" + returnT;
	
	if(string(aDeclNode->getName()).compare("main") == 0) {
		jsm << ".method public static " << methodDes << endl;
	} else {
		jsm << ".method static " << methodDes << endl;
	}
	jsm << "  .limit stack 25\n";
	jsm << "  .limit locals " << numV + numP << endl;
	
	parameterMap.insert(pair<string, vector<int> >(string(aDeclNode->getName()), parameterVector));

	// print (visit) the variables
	if( aDeclNode->getVariables() != NULL ) {
		for( int i = 0; i < aDeclNode->getVariables()->size(); i++ ) {
			aDeclNode->getVariables()->at( i )->accept( this );
		}
	}
	
	// print (visit) the body
	aDeclNode->getBody()->accept( this );
	
	symTab->closeMethodScope();
	indexNum = 0;
	jsm << ".end method\n\n";
}

void
CodeGen::visit( FieldDeclaration *aDeclNode )
{
	// verify the integrity of the node
	if( aDeclNode == NULL )
		throw AstException( "CodeGen::visit: FieldDeclaration: NULL argument" );
		
	FieldDesc *e = new FieldDesc(aDeclNode->getName(), aDeclNode->getType(), aDeclNode->getInitValue());
	symTab->install(e);
	
	fieldLiteral = string(aDeclNode->getInitValue());

	int fieldT = aDeclNode->getType();
	switch (fieldT) {
		case 1:
			fieldType = "I";
			break;
		case 2:
			fieldType = "F";
			break;
		case 5:
			fieldType = "[I";
			break;
		case 6:
			fieldType = "[F";
			break;
	}
	fieldDes = className + "/" + aDeclNode->getName();		
	jsm << ".field static " << aDeclNode->getName() << " " << fieldType << endl;
	
	if(fieldLiteral.compare("0") == 0)
		fieldInit.push_back("  iconst_0\n");
	else if(fieldLiteral.compare("1") == 0)
		fieldInit.push_back("  iconst_1\n");
	else if(fieldLiteral.compare("2") == 0)
		fieldInit.push_back("  iconst_2\n");
	else if(fieldLiteral.compare("3") == 0)
		fieldInit.push_back("  iconst_3\n");
	else if(fieldLiteral.compare("4") == 0)
		fieldInit.push_back("  iconst_4\n");
	else if(fieldLiteral.compare("5") == 0)
		fieldInit.push_back("  iconst_5\n");
	else if(fieldLiteral.compare("0.0f") == 0 || fieldLiteral.compare("0.0F") == 0)
		fieldInit.push_back("  fconst_0\n");
	else if(fieldLiteral.compare("1.0f") == 0 || fieldLiteral.compare("1.0F") == 0)
		fieldInit.push_back("  fconst_1\n");
	else if(fieldLiteral.compare("2.0f") == 0 || fieldLiteral.compare("2.0F") == 0)
		fieldInit.push_back("  fconst_2\n");
	else
		fieldInit.push_back("  ldc " + fieldLiteral + "\n");
	
	fieldInit.push_back("  putstatic " + fieldDes + " " + fieldType + "\n");
}

void
CodeGen::visit( ParameterDeclaration *aDeclNode )
{
	// verify the integrity of the node
	if( aDeclNode == NULL )
		throw AstException( "CodeGen::visit: ParameterDeclaration: NULL argument" );

	parameterType = aDeclNode->getType();
	switch(parameterType) {
		case 1:
			paraDes += "I";
			break;
		case 2:
			paraDes += "F";
			break;
		case 4:
			paraDes += "Ljava/lang/String;";
			break;
		case 5:
			paraDes += "[I";
			break;
		case 6:
			paraDes += "[F";
			break;
		case 7:
			paraDes += "[Ljava/lang/String;";
			break;
	}
	
	ParameterDesc *e = new ParameterDesc(aDeclNode->getName(), aDeclNode->getType(), indexNum);
	symTab->install(e);
	indexNum++;
}

void 
CodeGen::visit( VariableDeclaration *aDeclNode )
{
	// verify the integrity of the node
	if( aDeclNode == NULL )
		throw AstException( "CodeGen::visit: VariableDeclaration: NULL argument" );
		
	VariableDesc *e = new VariableDesc(aDeclNode->getName(), aDeclNode->getType(), aDeclNode->getInitValue(), indexNum);
	symTab->install(e);
	
	string literal = string(aDeclNode->getInitValue());

	if(literal.compare("0") == 0)
		emitInstruction("iconst_0");
	else if(literal.compare("1") == 0)
		emitInstruction("iconst_1");
	else if(literal.compare("2") == 0)
		emitInstruction("iconst_2");
	else if(literal.compare("3") == 0)
		emitInstruction("iconst_3");
	else if(literal.compare("4") == 0)
		emitInstruction("iconst_4");
	else if(literal.compare("5") == 0)
		emitInstruction("iconst_5");
	else if(literal.compare("0.0f") == 0 || literal.compare("0.0F") == 0)
		emitInstruction("fconst_0");
	else if(literal.compare("1.0f") == 0 || literal.compare("1.0F") == 0)
		emitInstruction("fconst_1");
	else if(literal.compare("2.0f") == 0 || literal.compare("2.0F") == 0)
		emitInstruction("fconst_2");
	else if(aDeclNode->getInitLiteral()->getType() == 8) {
		emitInstruction("aconst_null");
		emitInstruction("astore", indexNum);
	} else
		emitInstruction("ldc", aDeclNode->getInitValue());
	
	if(aDeclNode->getInitLiteral()->getType() != 8) {
		if(aDeclNode->getInitLiteral()->getType() == 1 || aDeclNode->getInitLiteral()->getType() == 5) {
			emitInstruction("istore", indexNum);
		} else {
			emitInstruction("fstore", indexNum);
		}
	}
	
	indexNum++;
}

void
CodeGen::visit( ClassDeclaration *aDeclNode )
{
	// verify the integrity of the node
	if( aDeclNode == NULL )
		throw AstException( "CodeGen::visit: ClassDeclaration: NULL argument" );
	className = string(aDeclNode->getName());
	symTab = new SymTab();
	ClassDesc *e = new ClassDesc(aDeclNode->getName(), aDeclNode->getMembers());
	symTab->install(e);
	
	jsm.open ("jsm.txt");
	jsm << "; " << aDeclNode->getName() << ".jsm\n\n";
	jsm << ".bytecode 50.0\n";
	jsm << ".source " << aDeclNode->getName() << ".java\n\n";
	jsm << ".class public " << aDeclNode->getName();
	jsm << "\n.super java/lang/Object\n\n";
	
	symTab->openClassScope();
	indexNum = 0;
	labelNum = 0;
	int flag = 1;
	
	// check if members are present
	if( aDeclNode->getMembers() != NULL ) {
		// print (visit) members
		for( int i = 0; i < aDeclNode->getMembers()->size(); i++ ) {
			// check if this member is really there
			if( aDeclNode->getMember( i ) == NULL )
				throw AstException( "CodeGen::visit: DCLASS: member is NULL" );
			
			if(aDeclNode->getMember(i)->getKind() != 1 && flag ==1) {
				jsm << "\n.method public <init>()V\n";
				jsm << "  .limit stack 1\n";
				jsm << "  .limit locals 1\n";
				jsm << "  aload_0\n";
				jsm << "  invokespecial java/lang/Object/<init>()V\n";
				jsm << "  return\n";
				jsm << ".end method\n\n";
				flag = 0;
			}
			
			// now, visit the next class member
			indent++;
			aDeclNode->getMember( i )->accept( this );
			indent--;
		}
	}
	
	if(fieldInit.size() != 0) {
		jsm << ".method static ()V\n";
		jsm << "  .limit stack 1\n";
		jsm << "  .limit locals 0\n";
		for( int i = 0; i < fieldInit.size(); i++ ) {
			jsm << fieldInit.at(i);
		}	
		jsm << "  return\n";
		jsm << ".end method\n";
	}
	jsm.close();
}


void
CodeGen::visit( LiteralExpression *anExpNode )
{
	// verify the integrity of the node
	if( anExpNode == NULL )
		throw AstException( "CodeGen::visit: NULL argument in LiteralExpression" );

	string literal = string(anExpNode->getLiteral());

	if(literal.compare("0") == 0)
		emitInstruction("iconst_0");
	else if(literal.compare("1") == 0)
		emitInstruction("iconst_1");
	else if(literal.compare("2") == 0)
		emitInstruction("iconst_2");
	else if(literal.compare("3") == 0)
		emitInstruction("iconst_3");
	else if(literal.compare("4") == 0)
		emitInstruction("iconst_4");
	else if(literal.compare("5") == 0)
		emitInstruction("iconst_5");
	else if(literal.compare("0.0f") == 0 || literal.compare("0.0F") == 0)
		emitInstruction("fconst_0");
	else if(literal.compare("1.0f") == 0 || literal.compare("1.0F") == 0)
		emitInstruction("fconst_1");
	else if(literal.compare("2.0f") == 0 || literal.compare("2.0F") == 0)
		emitInstruction("fconst_2");
	else if(literal.compare("null") == 0)
		emitInstruction("aconst_null");
	else
		emitInstruction("ldc", anExpNode->getLiteral());
}

void
CodeGen::visit( ReferenceExpression *anExpNode )
{
	// verify the integrity of the node
	if( anExpNode == NULL )
		throw AstException( "CodeGen::visit: ReferenceExpression: NULL argument" );
	
	index_inc_dec = symTab->lookup(anExpNode->getName())->getIndex();
	if(symTab->lookup(anExpNode->getName())->getKind() == 1) {
		int fieldT = symTab->lookup(anExpNode->getName())->getType();	
		switch(fieldT) {
			case 1:
				fieldType = "I";
				break;
			case 2:
				fieldType = "F";
				break;
			case 5:
				fieldType = "[I";
				break;
			case 6:
				fieldType = "[F";
				break;
		}
		fieldDes = className + "/" + anExpNode->getName();
		emitField("getstatic", fieldDes, fieldType);	
	} else {
		if(anExpNode->getType() == 1) {
			emitInstruction("iload", symTab->lookup(anExpNode->getName())->getIndex());
		} else if (anExpNode->getType() == 2) {
			emitInstruction("fload", symTab->lookup(anExpNode->getName())->getIndex());
		}
		else {	
			emitInstruction("aload", symTab->lookup(anExpNode->getName())->getIndex());
		}
	}
	
	// print (visit) the index expression, if provided
	if( anExpNode->getExpression() != NULL ) {
		anExpNode->getExpression()->accept( this );
		if(anExpNode->getExpression()->getType() == 1)
			emitInstruction("iaload");
		else
			emitInstruction("faload");
	} 
}

void
CodeGen::visit( NewExpression *anExpNode )
{
	// verify the integrity of the node
	if( anExpNode == NULL )
		throw AstException( "CodeGen::visit: NewExpression: NULL argument" );

	if( anExpNode->getExpression() == NULL )
		throw AstException( "CodeGen::visit: NewExpression: size expression is NULL" );

	// now, increase the indent level and visit, i.e. print the size expression
	anExpNode->getExpression()->accept( this );
	
	if(anExpNode->getBaseType() == 5)
		emitInstruction("newarray int");
	else
		emitInstruction("newarray float");
}

void
CodeGen::visit( UnaryExpression *anExpNode )
{
	// verify the integrity of the node
	if( anExpNode == NULL )
		throw AstException( "CodeGen::visit: UnaryExpression: NULL argument" );

	if( anExpNode->getOperand() == NULL )
		throw AstException( "CodeGen.visit: UnaryExpression: operand is NULL" );
	
	// now, increase the indent level and visit, i.e. print the operand
	anExpNode->getOperand()->accept( this );
	
	if( anExpNode->isPostfix() ) {
		if(anExpNode->getKind() == 1) {
			emitField("getstatic", fieldDes, fieldType);
			if(anExpNode->getOperand()->getType() == 1) {
				emitInstruction("ldc 1");
				if(anExpNode->getOperator() == 10)
					emitInstruction("iadd");
				else
					emitInstruction("isub");				
			} else {
				emitInstruction("ldc 1.0f");
				if(anExpNode->getOperator() == 10)
					emitInstruction("fadd");
				else
					emitInstruction("fsub");
			}
			emitField("putstatic", fieldDes, fieldType);			
		} else {
			if(anExpNode->getOperand()->getType() == 1) {
				emitInstruction("iload", index_inc_dec);
				emitInstruction("ldc 1");
				if(anExpNode->getOperator() == 10)
					emitInstruction("iadd");
				else
					emitInstruction("isub");
				emitInstruction("istore", index_inc_dec);
			} else {
				emitInstruction("fload", index_inc_dec);
				emitInstruction("ldc 1.0f");
				if(anExpNode->getOperator() == 10)
					emitInstruction("iadd");
				else
					emitInstruction("isub");
				emitInstruction("fstore", index_inc_dec);
			}
		}		
	}

	if (anExpNode->getOperator() == 1) {
		if (anExpNode->getOperand()->getType() == 1)
			emitInstruction("ineg");
		else
			emitInstruction("fneg");
	}
	
}

void
CodeGen::visit( BinaryExpression *anExpNode )
{
	// verify the integrity of the node
	if( anExpNode == NULL )
		throw AstException( "CodeGen::visit: BinaryExpression: NULL argument" );

	if( anExpNode->getLeftOperand() == NULL )
		throw AstException( "CodeGen.visit: EBINARY left operand is NULL" );

	if( anExpNode->getRightOperand() == NULL )
		throw AstException( "CodeGen.visit: EBINARY right operand is NULL" );

	int leftT = anExpNode->getLeftOperand()->getType();
	int rightT = anExpNode->getRightOperand()->getType();
	// now, increase the indent level and visit, i.e. print (visit) the left and right operands
	anExpNode->getLeftOperand()->accept( this );
	if(leftT == 1 && rightT == 2)
		emitInstruction("i2f");
	anExpNode->getRightOperand()->accept( this );
	if(leftT == 2 && rightT == 1)
		emitInstruction("i2f");
	
	if(leftT == 5)
		leftT = 1;
	if(leftT == 6)
		leftT = 2;
	if(rightT == 5)
		rightT = 1;
	if(rightT == 6)
		rightT = 2;
	
	int operatorT = anExpNode->getOperator();
	switch(operatorT) {
		case 0:			
			if(leftT == 1 && rightT == 1)
				emitInstruction("iadd");
			else
				emitInstruction("fadd");
			break;
		case 1:			
			if(leftT == 1 && rightT == 1)
				emitInstruction("isub");
			else
				emitInstruction("fsub");
			break;
		case 2:			
			if(leftT == 1 && rightT == 1)
				emitInstruction("imul");
			else
				emitInstruction("fmul");
			break;
		case 3:			
			if(leftT == 1 && rightT == 1)
				emitInstruction("idiv");
			else
				emitInstruction("fdiv");
			break;
		case 4:			
			if(leftT == 1 && rightT == 1) {
				emitLabel("if_icmpne", elseLabel);
			}
			else {
				emitInstruction("fcmpg");
				emitLabel("ifne", elseLabel);
			}
			break;
		case 5:			
			if(leftT == 1 && rightT == 1) {
				emitLabel("if_icmpeq", elseLabel);	
			}	
			else {
				emitInstruction("fcmpg");
				emitLabel("ifeq", elseLabel);					
			}
			break;
		case 6:			
			if(leftT == 1 && rightT == 1) {
				emitLabel("if_icmpge", elseLabel);
			}
			else {
				emitInstruction("fcmpg");
				emitLabel("ifge", elseLabel);
			}
			break;
		case 7:			
			if(leftT == 1 && rightT == 1) {
				emitLabel("if_icmple", elseLabel);
			}	
			else {
				emitInstruction("fcmpg");
				emitLabel("ifle", elseLabel);
			}
			break;
		case 8:			
			if(leftT == 1 && rightT == 1) {
				emitLabel("if_icmpgt", elseLabel);
			}
			else {
				emitInstruction("fcmpg");
				emitLabel("ifgt", elseLabel);
			}
			break;
		case 9:			
			if(leftT == 1 && rightT == 1) {
				emitLabel("if_icmplt", elseLabel);
			}
			else {
				emitInstruction("fcmpg");
				emitLabel("iflt", elseLabel);
			}
			break;
	}
}

void
CodeGen::visit( CastExpression *anExpNode )
{
	// verify the integrity of the node
	if( anExpNode == NULL )
		throw AstException( "CodeGen::visit: CastExpression: NULL argument" );

	if( anExpNode->getOperand() == NULL )
		throw AstException( "CodeGen::visit: ECAST operand is NULL" );

	// now, increase the indent level and visit, i.e. print the cast expression
	anExpNode->getOperand()->accept( this );
	
	int castToType = anExpNode->getCastToType();
	int operandType = anExpNode->getOperand()->getType();
	
	if(castToType == 1 && operandType == 2)
		emitInstruction("f2i");
	else if(castToType == 2 && operandType == 1)
		emitInstruction("i2f");
}

void
CodeGen::visit( MethodCallExpression *anExpNode )
{
	// verify the integrity of the node
	if( anExpNode == NULL )
		throw AstException( "CodeGen::visit: NULL argument in MethodCallExpression" );

	int returnT = symTab->lookup(anExpNode->getMethodName())->getReturnType();
	string returnSpec;
	switch (returnT) {
		case 0:
			returnSpec = "V";
			break;
		case 1:
			returnSpec = "I";
			break;
		case 2:
			returnSpec = "F";
			break;
		case 5:
			returnSpec = "[I";
			break;
		case 6:
			returnSpec = "[F";
			break;				
	}

	// check if any arguments have been provided
	if( anExpNode->getArguments() == NULL ) {
		if(anExpNode->getClassName() == NULL) {
			methodCall = className + "/" + string(anExpNode->getMethodName()) + "()" + returnSpec;
			emitMethodcall (methodCall);
		} else {
			methodCall = "SimpleIO/" + string(anExpNode->getMethodName()) + "()" + returnSpec;
			emitMethodcall (methodCall);
		}
	}
	else {
		string argSpec = "";
		int argType;
		int argTypeT;
		map<string, vector<int> >::iterator it;
		it = parameterMap.find(string(anExpNode->getMethodName()));
		
		if(anExpNode->getClassName() == NULL) {
			methodCall = className + "/" + string(anExpNode->getMethodName()) + "(";
		} else {
			methodCall = "SimpleIO/" + string(anExpNode->getMethodName()) + "(";
		}
		
		// visit (print) method call arguments
		for( int i = 0; i < anExpNode->getArguments()->size(); i++ ) {
			anExpNode->getArgument( i )->accept( this );			
			argType = anExpNode->getArgument(i)->getType();
			
			if(it == parameterMap.end()) {
				argTypeT = symTab->lookup(anExpNode->getMethodName())->getIOMPtype();
			} else {				
				vector<int> t = it->second;
				argTypeT = t.at(i);
			}
			
			if(argTypeT == 2 && argType == 1)
				emitInstruction("i2f");
				
			switch (argTypeT) {
				case 1:
					argSpec += "I";
					break;
				case 2:
					argSpec += "F";
					break;
				case 4:
					argSpec += "Ljava/lang/String;";
					break;
				case 5:
					argSpec += "[I";
					break;
				case 6:
					argSpec += "[F";
					break;	
				case 7:
					argSpec += "[Ljava/lang/String;";
					break;
			}
		}
		
		methodCall = methodCall + argSpec + ")" + returnSpec;
		emitMethodcall (methodCall);
	}
}

void
CodeGen::visit( AssignStatement *anStmtNode )
{
	// verify the integrity of the node
	if( anStmtNode == NULL )
		throw AstException( "CodeGen::visit: AssignStatement: NULL argument" );

	if( anStmtNode->getExpression() == NULL )
		throw AstException( "PrintStatementVisitor::visit: AssignStatement: NULL expression" );

	int identK = symTab->lookup(anStmtNode->getLHSName())->getKind();
	int identT = symTab->lookup(anStmtNode->getLHSName())->getType();
	int identI = symTab->lookup(anStmtNode->getLHSName())->getIndex();
	switch(identT) {
		case 1:
			fieldType = "I";
			break;
		case 2:
			fieldType = "F";
			break;
		case 5:
			fieldType = "[I";
			break;
		case 6:
			fieldType = "[F";
			break;
	}
	fieldDes = className + "/" + anStmtNode->getLHSName();
	string fieldDesLocal = fieldDes;
	string fieldTypeLocal = fieldType;
	// print (visit) the index expression, if given
	if( anStmtNode->getIndex() != NULL ) {
		if(identK == 1) {
			emitField("getstatic", fieldDes, fieldType);
		} else {
			emitInstruction("aload", symTab->lookup(anStmtNode->getLHSName())->getIndex());
		}
		anStmtNode->getIndex()->accept( this );
		
		// print (visit) the right-hand side expression
		anStmtNode->getExpression()->accept( this );
		
		if(identT == 5) {
			emitInstruction("iastore");
		} else {
			emitInstruction("fastore");
		}
		
	} else {
		// print (visit) the right-hand side expression
		anStmtNode->getExpression()->accept( this );

		if(identK == 1) {	
			emitField("putstatic", fieldDesLocal, fieldTypeLocal);
		} else {
			if(identT == 8) {
				emitInstruction("aconst_null");
				emitInstruction("astore", identI);
			} else if(identT == 1)
				emitInstruction("istore", identI);
			else if(identT == 5)
				emitInstruction("astore", identI);
			else if(identT == 6)
				emitInstruction("astore", identI);
			else
				emitInstruction("fstore", identI);
		}	
	}
}

void
CodeGen::visit( WhileStatement *anStmtNode )
{
	// verify the integrity of the node
	if( anStmtNode == NULL )
		throw AstException( "CodeGen::visit: WhileStatement: NULL argument" );

	if( anStmtNode->getExpression() == NULL )
		throw AstException( "CodeGen::visit: WhileStatement: expression is NULL" );

	if( anStmtNode->getBodyStatement() == NULL )
		throw AstException( "CodeGen::visit: WhileStatement: statement is NULL" );

	againLabel = labelNum;
	int againLocal = againLabel;
	labelNum++;
	emitLabel(againLocal);
	
	elseLabel = labelNum;
	int elseLocal = elseLabel;
	labelNum++;
	
	// print (visit) the control expression
	anStmtNode->getExpression()->accept( this );

	
	// now, print (visit) the while statement body
	anStmtNode->getBodyStatement()->accept( this );
	
	emitLabel("goto", againLocal);
	emitLabel(elseLocal);
}

void
CodeGen::visit( ForStatement *anStmtNode )
{
	// verify the integrity of the node
	if( anStmtNode == NULL )
		throw AstException( "CodeGen::visit: ForStatement: NULL argument" );

	if( anStmtNode->getInit() == NULL )
		throw AstException( "CodeGen::visit: ForStatement: initiatlization expression is NULL" );

	if( anStmtNode->getTerm() == NULL )
		throw AstException( "CodeGen::visit: ForStatement: termination expression is NULL" );

	if( anStmtNode->getUpd() == NULL )
		throw AstException( "CodeGen::visit: ForStatement: update expression is NULL" );

	if( anStmtNode->getBodyStatement() == NULL )
		throw AstException( "CodeGen::visit: ForStatement: statement is NULL" );

	int identK = symTab->lookup(anStmtNode->getLHSName())->getKind();
	int identT = symTab->lookup(anStmtNode->getLHSName())->getType();
	int identI = symTab->lookup(anStmtNode->getLHSName())->getIndex();
	switch(identT) {
		case 1:
			fieldType = "I";
			break;
		case 2:
			fieldType = "F";
			break;
		case 5:
			fieldType = "[I";
			break;
		case 6:
			fieldType = "[F";
			break;
	}
	fieldDes = className + "/" + anStmtNode->getLHSName();
	
	// print (visit) the index expression, if given
	if( anStmtNode->getIndex() != NULL ) {
		if(identK == 1)
			emitField("getstatic", fieldDes, fieldType);
		else
			emitInstruction("aload", identI);
	
		anStmtNode->getIndex()->accept( this );
	}

	// print (visit) the initialization expression
	anStmtNode->getInit()->accept( this );
	
	if(identK == 1)
		emitField("putstatic", fieldDes, fieldType);
	else {
		if(identT == 1) {
			emitInstruction("istore", identI);
		} else if(identT == 2) {
			emitInstruction("fstore", identI);
		} else if(identT == 5) {
			emitInstruction("iastore");
		} else {
			emitInstruction("fastore");
		}
	}
	
	againLabel = labelNum;
	labelNum++;
	int againLocal = againLabel;
	emitLabel(againLocal);

	elseLabel = labelNum;
	int elseLocal = elseLabel;
	labelNum++;
	// print (visit) the termination expression
	anStmtNode->getTerm()->accept( this );
	
	// now, visit the while statement body
	anStmtNode->getBodyStatement()->accept( this );

	// print (visit) the update expression
	anStmtNode->getUpd()->accept( this );
	
	if(anStmtNode->getUpd()->getKind() == AstNode::EUNARY) {
		if(dynamic_cast<UnaryExpression *>(anStmtNode->getUpd())->getOperator() == 10 || dynamic_cast<UnaryExpression *>(anStmtNode->getUpd())->getOperator() == 11) {
			emitInstruction("pop");
		}	
	}
	
	emitLabel("goto", againLocal);
	emitLabel(elseLocal);
}

void
CodeGen::visit( IfStatement *anStmtNode )
{
	// verify the integrity of the node
	if( anStmtNode == NULL )
		throw AstException( "CodeGen::visit: IfStatement: NULL argument" );

	if( anStmtNode->getExpression() == NULL )
		throw AstException( "CodeGen::visit: IfStatement: expression is NULL" );

	if( anStmtNode->getThenStatement() == NULL )
		throw AstException( "CodeGen::visit: IfStatement: then statement is NULL" );

	elseLabel = labelNum;
	int elseLocal = elseLabel;
	labelNum++;

	// print (visit) the control expression
	anStmtNode->getExpression()->accept( this );


	endLabel = labelNum;
	int endLocal = endLabel;
	labelNum++;
	
	// print (visit) the if's then statement
	anStmtNode->getThenStatement()->accept( this );
	emitLabel("goto", endLocal);
	
	// print (visit) the if's else statement, if present
	if( anStmtNode->getElseStatement() != NULL ) {
		emitLabel(elseLabel);
		anStmtNode->getElseStatement()->accept( this );
	} else {
		emitLabel(elseLocal);
	}
		
	emitLabel(endLocal);
}

void
CodeGen::visit( ReturnStatement *anStmtNode )
{
	// verify the integrity of the node
	if( anStmtNode == NULL )
		throw AstException( "CodeGen::visit: NULL argument in ReturnStatement" );

	// print (visit) the return value expression
	if( anStmtNode->getExpression() != NULL ) {
		anStmtNode->getExpression()->accept( this );
		if(anStmtNode->getExpression()->getType() == 1)
			emitInstruction("ireturn");
		else
			emitInstruction("freturn");
	} else 
		emitInstruction("return");
}

void
CodeGen::visit( BlockStatement *anStmtNode )
{
	// verify the integrity of the node
	if( anStmtNode == NULL )
		throw AstException( "CodeGen::visit: BlockStatement: NULL argument" );

	if( anStmtNode->getStatements() == NULL )
		throw AstException( "CodeGen::visit: BlockStatement: statements are NULL" );

	// visit (print) all statements
	for( int i = 0; i < anStmtNode->getStatements()->size(); i++ ) {
		// check if this Statement is OK to visit
		if( anStmtNode->getStatements()->at( i ) == NULL )
			throw AstException( "CodeGen::visit: BlockStatement: operand statement at position %d is NULL" );

		// visit the block's next statement
		anStmtNode->getStatements()->at( i )->accept( this );
	}
}

void
CodeGen::visit( MethodCallStatement *anStmtNode )
{
	// verify the integrity of the node
	if( anStmtNode == NULL )
		throw AstException( "CodeGen::visit: MethodCallStatement: NULL argument" );

	if( anStmtNode->getExpression() == NULL )
		throw AstException( "PrintStatementVisitor::visit: MethodCallStatement: MethodCallExpression is NULL" );

	// print (visit) the MethodCallExpression (MethodCallStatement serves as a wrapper only)
	anStmtNode->getExpression()->accept( this );
}

void
CodeGen::visit( EmptyStatement *anStmtNode )
{
	// verify the integrity of the node
	if( anStmtNode == NULL )
		throw AstException( "CodeGen::visit: EmptyStatement: NULL argument" );
}
