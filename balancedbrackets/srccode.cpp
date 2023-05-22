#include <iostream>
#include <climits>

using namespace std;

#define CAPACITY 50

/*

PASTE HERE YOUR STACK FUNCTIONS FROM PROBLEM 1 SINCE THE balancedBrackets FUNCTION BELOW
IS EXPECTED TO BE BASED ON A STACK*/
class Stack
{
private:
        int topvalue;
        static const int numberofelements= CAPACITY;
        int data[numberofelements];


public:
    //  default Constructor assigns objects 0
        Stack()
        {topvalue = -1;
        for(int i=0;i<numberofelements;i++)
        {
            data[i]=0;
        }
        }


        int size() //returns number of elements in the stack
        {
            return (topvalue + 1);
        }

        bool isEmpty()// returns true if there are no elements and false otherwise
        {
            if(topvalue == -1)
                {
                    return true;
                }
            else
            {
                return false;
            }
        }


        bool push(int newElement) {
            if(topvalue == 4)
            {
                return false;
            }
            else
            {
              topvalue++;
              data[topvalue]=newElement;//stores value pushed in the argument of the function
            }

        }
        // returns true if the push was successful and false otherwise. E.g. pushing onto a full stack should return false

        /* pops an element from the stack*/
        int pop()
         {
             if(isEmpty())
                return 0;
            else
               {
                int popvalue=data[topvalue];
                data[topvalue]=0;
                topvalue--;
                return popvalue;
               }
        }

        int peek()
        {
            int p;
            if(isEmpty())
                return 0;
            else
            return data[p];
        }
        // returns the element at the top of the stack without popping it. Peeking at an empty stack should return INT_MAX

        void printStack() {
            for(int i=0;i<=4;i++)
            {
                cout<<data[i]<<" ";
            }
        }//prints elements in the stack separated by a space





};



int balancedBrackets(Stack &myStack, string brackets)
{
    // TODO: implement your solution here
int i = 0;
while(brackets[i] != '\0')
{

            char br = brackets[i++];

            // Left brackets
            if(br == '(' || br == '{' || br == '[' || br == '<')
            {
                myStack.push(br);
                continue;
            }

            // Check if right brackets match
            switch(br) {
                case ')': if(myStack.pop() == '(') break; else return --i;
                case '}': if(myStack.pop() == '{') break; else return --i;
                case ']': if(myStack.pop() == '[') break; else return --i;
                case '>': if(myStack.pop() == '<') break; else return --i;
                default: return --i;
            }
        }

        if(!myStack.isEmpty())
            return i; // Unbalanced left bracket(s)

        return -1;
}

int main() {
    Stack myStack;

    int result;

    result = balancedBrackets(myStack, "{()}");
    // you can change the string of brackets to test various balanced and unbalanced instances

    if (result == -1)
        cout << "The brackets are balanced!" << endl;
    else
        cout << "The brackets are not balanced! First index causing imbalance: " << result  << endl;

    return 0;
}
