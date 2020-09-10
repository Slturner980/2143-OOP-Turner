///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Sarah Turner
// Email:            slturner980@gmail.com
// Label:            P01
// Title:            Array Based Stack and Resizeing
// Course:           2143
// Semester:         Fall 2020
//
// Description:
//        Implementation of an array based stack that holds integers.
//        When The Stack is full, the array will double it's capacity.
//        When the stack is less than half capacity, the Array will shrink
//        in half.
//
// Usage:
//       Nothing special right now.
//
// Files:            
//       None
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 * Stack
 * 
 * Description:
 *      Integer array based stack implementation
 * 
 * Public Methods:
 *      - Stack()
 *      - Stack(int)
 *      - void Push()
 *      - int Pop()
 *      - bool empty()
 *      - bool full()
 *      - void Print()
 *      - int* MoreArray()
 *      - int* LessArray()
 *
 * Private Methods:
 *      - None
 * 
 * Usage: 
 * 
 *  Stack S;
 *  S.Push(80);
 *  S.Push(90);
 *  S.Print();
 *  int x = S.Pop();
 *      
 */

class Stack {
private:
    int *S;       //array pointer
    int capacity; //max stack size
    int top;      //current top (index)
    int size;     //current num items
public:
    /**
     * Stack:
     *    Constructor.
     * Params:
     *    void
     * 
     * Returns:
     *     Void
     */
    Stack() {
        capacity = 10;          // set array size
        S = new int[capacity];  // allocate new memory
        top = -1;               // initialize top of stack
        size = 0;               // set stack to empty
    }
  
    /**
     * Stack:
     *    Constructor.
     * Params:
     *    int : capacity
     * 
     * Returns:
     *     Void
     */
    Stack(int cap) {
        capacity = cap;         // set array size      
        S = new int[capacity];  // allocate new memory
        top = -1;               // initialize top of stack
        size = 0;               // set stack to empty
    }

    

    /**
     * Push:
     *    Push item onto stack.
     * Params:
     *    int : data
     * 
     * Returns:
     *     Void
     */
    void Push(int data) {

        // if the array is full
      if (top == capacity - 1){

          MoreArray();          // Double the Array
          top++;                // move top of stack up
          size++;               // increment size
          S[top] = data;        // add item to array

        }

      else{
        top++;              // move top of stack up
        size++;             // increment size
        S[top] = data;      // add item to array
        }
    }

    /**
     * Pop:
     *    remove item from stack.
     * Params:
     *    void
     * 
     * Returns:
     *     int
     */
    int Pop() {
    
      // if the array is empty
      if(top == -1){
        cout << "Error: Stack empty!"<< endl;
        return -1;
      }

      // if the array is less than half full
      if(size <= (capacity/2) ){

        LessArray();        // Half the Array
        int data = S[top];  // pull item from stack
        top--;              // shrink the stack
        size--;             // update our size
        return data;        // send item back
      }

      
      else{
        int data = S[top];  
        top--;              
        size--;             
        return data;       
      }
    }

    /**
     * Empty:
     *    is the stack empty?
     * Params:
     *    void
     * 
     * Returns:
     *     bool : true == stack is empty
     */
    bool Empty() {
        //return size == 0;
        return top == -1;
    }

    /**
     * Full:
     *    is the stack full?
     * Params:
     *    void
     * 
     * Returns:
     *     bool : true == stack is full
     */
    bool Full() {
        return top == capacity - 1;
    }

    /**
     * Print:
     *    Used so we can inspect our stack.
     * Params:
     *    void
     * 
     * Returns:
     *     void
     */    
    void Print() {
        for (int i = top; i >= 0; i--) {
            cout << S[i] << endl;
        }
    }

    /**
     * MoreArray:
     *    Doubles the array's capacity.
     * Params:
     *    int* : S
     * 
     * Returns:
     *     int* : S
     */    
  
   int* MoreArray(){
    
    capacity *= 2;
    // Adds 2 when there not any capacity
    if(capacity == 0){

      capacity += 2;

    } 

    // Allocate new array twice as big
    int *S2 = new int [capacity];

    // Copy data from S to S2
    for(int i = 0;i<capacity;i++){
      S2[i] = S[i];
    }

    // Point S to new array
     S = S2;
    return S;
    
    }
  
  /**
  *  LessArray:
  *    Halves the array's capacity.
  * Params:
  *    int* : S
  * 
  * Returns:
  *     int* : S
  */    

  int* LessArray(){

    capacity /= 2; 
    // Allocate new array half as big
    int *S2 = new int[capacity];

    // Copy data from S to S2
    for(int i = 0;i<capacity;i++){
      S2[i] = S[i];
    }

    // Point S to new array
     S = S2;

    return S;
    
    }

    /**
     * Overloaded ostream <<
     *    Lets us print a stack using cout
     * Params:
     *    ostream &os   : instance of ostream passed in by reference
     *    const Stack   : instance of stack passed in using const so 
     *                    it cannot be changed
     * 
     * Returns:
     *     ostream 
     */
    friend ostream &operator<<(ostream &os, const Stack s) {
        for (int i = s.top; i >= 0; i--) {
            os << s.S[i] << endl;
        }
        return os;
    }


};



int main() {

    Stack test(10);

    test.Push(4);
    test.Pop();
    test.Push(65);
    cout << test << endl;
    test.Push(11);
    test.Push(76);
    test.Push(5);
    test.Push(97);
    test.Push(41);
    test.Push(14);
    test.Push(9);
    test.Push(11);
    test.Pop();
    test.Pop();
    test.Pop();
    test.Pop();
    test.Push(81);
    test.Push(53);
    test.Push(60);
     cout << test << endl;



}
