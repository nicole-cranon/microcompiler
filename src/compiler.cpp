/*
  nicole cranon <nicole.cranon@ucdenver.edu>
  csci 4640, fall 2015
  assignment 3 - microcompiler - a simple adhoc compiler
 */

#include "compiler.h"

namespace compiler {

  struct opRec {

    opToken op;

  };

  struct exprRec {

    exprKind kind;
    int val;
    std::string name;

  };

  void readId (exprRec& inVar);

}
