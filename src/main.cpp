/*
  nicole cranon <nicole.cranon@ucdenver.edu>
  csci 4640, fall 2015
  assignment 3 - microcompiler - a simple adhoc compiler
 */

#include "compiler.h"
#include "parser.h"
#include <iostream>

int main (int argc, char* argv[]) {

	if (argc < 3){

		std::cerr << "\nNot enough arguments provided. " << "\n";

		return (EXIT_FAILURE);
	}

	char *sourceFilename = argv[1],
		*outFilename = argv[2];

	// instantiate the file stream for reading the provided file
	scanner::file.open (sourceFilename);

	// handle empty file
	if (scanner::file == NULL || scanner::file.fail()) {

		std::cerr << "\nError opening file. " << sourceFilename <<  "\n";

		return (EXIT_FAILURE);

	}

	// open for writing the output file
	compiler::outFile.open (outFilename);

	// handle empty file
	if (compiler::outFile == NULL || compiler::outFile.fail()) {

		std::cerr << "\nError opening file. " << outFilename << "\n";

		return (EXIT_FAILURE);

	}

	// parse provided file
	parser::systemGoal();

	// close the file read stream
	scanner::file.close();

	// close the file write stream
	compiler::outFile.close();

	return EXIT_SUCCESS;

}
