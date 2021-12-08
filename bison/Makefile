# @author Adrian Ulises Mercado Martínez
# @version 1, 3/11/2021
CXX  = g++
EXE = compiler

CXXDEBUG = -g -Wall
CXXSTD = -std=c++14
CXXFLAGS = -Wno-deprecated-register -O0  $(CXXDEBUG) $(CXXSTD)

CPPOBJ = main Generator Quad Sym SymTab Type TypeTab
SOBJ =  parser lexer driver

FILES = $(addsuffix .cpp, $(CPPOBJ))
OBJS  = $(addsuffix .o, $(CPPOBJ))

CLEANLIST =  $(addsuffix .o, $(OBJ)) $(OBJS) Driver.o\
				parser.tab.cc parser.tab.hh \
				location.hh position.hh \
			    stack.hh parser.output Parser.o \
				lexer.o Lexer.cpp $(EXE)\

.PHONY: all

all: wc

wc: $(FILES)
	$(MAKE) $(SOBJ)
	$(MAKE) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXE) $(OBJS) Parser.o lexer.o Driver.o$(LIBS)


parser: parser.yy
	bison -d -v parser.yy
	$(CXX) $(CXXFLAGS) -c -o Parser.o parser.tab.cc

lexer: lexer.ll
	flex $<
	$(CXX)  $(CXXFLAGS) -c Lexer.cpp -o lexer.o

driver: Driver.cpp Pila.hpp
	$(CXX) $(CXXFLAGS) -c Driver.cpp -o Driver.o
.PHONY: clean
clean:
	rm -rf $(CLEANLIST)