#include<iostream>

class SetValue {  
	public:  //������ ���� �������� ������ private���� ������ �ȴٴ� ��.
		int x, y;
};

int main() {
	SetValue obj;
	obj.x = 33;
	obj.y = 44;

	std::cout << "X=" << obj.x << ", Y=" << obj.y << std::endl;

	system("pause"); //�ܼ�ȭ���� �ٷ� ����� ����
	return 0;
}