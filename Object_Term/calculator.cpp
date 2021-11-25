#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Node.h"
#include "calculate.h"
using namespace std;

#define operator(i) (i=='+' || i == '-' || i == '*' || i == '/')
#define operator_s(i) (i=="+" || i == "-" || i == "*" || i == "/")
#define paren(i) (i == '(' || i == ')')
#define paren_s(i) (i == "(" || i == ")")

string form(string exp) { //16진수, 2진수를 10진수로 맞춤
    string result = "";
    char symbol;
    int temp = 0;
    int i = 0;
    int ten = 1000;

    while(i < exp.size()){
        if (i < exp.size()-1 && exp[i] == '0') {
            if (exp[i + 1] == 'x') { //16진수인 경우
                i+=2;
                while (i != exp.size() - 1 && !operator(exp[i])) {
                    temp = temp * 16 + (exp[i] - '0');
                    i++;
                } 
                while (ten >= 1) {
                    if (temp/ten >= 1 && temp != 0) {
                        result += (temp/ten) + '0';
                        temp -= ten * (temp / ten);
                    }ten /= 10;
                }
            }
            if (exp[i + 1] == 'b') { //2진수인 경우
                i += 2;
                while (i != exp.size() - 1 && !operator(exp[i])) {
                    temp = temp * 2 + (exp[i] - '0');
                    i++;
                }
                while (ten >= 1) {
                    if (temp / ten >= 1 && temp != 0) {
                        result += (temp / ten) + '0';
                        temp -= ten * (temp / ten);
                    }ten /= 10;
                }
            }
        }

        if (isdigit(exp[i]) || operator(exp[i]) || paren(exp[i])) { //숫자, 연산자, 괄호는 그냥 적음
            result += exp[i];
            i++;
        }
        else i++;
    }
    return result;
}

bool paircheck(string exp)//괄호, 음수 체크
{
    element symbol;
    if (operator(exp[0])) //첫번째 글자가 부호인 경우 오류 
        return false;

    for (int i = 0; i < exp.size(); i++)
    {
        symbol = exp[i];

        if (i < exp.size() - 1 && operator(symbol)) //연속으로 연산자가 나오면 오류
            if (operator(exp[i + 1]))
                return false;

        switch (symbol)
        {
        case '(':
            if (i < exp.size() - 1 && exp[i + 1] == '-') //괄호 바로다음 -가 나오면 음수. 오류
                return false;
            push(symbol);
            break;
        case ')':
            if (isEmpty())
                return false;
            else
            {
                element popelement = pop();
                if (popelement == '(' && symbol != ')')
                    return false;
                else
                    break;
            }
            break;
        }
    }
    if (isEmpty())
        return true;
    else
        return false;
}

string postfix(string exp) //후위표기식으로 변환. 
{
    char symbol;
    string result = "";
    char a;

    for (int i = 0; i < exp.size(); i++)
    {
        symbol = exp[i]; 
        if (symbol == '(')
            push(symbol);

        else if (isdigit(symbol)) //숫자면 그냥 추가
        {
            result += symbol;
        }

        else if (operator(symbol) || paren(symbol)) {
            result += " ";
            if (isEmpty())
                push(symbol);
            else {
                switch (symbol) { //연산자나 괄호이면 우선순위 따지기
                case ')':
                    a = pop();
                    while (a != '(')
                    {
                        result = result + a;
                        a = pop();
                    }
                    break;
                case '+':case '-':case '*':case '/':
                    if (isHigher(peek(), symbol)) {
                        while (isHigher(peek(), symbol)) {
                        result = result + pop() + " ";
                        if (isEmpty) break;
                        }
                        push(symbol);
                    }
                    else 
                        push(symbol);
                    break;
                }
            }
        }
    }

    while (!isEmpty()) //스택에 남은 것 다 꺼내기 
        result = result + " " + pop();
    return result;
}

vector<string> split(string exp) {
    string buf;
    istringstream ss(exp);
    vector<string> arr;
    while (getline(ss, buf, ' ')) {
        arr.push_back(buf);
    }
    return arr;
}

int eval(vector<string> arr)
{
    vector<int> vec;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != "" && !operator_s(arr[i])) {
            vec.push_back(stoi(arr[i]));
            cout << stoi(arr[i]) << " push" << endl;
        }
        else if(operator_s(arr[i])){
            int opr2 = vec.back();
            vec.pop_back();
            int opr1 = vec.back();
            vec.pop_back();

            Calculator* calculator = new Calculator();
            Operator_cc* op_cc = new Add_cc;
            if (arr[i] == "+") {
                op_cc = new Add_cc;
                cout << "Add: ";
            }
            else if (arr[i] == "-") {
                op_cc = new Sub_cc;
                cout << "Sub: ";
            }
            else if (arr[i] == "*") {
                op_cc = new Mul_cc;
                cout << "Mul: ";
            }
            else if (arr[i] == "/") {
                op_cc = new Div_cc;
                cout << "Div: ";
            }

            calculator->setOperator(op_cc);
            int r = calculator->perform(opr1, opr2);
            cout << r << endl;
            vec.push_back(r);
        }
    }
    return vec.back(); 
}


int main() {
    string exp;

    cout << "수식을 입력하시오(조건: 공백없이 입력, 괄호는 ()만 사용한다)" << endl;
    cout << "입력 수식: " << exp ;
    cin >> exp;


    try { //정상적인 수식인지 검사
        if (!paircheck(exp)) throw 0;
    }
    catch (int ex) {
        cout << "잘못된 입력: 프로그램을 종료합니다." << endl;
        return 0;
    }

    string result = form(exp);  //10진수로 통일, 필요없는 문자 삭제
    cout << "정리한 수식: " << result << '\n';

    string postexp = postfix(result); //후위표기로 바꾸고, 공백으로 자릿수 구분
    cout << "후위표기: " << postexp << endl;

    vector<string> arr = split(postexp); //공백기준으로 잘라 벡터에 넣음 

    int r = eval(arr); //후위식을 계산
    cout << "결과: " << r << endl;
  
    return 0;
}