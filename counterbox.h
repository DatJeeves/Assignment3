#ifndef COUNTERBOX_H
#define COUNTERBOX_H
#include <iostream>

using namespace std;

class CounterBox {
	// This class keeps track of the line and the type of open bracket encountered
	// This class can be adapted easily to track any kind of char we want to keep track of
	public:
		CounterBox();
		CounterBox(int openLine, char bracketType);
		~CounterBox();

		int getOpenLine();
		void setOpenLine(int openLine);

		char getBracketType();
		void setBracketType(char bracketType);




	private:
		int openLine;
		char bracketType;

};

#endif