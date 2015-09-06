/*
	 nicole cranon <nicole.cranon@ucdenver.edu>
	 csci 4640, fall 2015
	 assignment 3 - microcompiler - a simple adhoc compiler
 */

#include "compiler.h"
#include "parser.h"
#include <iostream>

namespace compiler {

	unsigned maxTemporary = 0,
					 lastSymbol = 0;

	std::string symbolTable[MAX_SYMBOL] = 0;

	std::ofstream outFile;

	struct opRec {

		opToken op;

	};

	struct exprRec {

		exprKind kind;
		int val;
		std::string name;

	};

	void generate (const std::string& s1,
			const std::string& s2,
			const std::string& s3,
			const std::string& s4) {

		if (s1.size() && s2.size() && s3.size())	{

			outFile << s1 << ',' << s2 << ',' << s3;

		}

		else if ( s1.size() && s2.size() && s3.size() && s4.size()) {

			outFile << s1 << ',' << s2 << ',' << s3 << ',' << s4;

		}

	}

	std::string extract (const exprRec& e) {

		switch (e.kind) {

			case (idExpr) :
			case (tempExpr):

				return (e.name);
				break;

			case (literalExpr):

				return (std::to_string(e.val));
				break;

			default :
				return "";

		}
	}

	std::string extractOp (const opRec& o) {

		switch (o.op) {

			case MinusOp : 

				return ("Sub");
				break;

			case PlusOp : 

				return ("Add");
				break;

		}

		return "";

	}

	bool lookUp (const std::string& idName) {

		bool found = false;

		for (int i = 0; i < MAX_SYMBOL; ++i) {

			if (symbolTable[i] ==  idName) {

				return found = true;

			}

		}

		return found = false;

	}

	void enter (const std::string& idName) {

		if (lastSymbol < MAX_SYMBOL)	{

			++lastSymbol;

			symbolTable[lastSymbol] = idName;

		}

		else {

			std::cerr << "\nError: Table Overflow!\n";

		}

	}

	void checkId (const std::string& idName) {

		if (!lookUp(idName))	{

			enter (idName);

			generate ("Declare", "S", "Integer", "");

		}

	}

	std::string getTemp () {

		++maxTemporary;

		std::string tempVarName = "Temp&" + std::to_string(maxTemporary);

		checkId(tempVarName);

		return tempVarName;

	}

	void assign (const exprRec& target,
			const exprRec& e) {

		generate ("Store", extract(e), target.name, "");

	}

	void readId (const exprRec& inVar) {

		generate ("Read", inVar.name, "Integer", "");

	}

	void writeExpr (const exprRec& target ) {

		generate ("Write", extract(target), "Integer", "");

	}

	exprRec genInfix (const exprRec& e1,
			const opRec& op,
			const exprRec& e2) {

		exprRec newExpr;
		newExpr.kind = tempExpr;

		newExpr.name = getTemp();

		generate (extractOp (op), extract (e1), extract (e2), newExpr.name);

		return newExpr;

	}

	void processId (exprRec& e) {

		checkId (scanner::tokenBuffer);

		e.kind = idExpr;
		e.name = scanner::tokenBuffer;

	}

	void processLiteral (exprRec& e) {

		e.kind = literalExpr;
		e.val = std::stoi(scanner::tokenBuffer);

	}

	void processOp (opRec& o) {

		if (parser::currentToken == scanner::PlusOp) {

			o.op = PlusOp;

		}

		else if (parser::currentToken == scanner::MinusOp) {

			o.op = MinusOp;

		}

	}

	void finish () {

		outFile << "Halt";

	}

	

}
