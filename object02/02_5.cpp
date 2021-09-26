#include <iostream>

#define MAXSTACKSIZE 1000 //스택의 최대크기

class Stack {
	int top;

public:
	int a[MAXSTACKSIZE]; //스택

	Stack() { top = -1; } //스택의 꼭대기값 초기화
	bool push(int x);
	int pop();
};

bool Stack::push(int x) { //:: 스택 안의 푸쉬 함수라는 뜻
	if (top >= (MAXSTACKSIZE - 1)) {
		std::cout << "오류: 스택이 넘쳤습니다." << std::endl;
		return false;
	}
	else {
		//코드 구현: 스택에 데이터 넣기
		top++;
		a[top] = x;
		//
		std::cout << x << "이 스택에 들어갔습니다." << std::endl;
		return true;
	}
}

int Stack::pop() {
	if (top < 0) {
		std::cout << "오류: 스택이 비었습니다." << std::endl;
		return 0;
	}
	else {
		//코드 구현: 스택에서 데이터 빼기
		int x = a[top];
		top--;
		//
		return x;
	}
}

int main() {
	class Stack s;
	s.push(7);
	s.push(88);
	s.push(999);
	std::cout << s.pop() << "을 스택에서 꺼냈습니다." << std::endl;
	std::cout << s.pop() << "을 스택에서 꺼냈습니다." << std::endl;
	std::cout << s.pop() << "을 스택에서 꺼냈습니다." << std::endl;

	system("pause");

	return 0;
}