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

const ull sed = 1331;
const int MAXN = 1e5 + 5;
vector<int> G[MAXN];
ull _hash[MAXN];

void cal(int u, int fa) {
    _hash[u] = 1;
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        if(v == fa) continue;
        cal(v, u);
        _hash[u] += _hash[v] * sed;
    }
}
int n;
int main(void) {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    cal(1, -1);
    map<ull, int> mp;
    for (int i = 1; i <= n; i++) {
        // pr(i);
        // prln(_hash[i]);
        mp[_hash[i]]++;
    }
    map<ull, int>::iterator it;
    ll ans = 0;
    for (it = mp.begin(); it != mp.end(); it++) {
        ans += (ll)it->second * (it->second - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}

