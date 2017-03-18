#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    bool ok = true;
    int n;
    scanf("%d", &n);
    int rest = 0;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        x -= rest;
        if(x < 0) ok = false;
        rest = x % 2;
    }
    if(rest) ok = false;
    if(ok) puts("YES");
    else puts("NO");
    return 0;
}
