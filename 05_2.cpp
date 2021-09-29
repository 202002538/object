#include <iostream>
using namespace std;
int i;

class A {
public:
    ~A() {
        i = 10;
    }
};

int foo() { //레퍼런스 이용해 고치기 
    i = 3;
    A ob;
    A& o = ob;
    o.~A();
    return i;
}

int main() {
    cout << foo() << endl;
    return 0;
}