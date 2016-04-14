#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int x;
    while(cin >> x) {
        if(x == 42) return 0;
        cout << x << endl;
    }
    return 0;
}
