
#ifndef __CODEGEN_H__
#define __CODEGEN_H__

#include <iostream>
#include <fstream>
#include "Ast.h"
#include "SymTab.h"

using namespace std; 

extern ofstream jsm;

class CodeGen: public AstVisitor {

	private:
		
		int indent;
		SymTab *symTab;
		int indexNum;
		map<string, vector<int> > parameterMap;
		int parameterType;
		int elseLabel;
		int endLabel;
		int againLabel;
		int labelNum;
		string className;
		string methodDes;
		string methodCall;
		string fieldDes;
		string fieldType;
		string fieldLiteral;
		string paraDes;
		vector<string> fieldInit;
		int index_inc_dec;

		// indent for nested printing
		void doIndent( int lev )
		{
			// indent
			for( int i = 0; i < lev; i++ )
			cout << "  ";
		}

	public:

		CodeGen( int indentLevel )
		{
			indent = indentLevel;
		}

		void emitInstruction( const char *name );
		void emitInstruction( const char *name, int index );
		void emitInstruction( const char *name, const char *label );
		void emitField( const char *name, string fieldSpec );
		void emitField( const char *name, string fieldSpec, string typeSpec );
		void emitLabel( int num );
		void emitLabel( const char *name,  int num );
		void emitDirective( const char *name, const char *arg );
		void emitMethodcall( string methodDesc );
			
		void visit( MethodDeclaration *aDeclNode );
		void visit( FieldDeclaration *aDeclNode );
		void visit( ParameterDeclaration *aDeclNode );
		void visit( VariableDeclaration *aDeclNode );
		void visit( ClassDeclaration *aDeclNode );
		void visit( LiteralExpression *anExpNode );
		void visit( ReferenceExpression *anExpNode );
		void visit( NewExpression *anExpNode );
		void visit( UnaryExpression *anExpNode );
		void visit( BinaryExpression *anExpNode );
		void visit( CastExpression *anExpNode );
		void visit( MethodCallExpression *anExpNode );
		void visit( AssignStatement *anStmtNode );
		void visit( WhileStatement *anStmtNode );
		void visit( ForStatement *anStmtNode );
		void visit( IfStatement *anStmtNode );
		void visit( ReturnStatement *anStmtNode );
		void visit( BlockStatement *anStmtNode );
		void visit( MethodCallStatement *anStmtNode );
		void visit( EmptyStatement *anStmtNode );
};

#endif
