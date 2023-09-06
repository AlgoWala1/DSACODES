//Program to convert postfix to infix and evaluate
#include<iostream>
#include<math.h>
#define SIZE 30//assuming 30 must be the max
using namespace std;
float result(char *arr)
{
    float result = 0.0;//for division
    int index = 1;//start from 1st
    float a,b;//a for first operand b for second operand
    char ch;
    a = (*arr) - 48;//convert into integer
   while(*(arr + index)!= NULL)
    {
        ch = *(arr + index);
        switch(ch){
            case '+':
            result = (a+b);
            a = result;
            break;
            
            case '*':
             result = (a*b);
             a = result;
             break;
             
            case '-':
            result = (a-b);
            a = result;
            break;
            
            case '/':
            result = (a/b);
            a = result;
            break;
            
            case '^':
            result = pow(a,b);
            a = result;
            break;

            default://integer value encountered
            b = (float)ch - 48;//convert into integer
            break;
        }
        index++;
    }
    return result;
}
int main(){
    char instring[SIZE];
    int index = 0;
    cout<<"Enter postfix expression: ";
    cin>>instring;
    cout<<"Result is : "<<result(instring);
}
