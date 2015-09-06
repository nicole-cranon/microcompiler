/*
  nicole cranon <nicole.cranon@ucdenver.edu>
  csci 4640, fall 2015
  assignment 3 - microcompiler - a simple adhoc compiler
 */

#include "compiler.h"
#include <iostream>

int main (int argc, char* argv[]) {
  
  compiler::opToken Current;
  Current = compiler::PlusOp;

  std::cout << scanner::token_type[Current] << std::to_string(3) << '\n';

}
