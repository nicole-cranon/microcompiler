/*
  nicole cranon <nicole.cranon@ucdenver.edu>
  csci 4640, fall 2015
  assignment 3 - microcompiler -  a simple adhoc compiler
 */

#ifndef _COMPILER
#define _COMPILER

#include "../src/microparser/src/parser.h"

namespace compiler {

  typedef scanner::token token;
  typedef scanner::file source_file;
  typedef scanner::token_type token_type;
  typedef scanner::tokenBuffer tokenBuffer;

  typedef enum {

    MinusOp = scanner::MinusOp,
    PlusOP = scanner::PlusOp

  }

  struct opRec {

    opToken op;

  }
  
  /*
    compile 

    preconditions - 
    requires the name of a source code file

    postcondition - 
    compiles the file into a default output file 'out'
   */
  void compile (const char* sourceFile);

  /*
    compile 

    preconditions - 
    requires the name of a source code file, and the name of the output file


    postcondition - 
    compiles the file into a default output file 'out'
   */
   void compile (const char* sourceFile, const char* outFile);



}

#endif

