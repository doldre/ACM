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

map<ll, ll> mp;
map<ll, bool> used;

void update(ll x, ll w) {
    while(x > 0) {
        if(!used[x]) {
            mp[x] += w;
            used[x] = true;
        } else {
            mp[x] -= w;
        }
        x >>= 1;
    }
}

ll querry(ll x) {
    ll res = 0;
    while(x > 0) {
        if(!used[x]) {
            res += mp[x];
            used[x] = true;
        } else {
            res -= mp[x];
        }
        x >>= 1;
    }
    return res;
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int type; scanf("%d", &type);
        if(type == 1) {
            ll u, v, w;
            cin >> u >> v >> w;
            used.clear();
            update(u, w); update(v, w);
        } else if(type == 2) {
            ll u, v;
            cin >> u >> v;
            used.clear();
            ll res = 0;
            res += querry(u) + querry(v);
            cout << res << endl;
        }
    }
    return 0;
}

