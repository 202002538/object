#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

typedef char element; //element라 함은... char이다~

struct Node { //Node 구조체에는 char, 이어지는 노드를 가지고 있다.  
    element data;
    Node* link;
};

Node* top;

void push(element data)
{
    Node* temp;
    temp = new Node(); //새 노드를 만든다. 

    if (!temp) //노드가 안만들어진다? 힙 영역이 꽉 찬거임
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

    if (top == NULL) //top이 없는데 pop을 시도햇다는 것은.. underflow가 발생햇다는 뜻. 
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
    if (top == NULL) //노드가 없으면 언더플로우
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



bool paircheck(string exp) //이게지금 옳은 수식인가? 괄호를 제대로 쳤냐고.
{
    element symbol;

    for (int i = 0; i < exp.size(); i++)
    {
        symbol = exp[i]; //들어온 식 한글자씩 검사 
        switch (symbol)
        {
        case '(':case '[':case '{':
            push(symbol);
            break;
        case ')':case ']':case '}':  
            if (isEmpty())
                return false;  //괄호 닫았는데 여는 괄호가 들어와잇지 않다?? false 리턴
            else
            {
                element popelement = pop(); //여는 괄호가 있어? 그럼 가져와
                if ((popelement == '(' && symbol != ')') ||  //여는거 닫는거 서로 일치안해? false리턴 
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
    else //아니 괄호가 남아있어? 괄호 제대로 안친거지. test("((1+2)/3)"); =>> ( ( ) )
        return false;
}


string postfix(string exp) //후위표기식으로 변환 
{
    char symbol;
    int count = 0;
    string result = "";

    for (int i = 0; i < exp.size(); i++)
    {
        symbol = exp[i]; // 문자 하나 하나에 대해
        if (isdigit(symbol)) //숫자면 그냥 추가
        {
            result += symbol;
            continue;
        }

        switch (symbol) //연산자면 우선순위 따져보기 
        {
        case '+':case '-':case '*':case '/':
            push(symbol);
            break;
        case ')':case '}':case ']': //괄호 닫을때는 모든 연산자 빼냄
            while (!isEmpty())
                result += pop();
            break;
        }
    }

    while (!isEmpty()) //스택에 남은 것 다 꺼내기 
        result += pop();
    return result;
}

// 후위식을 계산해줌
int eval(string exp)
{
    element symbol;

    for (int i = 0; i < exp.size(); i++)
    {
        symbol = exp[i];
        if (isdigit(symbol)) //숫자면 일단 스택에 추가 
        {
            push((element)(symbol - '0')); //근데 왜... 0을 빼서 하나? 뭐... 소문자대문자처린가?
        }
        else
        {
            element opr2 = pop();
            element opr1 = pop(); //피연산자 두개 뺌

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
    return pop(); // 스택에 저장된 값을 최종 계산 결과로 반환
}

void test(string exp) //들어온 수식이 옳은 식인지 판단 후, 후위표기식으로 바꿈->계산
{
    cout << "-------------------- " << endl;
    cout << "수식: " << exp << endl;

    while (!isEmpty()) pop();//이게 왜있는건지?
    if (!paircheck(exp))
    {
        cout << "잘못된 수식 " << endl;
        return;
    }
    while (!isEmpty()) pop();//

    string postexp = postfix(exp);
    cout << "후위표기: " << postexp << endl;

    while (!isEmpty()) pop();//

    int result = eval(postexp); //후위식을 계산
    cout << "결과: " << result << endl;
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


