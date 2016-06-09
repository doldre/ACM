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
typedef long long ll;
typedef unsigned long long ull;
#define xx first
#define lowbit(x) (x&-x)
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
typedef pair<ll, ll> pii;
vector<ll> tabel;
const int maxn = 1e5 + 5;
void init() {
    for (int i = 1; i <= maxn; i++) {
        tabel.push_back((ll)i*i*i);
    }
}
map<ll, pii> mp;

pii f(ll x) {
    if(x < 8) return pii(x, x);
    if(mp.find(x) != mp.end()) {
        return mp[x];
    }
    ll t = *(--upper_bound(tabel.begin(), tabel.end(), x));
    pii ta = f(t-1), tb = f(x - t);
    pii res;
    if(ta.xx > tb.xx + 1) {
        res = ta;
    } else if(ta.xx < tb.xx + 1) {
        res = pii(tb.xx + 1, tb.yy + t);
    } else if(ta.xx == tb.xx + 1) {
        ll a = ta.yy, b = tb.yy + t;
        if(a > b) {
            res =  pii(ta.xx, a);
        } else {
            res = pii(tb.xx + 1, tb.yy + t);
        }
    }
    return mp[x] = res;
}
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    init();
    ll x;
    cin >> x;
    pii res = f(x);
    cout << res.xx << " " << res.yy << endl;
    return 0;
}
