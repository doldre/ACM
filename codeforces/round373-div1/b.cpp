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

const int MAXN = 2e5 + 5;
const int MAXM = 2e3 + 5;
int t[MAXN];
int ans[MAXN], last[MAXN];
int n, m;
int cnt[MAXM];
int pre[MAXM][MAXM];
ll judge(ll x) {
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        // prln(last[i]);
        res += (x - last[i]) / t[i];
    }
    // prln(res);
    return res;
}

ll judge2(ll x) {
    ll res = 0;
    for (int i = 1; i <= 1000; i++) {
        res += (x / i) * cnt[i];
        res += pre[i][x % i];
    }
    return res;
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
    }
    sort(t + 1, t + n + 1);
    priority_queue<pii, vector<pii>, greater<pii> > que;
    int s = 1;
    que.push(pii(t[s], s));
    while(s <= n) {
        pii cur = que.top(); que.pop();
        ans[s++] = cur.xx;
        last[cur.yy] = cur.xx;
        last[s] = cur.xx;
        que.push(pii(cur.xx + t[s], s));
        que.push(pii(cur.xx + t[cur.yy], cur.yy));
    }
    for (int i = 1; i <= n; i++) {
        pre[t[i]][t[i] - (ans[n]-last[i])]++;
        cnt[t[i]]++;
    }
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            pre[i][j] += pre[i][j-1];
        }
    }
    while(m--) {
        int a; scanf("%d", &a);
        if(a <= n) {
            printf("%d\n", ans[a]);
        } else {
            int x = a - n;
            ll l = 0, r = 1e12 + 1;
            while(l < r - 1) {
                ll mid = (l + r) >> 1;
                if(judge2(mid) >= x) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
            printf("%lld\n", r + ans[n]);
        }
    }
    return 0;
}

