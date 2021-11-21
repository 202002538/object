#include <iostream>
#include <string>

/* ....(실습1)에서 구현된 template swap ....*/
template<typename T>
void swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
};

/* ... (추가) template swap의 string type specialization ... */
template<>
typename void swap<std::string>(typename std::string& a, std::string& b) {
	std::string tmp = a;
	a = b;
	b = tmp;
};

int main() {
	int a = 1;
	int b = 2;
	float c = 3.3;
	float d = 4.4;
	std::string e = "World";
	std::string f = "Hello";

	swap(a, b); //swap(a,b)도 가능
	swap(c, d); //swap(c,d)도 가능
	swap(e, f); //(추가) e, f의 swap이 가능하도록 swap template 호출

	std::cout << "a: " << a << ", b: " << b << std::endl;
	std::cout << "c: " << c << ", d: " << d << std::endl;
	std::cout << "e: " << e << ", f: " << f << std::endl;

	return 0;
}
