#include<iostream>

class SetValue {  
	public:  //권한을 따로 지정하지 않으면 private으로 설정이 된다는 점.
		int x, y;
};

int main() {
	SetValue obj;
	obj.x = 33;
	obj.y = 44;

	std::cout << "X=" << obj.x << ", Y=" << obj.y << std::endl;

	system("pause"); //콘솔화면이 바로 사라짐 방지
	return 0;
}