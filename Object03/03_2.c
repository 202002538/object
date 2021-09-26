#include <stdio.h>

int main() {
	int s;
	printf("문자를 입력하세요(100자 이내).\n");
	scanf_s("%d", &s);
	printf("입력된 문자는 %d입니다.", s);

	//system("pause"); //keep terminal open
	return 0;
}
