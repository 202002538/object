#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

typedef char element; //element�� ����... char�̴�~

struct Node { //Node ����ü���� char, �̾����� ��带 ������ �ִ�.  
    element data;
    Node* link;
};

Node* top;

void push(element data)
{
    Node* temp;
    temp = new Node(); //�� ��带 �����. 

    if (!temp) //��尡 �ȸ��������? �� ������ �� ������
    {
        cout << "\nHeap Overflow";
        exit(1);
    }

    temp->data = data; //��忡 �߰��� ������ ���, �� �տ� ���� ���� 
    temp->link = top;
    top = temp;
}

int isEmpty()
{
    return top == NULL; //�ƹ� ��嵵 ������ 1 ���� 
}

int peek()
{
    if (!isEmpty())
        return top->data;  //����� ������ ��ȯ(�� �� ���)
    else
        exit(1);
}

element pop()
{
    Node* temp;
    element data;

    if (top == NULL) //top�� ���µ� pop�� �õ��޴ٴ� ����.. underflow�� �߻��޴ٴ� ��. 
    {
        cout << "\nStack Underflow" << endl;
        exit(1);
    }
    else
    {
        data = top->data; //�� ���� �����͸� ������, �Ǿ��� ��带 ���ش�
        temp = top;
        top = top->link; //���� ��尡 top�� �ȴ�. 
        temp->link = NULL;
        delete temp;
    }

    return data;
}

void display() //��� ��带 ���
{
    Node* temp;
    if (top == NULL) //��尡 ������ ����÷ο�
    {
        cout << "\nStack Underflow";
        exit(1);
    }
    else
    {
        temp = top;
        while (temp != NULL)
        {
            cout << temp->data << "-> ";
            temp = temp->link;
        }
    }
}



bool paircheck(string exp) //�̰����� ���� �����ΰ�? ��ȣ�� ����� �Ƴİ�.
{
    element symbol;

    for (int i = 0; i < exp.size(); i++)
    {
        symbol = exp[i]; //���� �� �ѱ��ھ� �˻� 
        switch (symbol)
        {
        case '(':case '[':case '{':
            push(symbol);
            break;
        case ')':case ']':case '}':  
            if (isEmpty())
                return false;  //��ȣ �ݾҴµ� ���� ��ȣ�� �������� �ʴ�?? false ����
            else
            {
                element popelement = pop(); //���� ��ȣ�� �־�? �׷� ������
                if ((popelement == '(' && symbol != ')') ||  //���°� �ݴ°� ���� ��ġ����? false���� 
                    (popelement == '[' && symbol != ']') ||
                    (popelement == '{' && symbol != '}'))
                    return false;
                else
                    break;
            }
            break;
        }
    }
    if (isEmpty())
        return true;
    else //�ƴ� ��ȣ�� �����־�? ��ȣ ����� ��ģ����. test("((1+2)/3)"); =>> ( ( ) )
        return false;
}


string postfix(string exp) //����ǥ������� ��ȯ 
{
    char symbol;
    int count = 0;
    string result = "";

    for (int i = 0; i < exp.size(); i++)
    {
        symbol = exp[i]; // ���� �ϳ� �ϳ��� ����
        if (isdigit(symbol)) //���ڸ� �׳� �߰�
        {
            result += symbol;
            continue;
        }

        switch (symbol) //�����ڸ� �켱���� �������� 
        {
        case '+':case '-':case '*':case '/':
            push(symbol);
            break;
        case ')':case '}':case ']': //��ȣ �������� ��� ������ ����
            while (!isEmpty())
                result += pop();
            break;
        }
    }

    while (!isEmpty()) //���ÿ� ���� �� �� ������ 
        result += pop();
    return result;
}

// �������� �������
int eval(string exp)
{
    element symbol;

    for (int i = 0; i < exp.size(); i++)
    {
        symbol = exp[i];
        if (isdigit(symbol)) //���ڸ� �ϴ� ���ÿ� �߰� 
        {
            push((element)(symbol - '0')); //�ٵ� ��... 0�� ���� �ϳ�? ��... �ҹ��ڴ빮��ó����?
        }
        else
        {
            element opr2 = pop();
            element opr1 = pop(); //�ǿ����� �ΰ� ��

            switch (symbol)
            {
            case '+':
                push(opr1 + opr2);
                break;
            case '-':
                push(opr1 - opr2);
                break;
            case '*':
                push(opr1 * opr2);
                break;
            case '/':
                push(opr1 / opr2);
                break;
            }
        }
    }
    return pop(); // ���ÿ� ����� ���� ���� ��� ����� ��ȯ
}

void test(string exp) //���� ������ ���� ������ �Ǵ� ��, ����ǥ������� �ٲ�->���
{
    cout << "-------------------- " << endl;
    cout << "����: " << exp << endl;

    while (!isEmpty()) pop();//�̰� ���ִ°���?
    if (!paircheck(exp))
    {
        cout << "�߸��� ���� " << endl;
        return;
    }
    while (!isEmpty()) pop();//

    string postexp = postfix(exp);
    cout << "����ǥ��: " << postexp << endl;

    while (!isEmpty()) pop();//

    int result = eval(postexp); //�������� ���
    cout << "���: " << result << endl;
}

int main()
{
    test("1+2");
    test("(1+2)*3");
    test("(1+2)/3");
    test("(1+2)/3)");
    test("((1+2+3)*6/2)");
    test("(1+2)*(3+4)");

    return 0;
}


