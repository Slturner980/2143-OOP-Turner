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
//       Input.txt
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
 *      - ~Stack()
 *      - void Push()
 *      - int Pop()
 *      - bool empty()
 *      - bool full()
 *      - void Print()
 *      - int* MoreArray()
 *      - int* LessArray()
 *      - void TrackSize()
 *      - void Readfile()
 *      - void Writefile()
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
 *  S.Readfile();
 *      
 */

class Stack {
private:
    int *S;          //array pointer
    int capacity;    //max stack size
    int top;         //current top (index)
    int size;        //current num items
    int maxsize = 0; //max size that the array got 
    int fileval;     //int value from input file.
    string filestr;  //string value from input file
    ifstream fin;    //input stream
    ofstream fout;   //output stream

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
        cout << "Name: Sarah Turner" << endl;
        cout << "Program: P01" << endl;
        cout << "Date: 15 Sep 2020\n" << endl;
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

        cout << "Name: Sarah Turner" << endl;
        cout << "Program: P01" << endl;
        cout << "Date: 15 Sep 2020\n" << endl;
    }
   
    /**
     * Stack:
     *    Deconstructor.
     * Params:
     *    Void
     * 
     * Returns:
     *     Void
     */

    ~Stack(){
        Writefile(); // writes the output file.
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
          TrackSize();          // Tracks the max size
        }

      else{
        top++;              
        size++;            
        S[top] = data;    
        TrackSize();
        }
    }

    /**
     * Pop:
     *    remove item from stack, checks if
     *    stack is empty or half full.
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
      if(size < (capacity/2)-1 ){

        LessArray();        // Half the Array
        int data = S[top];  // pull item from stack
        top--;              // shrink the stack
        size--;             // update our size
        return data;        // send item back
      }

      // removes from the stack.
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
        cout << "+ : " << capacity;
        capacity *= 2;
        cout << " -> " << capacity << endl;

        // Adds 2 when there not any capacity
        if(capacity == 0){
            capacity += 2;
         } 

        // Allocate new array twice as big
        int *S2 = new int [capacity];

        // Copy data from S to S2
        for(int i = 0;i<size;i++){
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

        cout << "- : " << capacity;
        capacity /= 2; 
        cout << " -> " << capacity << endl;

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
    *  TrackSize:
    *    Tracks how high the stack size got.
    * Params:
    *    Void
    * 
    * Returns:
    *     Void
    */    

    void TrackSize(){
        if(size > maxsize){
            maxsize = size;
        }
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

    /**
    *  Readfile:
    *    Reads and interprets the input file given.
    * Params:
    *    Void
    * 
    * Returns:
    *     Void
    */  

void Readfile(){
    fin.open("input.txt");

    while(fin >> filestr){
        
        // reads an int value if it reads 'Push'    
        if (filestr == "push"){
             fin >> fileval;
             Push(fileval);
             
        }
        else{
            Pop();
        }
        
     }
     
    fin.close();
}

/**
    *  Writefile:
    *    Writes out info in a seperate output file.
    * Params:
    *    Void
    * 
    * Returns:
    *     Void
    */  

void Writefile(){
    fout.open("output.txt");

    fout << "Name: Sarah Turner" << endl;
    fout << "Program: P01" << endl;
    fout << "Date: 15 Sep 2020" << endl;
    fout << "Start size: 10 " << endl;
    fout << "Max size: "<< maxsize << endl;
    fout << "Ending size: " << size << endl;

    fout.close();
}
};


int main() {
    Stack test;
    test.Readfile();
}
