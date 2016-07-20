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
    mp['b'] = 'd';
    mp['d'] = 'b';
    mp['H'] = 'H';
    mp['I'] = 'I';
    mp['M'] = 'M';
    mp['O'] = 'O';
    mp['o'] = 'o';
    mp['p'] = 'q';
    mp['q'] = 'p';
    mp['T'] = 'T';
    mp['U'] = 'U';
    mp['V'] = 'V';
    mp['v'] = 'v';
    mp['W'] = 'W';
    mp['w'] = 'w';
    mp['X'] = 'X';
    mp['x'] = 'x';
    mp['Y'] = 'Y';
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    init();
    string str;
    cin >> str;
    int len = (int)str.size();
    bool ok = true;
    for (int i = 0; i < len; i++) {
        if(mp.find(str[i]) == mp.end()) {
            ok = false;
            break;
        } else {
            if(mp[str[i]] != str[len - 1 - i]) {
                ok = false;
                break;
            }
        }
    }
    if(ok) printf("TAK\n");
    else printf("NIE\n");
    return 0;
}

