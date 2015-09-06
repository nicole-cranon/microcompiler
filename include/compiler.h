/*
   nicole cranon <nicole.cranon@ucdenver.edu>
   csci 4640, fall 2015
   assignment 3 - microcompiler -  a simple adhoc compiler
 */

#ifndef _COMPILER
#define _COMPILER

#include "parser.h"

namespace compiler {

  // arthmetic operators
  enum opToken {

    MinusOp = scanner::MinusOp,
		PlusOp = scanner::PlusOp

	};

	// types of expressions
	enum exprKind {

		idExpr,
		tempExpr,
		literalExpr

	};

	// placeholder for an arithmetic operator
	struct opRec;

	// place holder for an expression
	struct exprRec;

	/*
		 generate

		 precondition -
		 four strings:
		 s1 - operation code
		 s2 - operand1
		 s3 - operand2
		 s4 - result field

		 postcondition - 
		 produces a correctly formatted instruction string in the output file
		 compile::outFile
	 */
	void generate (const std::string& s1, 
			const std::string& s2, 
			const std::string& s3,
			const std::string& s4);

	/*
		 extract 

		 precondition -
		 requires a valid expression record (exprRec) object

		 postcondition -
		 if type of expression record is idExpr or tempExpr, returns the name of
		 the expression record. if type is literalExpr (integer literal), 
		 returns the integer value of the expression record
	 */
	std::string extract (const exprRec& e);

	/*
		 extractOp 

		 precondition -
		 requires a valid operator record (opRec) object

		 postcondition -
		 if type of op record type is PlusOp, returns "ADD, returns "SUB" 
		 otherwise
	 */
	std::string extractOp (const opRec& o);

	/*
		 lookUp 

		 precondition - 
		 the string name if an identifier

		 postcondition - 
		 returns true if the given identifier is already in the symbol table
		 returns false otherwise
	 */
	bool lookUp (const std::string& idName);

	/*
		 enter

		 precondition -
		 the string name of an identifier

		 postcondition -
		 returns nothing. enters the given identifier into the symbol table
	 */
	void enter (const std::string& idName);

	/*
		 checkId

		 precondition - 
		 the name of an identifier

		 postcondition -
		 returns nothing. checks for the given id in the symbol table, if it is 
		 not in the symbol table it will add it, does nothing otherwise
	 */
	void checkId (const std::string& idName);

	/*
		 getTemp

		 precondition -
		 variable maxTemp (tracks the number of temporary variables already 
		 allocated thus far) exists and has been intialized

		 postcondition - 
		 checks if the temp variable id already exists in the
		 symbol table, if it does not it is entered into the symbol table.
		 the temporary id is returned
	 */
	std::string getTemp ();

	/*
		 semantic routines
	 */

	/*
		 assign

		 precondition -
		 a target id, and a a source expression record

		 postcondition -
		 generates the code to store the source information in the target
	 */
	void assign (const std::string& target, const exprRec& e);

	/*
		 readId

		 precondition - 
		 an expression record

		 postcondition -
		 generates the code to read an expression into provided 
		 expression record
	 */
	void readId (exprRec& inVar);

	/*
		 writeExpr

		 precondition -
		 an expression record

		 postcondition -
		 generates the code to write an expression into the provided
		 expression record
	 */
	void writeExpr ();

	/*
		 genInfix

		 precondition -
		 e1 (expression record 1), op (operator), e2 (expression record 2)

		 postcondition -
		 generates the code for eTemp = e1 op e2 (i.e. A + B), returns eTemp
	 */
	exprRec genInfix (const exprRec& e1, const opRec& op, const exprRec& e2);

	/*
		 processId

		 precondition -
		 an expression record

		 postcondition -
		 declare an id, enter it into the semantic table, and build a 
		 corresponding semantic record
	 */
	void processId (exprRec& e);

	/*
		 processLiteral

		 precondition -
		 an expression record

		 postcondition -
		 convert literal to a numeric representation and build a semantic record
	 */
	void processLiteral (exprRec& e);

}

#endif

