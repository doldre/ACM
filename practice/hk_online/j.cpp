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
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
template<class T> inline T lowbit(T x) { return x & (-x); }

const ll MOD = 1e9 + 7;
const int MAXN = 5e5 + 5;

ll fast_pow(ll x, int n) {
    ll res = 1;
    while(n > 0) {
        if(n & 1) {
            res = res * x % MOD;
        }
        n >>= 1;
        x = x * x % MOD;
    }
    return res;
}

char str[MAXN];

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%s", str);
    int len = strlen(str);
    int all_quote = 0;
    for (int i = 0; i < len; i++) {
        if(str[i] == '?') all_quote++;
    }

    int cnt_one = 0, cnt_quote = 0;
    ll ans = 0;
    for (int i = 0; i < len; i++) {
        if(str[i] == '?' || str[i] == '0') {
            ll t = (cnt_one * fast_pow(2, cnt_quote) +
                    cnt_quote * fast_pow(2, cnt_quote - 1)) % MOD;
            if(str[i] == '?') cnt_quote++;
            t = t * fast_pow(2, all_quote - cnt_quote) % MOD;
            ans = (ans + t) % MOD;
        } else cnt_one++;
    }
    cout << ans << endl;
    return 0;
}

