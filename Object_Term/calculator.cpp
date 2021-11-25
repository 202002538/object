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

string form(string exp) { //16����, 2������ 10������ ����
    string result = "";
    char symbol;
    int temp = 0;
    int i = 0;
    int ten = 1000;

    while(i < exp.size()){
        if (i < exp.size()-1 && exp[i] == '0') {
            if (exp[i + 1] == 'x') { //16������ ���
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
            if (exp[i + 1] == 'b') { //2������ ���
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

        if (isdigit(exp[i]) || operator(exp[i]) || paren(exp[i])) { //����, ������, ��ȣ�� �׳� ����
            result += exp[i];
            i++;
        }
        else i++;
    }
    return result;
}

bool paircheck(string exp)//��ȣ, ���� üũ
{
    element symbol;
    if (operator(exp[0])) //ù��° ���ڰ� ��ȣ�� ��� ���� 
        return false;

    for (int i = 0; i < exp.size(); i++)
    {
        symbol = exp[i];

        if (i < exp.size() - 1 && operator(symbol)) //�������� �����ڰ� ������ ����
            if (operator(exp[i + 1]))
                return false;

        switch (symbol)
        {
        case '(':
            if (i < exp.size() - 1 && exp[i + 1] == '-') //��ȣ �ٷδ��� -�� ������ ����. ����
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

string postfix(string exp) //����ǥ������� ��ȯ. 
{
    char symbol;
    string result = "";
    char a;

    for (int i = 0; i < exp.size(); i++)
    {
        symbol = exp[i]; 
        if (symbol == '(')
            push(symbol);

        else if (isdigit(symbol)) //���ڸ� �׳� �߰�
        {
            result += symbol;
        }

        else if (operator(symbol) || paren(symbol)) {
            result += " ";
            if (isEmpty())
                push(symbol);
            else {
                switch (symbol) { //�����ڳ� ��ȣ�̸� �켱���� ������
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

    while (!isEmpty()) //���ÿ� ���� �� �� ������ 
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

    cout << "������ �Է��Ͻÿ�(����: ������� �Է�, ��ȣ�� ()�� ����Ѵ�)" << endl;
    cout << "�Է� ����: " << exp ;
    cin >> exp;


    try { //�������� �������� �˻�
        if (!paircheck(exp)) throw 0;
    }
    catch (int ex) {
        cout << "�߸��� �Է�: ���α׷��� �����մϴ�." << endl;
        return 0;
    }

    string result = form(exp);  //10������ ����, �ʿ���� ���� ����
    cout << "������ ����: " << result << '\n';

    string postexp = postfix(result); //����ǥ��� �ٲٰ�, �������� �ڸ��� ����
    cout << "����ǥ��: " << postexp << endl;

    vector<string> arr = split(postexp); //����������� �߶� ���Ϳ� ���� 

    int r = eval(arr); //�������� ���
    cout << "���: " << r << endl;
  
    return 0;
}