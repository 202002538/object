class Animal {
public:
	Animal() {
		numberOfLeg = 0;
	}
	Animal(int numberOfLeg) {
		this->numberOfLeg = numberOfLeg;
	}
	//default 생성자가 없이 Parameterized Constructor만 있어서 에러가 발생 

private:
	int numberOfLeg;
};

int main() {
	Animal a; //이렇게 객체를 생성하면 기본생성자가 필요함
	return 0;
}