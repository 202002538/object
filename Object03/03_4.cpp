#include <iostream>

//포인터를 활용하여 increment의 인풋값이 1 증가되도록 수정.

void increment(int *x) {
	++ *x;
}

int main() {
	int x = 55;

	std::cout << "Before increment: " << x << std::endl;
	increment(&x);
	std::cout << "After increment: " << x << std::endl;

	system("pause");
	return 0;
}