#include <iostream>
#include <string>
using namespace std;
//#include "Node.h"
#define operator(i) (i=='+' || i == '-' || i == '*' || i == '/')

/*
bool isChar(char a) {
    a = int(a);
    if (((a >= 65) && (a <= 90)) || ((a >= 97) && (a <= 122)))
        return true;
    else return false;
}


bool isOperator(char a) {
    switch (a) {
    case '+': return true;
    case '-': return true;
    case '*': return true;
    case '/': return true;
    case '(': return true;
    case ')': return true;
    case '^': return true;
    default: return false;
    }
}
*/

int order(char op) {
    switch (op) {
    case '+': return 1;
    case '-': return 1;
    case '*': return 2;
    case '/': return 2;

    default: return 0;
    }
}

bool isHigher(char a, char b) {
    if (order(a) >= order(b)) return true;
    else return false;
}

string pop(string s) {
    return s.substr(0, s.size() - 1);
}

string toPostfix(string infix) {
    string postfix;
    char symbol;
    for (int i = 0; i < infix.length(); ++i) {

        symbol = infix[i]; 
        //if operand
        if (isdigit(symbol)) //숫자면 그냥 추가
        {
            postfix += symbol;
        }

        //if operator
        else if (operator(infix[i])) {
            //if stack is empty
            if (isEmpty()) {
                push(infix[i]);
            }

            //if stack not empty
            else if (!isEmpty()) {
                //if (
                if (infix[i] == '(') {
                    push(infix[i]);
                }

                //if ) is encountered pop till ( to postfix
                else if (infix[i] == ')') {
                    while (pop() != '(') {
                        postfix = postfix + " " + pop();
                    }
                    pop();
                }

                else {
                    //pop until tos has lesser precedence or tos is null.
                    char a = pop();
                    while (isHigher(a, infix[i])) {
                        postfix += a;
                        a = pop();
                    }

                    if (!(isHigher(a, infix[i])))
                        push(infix[i]);
                }
            }
        }

        else
            postfix += " ";
    }

    while (!isEmpty()) //스택에 남은 것 다 꺼내기 
        postfix = postfix + " " + pop();
    return postfix;

    return postfix;
}
