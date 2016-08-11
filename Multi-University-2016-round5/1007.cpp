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
const int MAX_LEN = 20;
const int MAXK = 6;
map<vector<int>, ll> dp[MAX_LEN][MAXK];
ll L, R;
int K;
ll dfs(int pos, vector<int> pre, int limit, vector<int> &dig) {
    if(pos < 0) return 1;
    if(!limit && dp[pos][K].find(pre) != dp[pos][K].end()) {
        return dp[pos][K][pre];
    }
    int last = limit ? dig[pos] : 9;
    ll ret = 0;
    for (int i = 0; i <= last; i++) {
        if(find(pre.begin(), pre.end(), i) != pre.end()) continue;
        vector<int> nxt;
        for(int j = ((int)pre.size() == K - 1 ? 1 : 0); j < (int)pre.size(); j++) {
            nxt.emplace_back(pre[j]);
        }
        if(!pre.empty() || i != 0) nxt.emplace_back(i);
        ret += dfs(pos - 1, nxt, limit && i == last, dig);
    }
    if (!limit) {
        dp[pos][K][pre] = ret;
    }
    return ret;
}

ll cal(ll x) {
    vector<int> dig;
    if(x == 0) dig.push_back(0);
    while(x > 0) {
        dig.emplace_back(x % 10);
        x /= 10;
    }
    return dfs(dig.size() - 1, vector<int>(), 1, dig);
}
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(scanf("%lld%lld%d", &L, &R, &K) == 3) {
        printf("%lld\n", cal(R) - cal(L-1));
    }
    return 0;
}

