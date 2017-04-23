/*************************************************
 Author: hehez
 Date: 4/23/17
 Description:
 **************************************************/
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#include "AstPrinter.h"
#include "CodeGen.h"

void fatal(const char *, const char *);
void error(const char *fmt, ...);

const char *pgm_name;

int errCnt = 0;

#ifdef YYDEBUG
extern int yydebug;
#endif

extern FILE *yyin;
extern int yylineno;
int yyparse (void);


// root of the abstract syntax tree for the expression
ClassDeclaration *expTree;
int errorNum;
ofstream jsm;
string fileName;

int main(int argc, const char **argv) {
    pgm_name = argv[0];
    
#ifdef YYDEBUG
    yydebug = 1;
#endif
    
    if(argc > 1) {
        yyin = fopen(argv[1], "r");
        fileName = string(argv[1]);
        
        if(yyin == NULL)
            fatal("Cannot open input file: ", argv[1]);
    }
    
    // parse an expression and construct a syntax tree for it
    // the root of the tree will be available as expTree
    expTree = NULL;
    //symTab = new SymTab();
    errorNum = 0;
    // yyparse();
    int result = yyparse();
    printf("Result of parsing: %d\n", result);
    // now, visit the tree using the AstPrinter visitor
    // but only if there were no errors
    if(errCnt == 0 && expTree != NULL) {
        expTree->accept(new AstPrinter (0));
        if(errorNum == 0) {
            expTree->accept(new CodeGen(0));
            cout << "Generated: jsm.txt" << endl;
        } else {
            remove("jsm.txt");
        }
    }
    return 0;
}

void error(const char *fmt, ...) {
    va_list ap;
    
    errCnt++;
    va_start(ap, fmt);
    fprintf(stderr, "Line %d: ", yylineno);
    vfprintf(stderr, fmt, ap);
    va_end(ap);
    fflush(stderr);
}

void fatal(const char *msg1, const char *msg2) {
    printf("%s%s\n", msg1, msg2);
    exit(1);
}
