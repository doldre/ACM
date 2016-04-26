/************************************************
 *Author        :mathon
 *Created Time  :二  4/26 07:59:36 2016
 *Problem class:
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
typedef long long ll;
typedef pair<ll, int> pii;
typedef unsigned long long ull;
vector<int> vi;
#define xx first
#define yy second
#define lowbit(x) (x&-x)
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++)
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl

const ll mod = 1e9 + 7;
const int maxv = 1e9 + 7;
const int maxn = 50000 + 5;
int A[maxn];
vector<int> buf;
map<pii, ll> bit;

void add(int v, int p, int x) {
    for (int i = p; i <= maxv; i += lowbit(i)) {
        bit[pii(v, i)] = (bit[pii(v, i)] + x) % mod;
    }
}

ll querry(int v, int p) {
    ll res = 0;
    for (int i = p; i > 0; i -= lowbit(i)) {
        res = (res + bit[pii(v, i)]) % mod;
    }
    return res;
}

int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n;
    sa(n);
    rep(i, 0, n) {
        sa(A[i]);
        A[i]++;
    }
    ll maxlen = 0, cnt = 0;
    rep(i, 0, n) {
        int x = A[i];
        add(1, x, 1);
        int p = lower_bound(buf.begin(), buf.end(), x) - buf.begin();
        if(p == (int)buf.size()) {
            buf.push_back(x);
        } else {
            if(buf[p] > x) {
                buf[p] = x;
            }
        }
        ll t = querry(p, x - 1);
        /* pr(p); prln(t); */
        /* prln(buf[p]); */
        add(p + 1, x, t);
        t = querry(p + 1, maxv);
        if(p + 1 > maxlen) {
            maxlen = p + 1; cnt = t;
        } else if(p + 1 == maxlen) {
            cnt = max(cnt, t);
        }
    }
    cout << cnt << endl;
    return 0;
}
