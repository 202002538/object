#include <stdio.h>

//같은 코드. 근데 c파일에서만 오류가 난다. 왜일까?
//c언어는 객체지향 개념이 없다. 즉, 오버로딩 개념은 c++에서만 존재한다. 
//여기서는 이름이 똑같은 함수가 3개인 것이 이상한것.

void print(int var) {
	printf("Integer number: %d\n", var);
}

void print(float var) {
	printf("Float number: %f\n", var);
}

void print(int var1, float var2) {
	printf("Integer number: %d\n", var1);
	printf("and float number: %f\n", var2);
}

int main() {
	int a = 7;
	float b = 9;

	print(a);
	print(b);
	print(a, b);

	return 0;
}