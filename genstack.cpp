#include "genstack.h"
#include <exception>

using namespace std;

/*Constructors that assign an array size, sie and top variables,
but more importantly determine the TYPE of the array/stack.
by default a interger array of size 50 is created for a constructor
that was not given a value. I was debating if this is worth keeping 
and left it for now.*/
template <typename T>
GenStack<T>::GenStack(){
    arraySize = 50;
    myArray = new int[arraySize]; // Allocated on the heap
    size = arraySize;
    top = -1;

}

template <typename T>
GenStack<T>::GenStack(int maxSize){
 
   myArray = new T[maxSize];
  size = maxSize;
  arraySize = maxSize;
  top = -1;
 
}

/*Destructor for the Stack. Goes through the entire array and
deletes the variables at each index and then delete the array itself.*/
template <typename T>
GenStack<T>::~GenStack(){
    delete[] myArray; // frees up the heap stack
}

/*Checks wehether the stack is full-if so it automatically calls method
expand() to expand the stack. Then push recursively calls itself. If
Stack is not full, then it increments the top in preperation for a 
new entry into the Stack/array and assigns data  to the new top/index 
value.*/
template <typename T>
void GenStack<T>::push(T data){
 
    if (isFull()) {
        expand();
        push(data);
    }
    else {
        myArray[++top] = data;
    }  
}

/*NOTE: pop() assumes that you have called isEmpty to ensure you dont 
pop an empty stack.

This method assignes the top value of myArray/the Stack to a temp
variable popped which will be returned after decrementing top. 

NOTE: Top is used in isEmpty and isFull, not a search algorithm.*/
template <typename T>
T GenStack<T>::pop() {
    T popped = myArray[top]; //will this point to null later?
    --top; // just move the top down one since we dont care if we have not deleted the old counter box.
    return popped;
   
}

/*NOTE: Top is used in isEmpty and isFull, not a search algorithm.

Relies on the value of Top to see if the stack is empty (-1). 
Returns a boolean value.*/
template <typename T>
bool GenStack<T>::isEmpty() {
    if (top == -1) {        
        return true;
    }
    else {       
        return false;
    }
}

/*NOTE: Top is used in isEmpty and isFull, not a search algorithm.

Relies on the value of Top to see if the stack is FULL if it is one
less than size (size keeps track of the elements of the array/number
of CounterBoxes).
Returns a boolean value.*/
template <typename T>
bool GenStack<T>::isFull() {
    if (top == (size - 1)) {
        return true;
    }
    else {        
        return false;
    }
}


/*Referenced: http://www.fredosaurus.com/notes-cpp/newdelete/55dynexample.html
for help with expanding the array dynamically because we placed the array on 
the heap vs the stack.

Creates a new dynamic tempArray which is the original size of the array plus
the arraySize. We have to be mindful not to allocate too much on the heap
to avoid eating up unsed memory. A for loop is utilized to 
iterate through myArray and assign it's elements to tempArray.

Top is also reset at it's initial -1 for myArray and incremented
based on the number of elements inserted. */

template <typename T>
void GenStack<T>::expand() {

    int newSize = size + arraySize;

    T* tempArray = new T[newSize]; // Allocated on the heap

    top = -1;

    for (int i = 0; i < size; ++i) {
        ++top;
        tempArray[top] = myArray[i];
    }
    size = newSize;
    delete[] myArray; // frees up the heap stack
    myArray = tempArray;
}
