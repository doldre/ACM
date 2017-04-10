#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const ll inf = 1e18 + 7;
map<pll, pll> mp;

pll dfs(ll n, ll k) {
    if (k == 1) {
        return pll((n - 1) / 2, n / 2);
    }
    if(mp.count(pll(n, k)) > 0) return mp[pll(n, k)];
    else {
        pll res(inf, inf);
        if(k > 2) res = dfs((n - 1) / 2, (k - 1) / 2);
        res = min(res, dfs(n / 2, k / 2));
        return mp[pll(n, k)] = res;
    }
}

int main() {
    int T; scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        ll N, K;
        scanf("%lld%lld", &N, &K);
        pll res = dfs(N, K);
        printf("Case #%d: %lld %lld\n", Cas, res.second, res.first);
    }
    return 0;
}
