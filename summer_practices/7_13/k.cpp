/************************************************
 *Author        :mathon
 *Email         :luoxinchen96@gmail.com
*************************************************/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stack>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
#define xx first
#define lowbit(x) (x&-x)
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
map<char, char> mp;

void init() {
    mp['A'] = 'A';
    mp['E'] = '3';
    mp['H'] = 'H';
    mp['I'] = 'I';
    mp['J'] = 'L';
    mp['L'] = 'J';
    mp['M'] = 'M';
    mp['O'] = 'O';
    mp['S'] = '2';
    mp['T'] = 'T';
    mp['U'] = 'U';
    mp['V'] = 'V';
    mp['W'] = 'W';
    mp['X'] = 'X';
    mp['Y'] = 'Y';
    mp['Z'] = '5';
    mp['1'] = '1';
    mp['2'] = 'S';
    mp['3'] = 'E';
    mp['5'] = 'Z';
    mp['8'] = '8';
}
const int maxn = 200 + 5;
char str[maxn];
char buf[maxn];
bool ismirroed(int len) {
    for (int i = 0; i < len; i++) {
        if(mp.find(str[i]) != mp.end()) {
            buf[i] = mp[str[i]];
        } else return false;
    }
    for (int i = 0; i < len; i++) {
        if(str[i] != buf[len - 1 - i]) {
            return false;
        }
    }
    return true;
}
bool ispali(int len) {
    for (int i = 0; i < len; i++) {
        if(str[i] != str[len - 1 - i]) {
            return false;
        }
    }
    return true;
}
char ans[4][100] = {
    "is not a palindrome.",
    "is a regular palindrome.",
    "is a mirrored string.",
    "is a mirrored palindrome."
};

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    init();
    while(scanf("%s", str) == 1) {
        int len = strlen(str);
        printf("%s -- ", str);
        int a1 = ispali(len), a2 = ismirroed(len);
        printf("%s\n", ans[a1 | (a2 << 1)]);
        puts("");
    }
    return 0;
}

