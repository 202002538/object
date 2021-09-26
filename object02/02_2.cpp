#include<iostream>

class SetValue {
	int x, y;

	//여기부터 추가
public:
	void setXY(int a, int b) {
		x = a;
		y = b;
	}

	void show() {
		std::cout << "X=" << x << ", Y=" << y << std::endl;
	}
}; //이거 그.. 꼭 세미콜론 있어야하나?

int main() {
	SetValue obj;

	obj.setXY(33, 44);
	obj.show();

	system("pause");
	return 0;
}

