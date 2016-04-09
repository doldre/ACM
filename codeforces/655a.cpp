#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

const int maxn = 4;
char A[maxn], B[maxn];

void doit(char *buf) {
    for(int i = 0; i < maxn; i++) {
        if(buf[i] == 'X') {
            for(int j = i; j < maxn - 1; j++) {
                buf[j] = buf[j+1];
            }
        }
    }
}
int main() {
    for(int i = 0; i < maxn; i++) {
        cin >> A[i];
    }
    swap(A[2], A[3]);
    for(int i = 0; i < maxn; i++) {
        cin >> B[i];
    }
    swap(B[2], B[3]);
    doit(A); doit(B);
    int ok = false;
    for(int i = 0; i < 3; i++) {
        bool t = true;
        for(int j = 0; j < 3; j++) {
            if(A[j] != B[(i+j) % 3]) {
                t = false;
                break;
            }
        }
        if(t) {
             ok = true;
             break;
        }
    }
    if(ok) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
