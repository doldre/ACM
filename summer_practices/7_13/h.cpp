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
const ll inf = 1ll << 32;
const int maxn = 1e6 + 5;
char str[100];
ll X[maxn], Y[maxn], Z[maxn];
int n;

ll count(ll x) {
    ll res = 0;
    for (int i = 0; i < n; i++) {
        if(X[i] > x) continue;
        else {
            res += (min(x, (ll)Y[i]) - X[i]) / Z[i] + 1;
        }
    }
    return res;
}

ll count2(ll x) {
    ll res = 0;
    for (int i = 0; i < n; i++) {
        if(x < X[i] || x > Y[i]) continue;
        else {
            if((x - X[i]) % Z[i] == 0) res++;
        }
    }
    return res;
}

bool judge(ll x) {
    ll res = count(x);
    return res % 2 == 1;
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(gets(str) && str[0] == 0);
    while(true) {
        n = 0;
        sscanf(str, "%lld%lld%lld", &X[n], &Y[n], &Z[n]);
        n++;
        while(gets(str) && str[0]) {
            // prln(str);
            sscanf(str, "%lld%lld%lld", &X[n], &Y[n], &Z[n]);
            n++;
        }
        ll l = -1, r = inf; 
        while(l < r - 1) {
            ll m = (l + r) >> 1;
            if(judge(m)) {
                r = m;
            } else l = m;
        }
        if(r == inf) {
            printf("no corruption\n");
        } else {
            printf("%lld %lld\n", r, count2(r));
        }
        int flag = 0;
        while(gets(str)) {
            flag++;
            if(str[0] != 0) break;
        }
        if(flag == 0 || str[0] == 0) return 0;
    }
    return 0;
}

