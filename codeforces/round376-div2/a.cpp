#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100 + 5;
char str[MAXN];

int main() {
    scanf("%s", str);
    int len = strlen(str);
    int ans = 0, last = 0;
    for (int i = 0; i < len; i++) {
        int x = str[i] - 'a';
        ans += min(abs(x - last), 26 - abs(x - last));
        last = x;
    }
    cout << ans << endl;
}
