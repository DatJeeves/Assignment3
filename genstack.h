#ifndef GENSTACK_H
#define GENSTACK_H
#include <iostream>
using namespace std;

//STACK class

/*Generic class type so that the stack can contain a specified type
(Specified in Reader class).*/
template<typename T>
class GenStack{
  public:
	  /*Constructors and Destructor*/
    GenStack();
    GenStack(int maxSize);
    ~GenStack();

	//Fictions to augment the stack
    void push(T data); 
    T pop();
    void expand();

    //aux funtions
    char peek(); //AKA top
    bool isEmpty();
    bool isFull();

private:
	/*These private variables are used to keep track
	of the stack. The Top keeps track of the top index,
	size keeps track of the amount of elements in the array
	and arraySize is the maximum size of the array.*/
    int top; //need ti make public?
    int size;
    int arraySize;

	//Generic array
    T *myArray;
};

#endif