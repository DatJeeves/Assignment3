#include "counterbox.h"
#include <fstream>
using namespace std;
/*Constructors establish a program's opening line in the file as well
as the bracket type this object holds.*/
CounterBox::CounterBox() {
	int openLine = 0;
	char bracketType = '(';
}

CounterBox::CounterBox(int openLine, char bracketType) {
	this->openLine = openLine;
	this->bracketType = bracketType;
}

//Destructor class, nothing to hard code in here.
CounterBox::~CounterBox() {

}


//Getters and setters for the private object variables.
int CounterBox::getOpenLine() {
	return openLine;
}
void CounterBox::setOpenLine(int openLine) {
	this->openLine = openLine;

}

char CounterBox::getBracketType() {
	return bracketType;
}
void CounterBox::setBracketType(char bracketType) {
	this->bracketType = bracketType;
}