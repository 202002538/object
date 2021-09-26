#include <iostream>

//c이 아닌 c++에만 오버로딩, 다양성 개념이 있다.
//오버로딩: 이름이 같아도 파라미터가 다르면 다른 함수
//오버라이딩: 같은 함수이름에 대해서, 새롭게 정의함

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