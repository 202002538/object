#include <iostream>
using namespace std;

class Operator_cc {
public:
	virtual int cc(int a, int b)=0;
};

class Add_cc : public Operator_cc {
public: 
	virtual int cc(int a, int b) {
		return a + b;
	}
};

class Sub_cc : public Operator_cc {
public:
	virtual int cc(int a, int b) {
		return a - b;
	}
};

class Mul_cc : public Operator_cc {
public:
	virtual int cc(int a, int b) {
		return a * b;
	}
};

class Div_cc : public Operator_cc {
public:
	virtual int cc(int a, int b) {
		try {
			if (b == 0) throw b;
			else return a / b;
		}
		catch (int ex) {
			cout << "������ ���� " << ex << "�� �� �� �����ϴ�. " << endl;
			cout << "���α׷��� �����մϴ�." << endl;
			exit(0);
		}
	}
};

class Calculator {
private:
	Operator_cc *op_cc;
public:
	void setOperator(Operator_cc* op_cc) {
		this->op_cc = op_cc;
	}
	int perform(int a, int b) {
		return op_cc -> cc(a, b);
	}
};