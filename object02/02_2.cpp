#include<iostream>

class SetValue {
	int x, y;

	//������� �߰�
public:
	void setXY(int a, int b) {
		x = a;
		y = b;
	}

	void show() {
		std::cout << "X=" << x << ", Y=" << y << std::endl;
	}
}; //�̰� ��.. �� �����ݷ� �־���ϳ�?

int main() {
	SetValue obj;

	obj.setXY(33, 44);
	obj.show();

	system("pause");
	return 0;
}

