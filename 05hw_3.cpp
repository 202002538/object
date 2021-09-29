#include <iostream>

class Animal {
public:
	char* name;
	int age;

	Animal(int age_, const char* name_) {
		age = age_;
		name = new char[strlen(name_) + 1];
		strcpy(name, name_);
	}

	Animal(Animal& a) { //���� ������
		age = a.age;
		name = new char[strlen(a.name) + 1]; //deep copy�� �ٲ㼭 �ذ�
		strcpy(name, a.name);			//B.name�� A.name�� �ּҰ� �ƴ� ���� ������ ���ڿ��� ���Ե�
	}

	void changeName(const char* newName) {
		strcpy(name, newName);
	}
	void printAnimal() {
		std::cout << "Name: " << name << " Age: "
			<< age << std::endl;
	}
};

void main() {
	Animal A(10, "Jenny"); //10�� Jenny ����
	Animal B = A; // 10�� Jenny�� A�� B���� ����
	A.age = 22;		//A�� ���̸� 22��� �ٲ�
	A.changeName("Brown"); //A�� �̸��� Brown���� �ٲ�

	A.printAnimal();
	B.printAnimal();
	getchar();
}