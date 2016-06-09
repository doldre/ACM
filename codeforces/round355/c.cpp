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
#define sa(n) scanf("%d", &(n))
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const ll mod = 1e9 + 7;
const int maxn = 100000 + 5;
char str[maxn];

int ctoi(char c) {
    if(c == '-') return 62;
    if(c == '_') return 63;
    if(c >= '0' && c <= '9') return c - '0';
    if(c >= 'A' && c <= 'Z') return c - 'A' + 10;
    if(c >= 'a' && c <= 'z') return c - 'a' + 36;
}

ll cal(int x) {
    ll res = 1;
    for (int i = 0; i < 6; i++) {
        if(!((x >> i) & 1)) {
            res *= 3;
        }
    }
    return res;
}
ll solve() {
    ll res = 1;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        /* pr(str[i]); prln(ctoi(str[i])); */
        res = (res * cal(ctoi(str[i]))) % mod;
    }
    return res;
}
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%s", str);
    ll res = solve();
    cout << res << endl;
    return 0;
}
