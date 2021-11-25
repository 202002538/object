#include <iostream>
#include <string>
using namespace std;
typedef char element; 

struct Node { //Node ����ü�� char�����Ϳ� �̾����� ��带 ������ �ִ�.  
    element data;
    Node* link;
};

Node* top;

void push(element data)
{
    Node* temp;
    temp = new Node(); //�� ��带 �����. 

    if (!temp) //��尡 �ȸ�������� �� ������ ����������
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

    if (top == NULL) //top�� ���µ� pop�� �õ��޴ٴ� ���� underflow�� �߻��޴ٴ� ��. 
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
    if (top == NULL) //��尡 ������ ����÷ο�߻�
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

int order(char op) { //������ �켱���� ��ȯ 
    switch (op) {
    case '+': return 1;
    case '-': return 1;
    case '*': return 2;
    case '/': return 2;

    default: return 0;
    }
}

bool isHigher(char a, char b) { //�켱���� ��. �Ű�����1�� ������ �� ���� ��� ��
    if (order(a) >= order(b)) return true;
    else return false;
}