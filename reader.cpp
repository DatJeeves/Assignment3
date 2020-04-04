#include "genstack.h"
#include "counterbox.h"
#include "reader.h"
#include <fstream>
#include <exception>
using namespace std;

Reader::Reader(){
	
}

/*Reads a file and creates CounterBoxes based on the type of bracket/parenthese.
It then pops the CounterBoxes from the stack when it finds their closing bracket.*/

Reader::Reader(string filePath) {
	/*Will create a version of the stack using the generic GenStack class.
	 The default max size is passed in to the constructor to ensure that
	 we can change dynamically in the future by passing it via the user.*/
	GenStack<CounterBox> stack(50);


	fstream stream(filePath);
	string line;
	int lineNum = 0;

	string errorString = "";

	/*Checks whether the file exists and is good to read as well as if it is blank.
	Next it reads in the first line of the file.*/
	if (stream.good()) {
		while (!stream.eof()) {
			//stream >> line;
			getline(stream, line);
			++lineNum;

			/*Iterates through the line to see if it catches any of the open/close
			bracket parentheses. Logic is as such:

			If an open bracket is found, then create a CounterBox and push it to
			the stack.

			If a close bracket is found and the stack is empty, then throw an
			error message expecting an open bracket. If the stack is not empty,
			then pop off the latest CounterBox.*/
			for (char c : line) {
				if (stack.isFull()) {
					stack.expand();
				}
				//reads for parenthesies
				if (c == '(' || c == '[' || c == '{') {
					//create counterbox with that parenthese and line number
					CounterBox box = CounterBox(lineNum, c);
					stack.push(box);
				}
				else if (c == ')' || c == ']' || c == '}') {
					if (stack.isEmpty()) {
						cout<<"Line: " <<lineNum << " You have a closing '" << c << " that does not have an opening ";
						if (c == ')') {
							cout << "(" << endl;
						}
						else if (c == ']') {
							cout << "[" << endl;
						}
						else if (c == '}') {
							cout << "{" << endl;
						}
						else {
							cout << endl;
							cout << "ERROR: C VAR MISMATCH" << endl;
						}
						stream.close();
						throw "ERROR: Trying to pop from an empty stack";
					}
					 
					/* If we are here it means we got a closing bracket but of the wrong type.
					So I have found what the type of bracket is and what I was expecting and then 
					thew an exception out of reader.*/

					CounterBox popped = stack.pop();
					char reverse;
					if (c == ')' && popped.getBracketType() != '(') {
						reverse = c;
						stream.close();
						popped.~CounterBox();
						errorString = "Error Line ";
						errorString.append(std::to_string(lineNum));						
						errorString.append(" was expecting a ");
						if (popped.getBracketType() == '[') {
							errorString.append("]");
						}
						else if (popped.getBracketType() == '{') {
							errorString.append("}");
						}
						errorString.append(" found )");
						throw errorString;
					}
					else if (c == ']' && popped.getBracketType() != '[') {

						stream.close();
						popped.~CounterBox();
						errorString = "Error Line ";
						errorString.append(std::to_string(lineNum));
						errorString.append(" was expecting a ");
						if (popped.getBracketType() == '(') {
							errorString.append(")");
						}
						else if(popped.getBracketType() == '{') {
							errorString.append("}");
						}
						errorString.append(" found ] ");
						throw errorString;
					}
					else if (c == '}' && popped.getBracketType() != '{') {
						reverse = c;
						stream.close();
						popped.~CounterBox();
						errorString = "Error Line ";
						errorString.append(std::to_string(lineNum));
						errorString.append(" was expecting a ");
						if (popped.getBracketType() == '[') {
							errorString.append("]");
						}
						else if (popped.getBracketType() == '(') {
							errorString.append(")");
						}
						errorString.append(" found } ");
						throw errorString;
					}
															
				}				
			}
		}

		if (stack.isEmpty()) {
			cout << "Your file has No Errors!" << endl;
		}
		else {
			cout << "Reached end of file : " << endl;

			CounterBox popped = stack.pop();

			char reverse;
			cout << "Line: " << popped.getOpenLine() << " You have a " << popped.getBracketType() << " that does not have an ending ";
			if (popped.getBracketType() == '(') {
				reverse = ')';
			}
			else if (popped.getBracketType() == '[') {
				reverse = '}';
			}
			else if ( popped.getBracketType() == '{') {
				reverse = '}';
			}
			else {
				popped.~CounterBox();
				errorString = "Error Line ";
				errorString.append(std::to_string(lineNum));
				errorString.append(" Expected a "); 
				errorString.append(std::to_string(reverse));
				throw errorString;
			}
			cout << reverse << endl;
		}

		stream.close();	
	}
	else {
		cout << "Something went wrong trying to open the file " << filePath << endl;
	}

}

Reader::~Reader() {

}