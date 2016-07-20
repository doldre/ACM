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
const int N = 1e5 + 10, inf = 0x3f3f3f3f, MOD = 1e9 + 7;

struct P {
    ll xx, yy;
    int num;
    P() {}
    P(ll xx, ll yy):xx(xx), yy(yy) {}
    bool operator < (const P &b) const {
        return xx < b.xx || (xx == b.xx && yy < b.yy);
    }
};

P a[N];

bool cmp(const P &a, const P &b) {
    return a.yy < b.yy;
}

pair<ll, pii> dfs(int l, int r) {
    if(l == r) return make_pair(inf, pii(-1, -1));
    int m = (l + r) >> 1;
    ll x = a[m].xx;
    pair<ll, pii> d = min(dfs(l, m), dfs(m + 1, r));
    // sort(a + l, a + r + 1, cmp);
    inplace_merge(a + l, a + m + 1, a + r + 1, cmp);

    vector<int> v;
    for (int i = l; i <= r; i++) {
        if(abs(a[i].xx - x) >= d.xx) continue;
        
        for (int j = v.size() - 1; j >= 0; j--) {
            int k = v[j];
            ll dy = a[i].yy - a[k].yy;
            if(dy >= d.xx) break;
            ll dx = a[i].xx - a[k].xx;
            d = min(d, make_pair(dx * dx + dy * dy, pii(a[i].num, a[k].num)));
        }
        v.push_back(i);
    }
    return d;
}

P src[N];
int n;

void cpy(int pass) {
    int cnt = 1;
    for (int i = 1; i <= n; i++) {
        if(src[i].num == pass) continue;
        else {
            a[cnt++] = src[i];
        }
    }
}
int main(void) {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%lld%lld", &src[i].xx, &src[i].yy);
            src[i].num = i;
            a[i] = src[i];
        }
        sort(a + 1, a + n + 1);
        pair<ll, pii> res = dfs(1, n);
        ll ans = res.xx * (n - 2);
        // prln(ans);
        int aa = res.yy.xx, bb = res.yy.yy;
        cpy(aa);
        // prln(aa); prln(bb);
        sort(a + 1, a + n);
        ans += dfs(1, n - 1).xx;
        // prln(ans);
        cpy(bb);
        sort(a + 1, a + n);
        ans += dfs(1, n - 1).xx;
        // prln(ans);
        printf("%lld\n", ans);
    }
    return 0;
}

