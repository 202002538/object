class Animal {
public:
	Animal() {
		numberOfLeg = 0;
	}
	Animal(int numberOfLeg) {
		this->numberOfLeg = numberOfLeg;
	}
	//default �����ڰ� ���� Parameterized Constructor�� �־ ������ �߻� 

private:
	int numberOfLeg;
};

int main() {
	Animal a; //�̷��� ��ü�� �����ϸ� �⺻�����ڰ� �ʿ���
	return 0;
}