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

const ll mod = 1e9 + 7;
const int MAXN = 1e5 + 5;
ll cnt[50];
vector<ll> V;
void init() {
    ll x = 1;
    while(x < mod) {
        V.push_back(x);
        x *= 2;
    }
}
int A[MAXN], n;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    init();
    while(T--) {
        scanf("%d", &n);
        memset(cnt, 0, sizeof(cnt));
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            int x; scanf("%d", &x);
            if(x == 1) {
                cnt[0]++;
                ans++;
            } else {
                auto p = lower_bound(V.begin(), V.end(), x);
                if(p != V.end() && *p == x) {
                    int ind = p - V.begin();
                    cnt[ind] = (cnt[ind] + cnt[ind-1]) % mod;
                    ans = (ans + cnt[ind-1]) % mod;
                }
            }
        }
        cout << ans % mod << endl;
    }
    return 0;
}

