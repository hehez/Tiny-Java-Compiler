CXX		= g++
CPPFLAGS	= -Iast
CXXFLAGS	= -g
LDFLAGS		= -Last
LDLIBS		= -lAst -lfl
YACC        = bison -y
LEX         = flex


SRCS            = main.cpp lex.yy.c y.tab.c AstPrinter.cpp Entry.cpp SymTab.cpp CodeGen.cpp

HDRS            = y.tab.h Ast.h

OBJS	        = main.o y.tab.o lex.yy.o AstPrinter.o Entry.o SymTab.o CodeGen.o



# compile rules
#
COMPILE.cpp     = $(CXX) $(CPPFLAGS) $(CXXFLAGS)  -c
LINK.cpp        = $(CXX) $(CXXFLAGS) $(LDFLAGS)

.SUFFIXES: .cpp

.cpp.o:
	$(COMPILE.cpp) $(OUTPUT_OPTION) $<

all: tjc

tjc: Makefile $(OBJS) 
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS) $(LDLIBS) -g

# non-standard target dependencies
y.tab.o: Makefile y.tab.c ast/Ast.h
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) y.tab.c

lex.yy.o: Makefile lex.yy.c y.tab.h ast/Ast.h
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) lex.yy.c

y.tab.c y.tab.h: Makefile tjc.y
	$(YACC) -dv tjc.y

lex.yy.c: Makefile tjc.l
	$(LEX) tjc.l

#clean targets
clean:
	/bin/rm -f *.o

realclean: clean
	/bin/rm -f tjc

#################################################################
#################################################################
## Dependencies
##
#main.o: main.c
main.o: main.cpp ast/Ast.h
