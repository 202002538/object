#include <iostream>
using namespace std;
int i;

class A {
public:
    ~A() {
        i = 10;
    }
};

int foo() {
    i = 3;
    {A ob; } //이 블럭내에서 객체 ob가 생성되고, 블럭이 끝날떄 A가 delete되며 i가 10으로 바뀐다.
    return i;
}

int main() {
    cout << foo() << endl;
    return 0;
}