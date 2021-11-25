#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;


vector<string> split(string exp) {
    string buf;
    istringstream ss(exp);
    vector<string> arr;
    while (getline(ss, buf, ' ')) {
        arr.push_back(buf);
    }
    return arr;
}

int main() {
    string s = "";
    int a = 100;
    s += a;
    cout << s << endl;

	
}
