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

const ll MOD = 1e9 + 7;
const double inf = 1e15;
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll mod_pow(ll x, ll n, ll mod) {
    ll res = 1;
    while(n > 0) {
        if(n & 1) {
            res = (res * x) % mod;
        }
        n >>= 1;
        x = (x * x) % mod;
    }
    return res;
}

const int maxn = 1000 + 5;
struct Point {
    ll x, y;
    double k;
    Point() {}
    Point(ll x, ll y): x(x), y(y) {}

    Point operator - (const Point &b) const {
        return Point(x - b.x, y - b.y);
    }

    void read() {
        scanf("%lld%lld", &x, &y);
    }
    

    void get_k() {
        if(x != 0) {
            ll g = gcd(x, y);
            ll a = y / g, b = x / g;
            k = double(a) / b;
        } else {
            k = inf;
        }
    }

}ps[maxn];
int n;

bool cmp(const Point &a, const Point &b) {
    return a.k < b.k;
}

Point buf[maxn];
int main(void) {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            ps[i].read();
        }

        ll ans = 0;
        for (int i = 0; i < n - 1; i++) {
            int cnt = 0;
            int same = 0;
            for (int j = i + 1; j < n; j++) {
                Point t = ps[j] - ps[i];
                if(t.x == 0 && t.y == 0) {
                    same++;
                    continue;
                }
                buf[cnt] = t;
                buf[cnt].get_k();
                // prln(buf[cnt].k);
                cnt++;
            }

            ll cnt_same = mod_pow(2, same, MOD);
            sort(buf, buf + cnt, cmp);
            int tmp = 1;
            for (int j = 1; j < cnt; j++) {
                if(buf[j].k == buf[j-1].k) {
                    tmp++;
                } else {
                    ans = (ans + (mod_pow(2, tmp, MOD) - 1) * cnt_same) % MOD;
                    // prln(ans);
                    tmp = 1;
                    // prln(tmp);
                }
            }
            // prln(cnt);
            // prln(tmp);
            if(cnt > 0) ans = (ans + (mod_pow(2, tmp, MOD) - 1) * cnt_same) % MOD;
            ans = (ans + (cnt_same - 1) + MOD) % MOD;
            // prln(ans);
        }
        printf("%lld\n", ans);
    }
    return 0;
}

