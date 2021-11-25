#include <iostream>
#include <string>
using namespace std;
typedef char element; 

struct Node { //Node 구조체는 char데이터와 이어지는 노드를 가지고 있다.  
    element data;
    Node* link;
};

Node* top;

void push(element data)
{
    Node* temp;
    temp = new Node(); //새 노드를 만든다. 

    if (!temp) //노드가 안만들어지면 힙 영역이 남지않은것
    {
        cout << "\nHeap Overflow";
        exit(1);
    }

    temp->data = data; //노드에 추가할 데이터 담고, 맨 앞에 갖다 붙임 
    temp->link = top;
    top = temp;
}

int isEmpty()
{
    return top == NULL; //아무 노드도 없으면 1 리턴 
}

int peek()
{
    if (!isEmpty())
        return top->data;  //꼭대기 데이터 반환(맨 앞 노드)
    else
        exit(1);
}

element pop()
{
    Node* temp;
    element data;

    if (top == NULL) //top이 없는데 pop을 시도햇다는 것은 underflow가 발생햇다는 뜻. 
    {
        cout << "\nStack Underflow" << endl;
        exit(1);
    }
    else
    {
        data = top->data; //맨 앞의 데이터를 꺼내고, 맨앞의 노드를 없앤다
        temp = top;
        top = top->link; //다음 노드가 top이 된다. 
        temp->link = NULL;
        delete temp;
    }

    return data;
}

void display() //모든 노드를 출력
{
    Node* temp;
    if (top == NULL) //노드가 없으면 언더플로우발생
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

int order(char op) { //연산자 우선순위 반환 
    switch (op) {
    case '+': return 1;
    case '-': return 1;
    case '*': return 2;
    case '/': return 2;

    default: return 0;
    }
}

bool isHigher(char a, char b) { //우선순위 비교. 매개변수1의 순위가 더 높은 경우 참
    if (order(a) >= order(b)) return true;
    else return false;
}