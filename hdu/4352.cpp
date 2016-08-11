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

const int MAXN = 65;
const int MAX_STATE = 1 << 10;
const int MAXK = 11;
ll dp[MAXK][MAXN][MAX_STATE];
ll L, R;
int K;
ll dfs(int pos, int state, int limit, vector<int> &dig) {
    if(pos < 0) {
        return __builtin_popcount(state) == K;
    }
    if(!limit && dp[K][pos][state] != -1) {
        return dp[K][pos][state];
    }
    int last = limit ? dig[pos] : 9;
    ll ret = 0;
    for (int i = 0; i <= last; i++) {
        int t = -1;
        for (int j = 0; j <= 9; j++) {
            if(((state >> j) & 1) && j >= i) {
                t = j;
                break;
            }
        }
        int nxt = state;
        if(t != -1) nxt = state ^ (1 << t) ^ (1 << i);
        else if(i != 0) nxt = state ^ (1 << i); 
        ret += dfs(pos - 1, nxt, limit && i == last, dig);
    }
    if(!limit) {
        dp[K][pos][state] = ret;
    }
    return ret;
}

ll cal(ll x) {
    vector<int> dig;
    if(x == 0) dig.push_back(0);
    while(x > 0) {
        dig.push_back(x % 10);
        x /= 10;
    }
    return dfs(dig.size() - 1, 0, true, dig);
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    memset(dp, -1, sizeof(dp));
    for (int Cas = 1; Cas <= T; Cas++) {
        scanf("%lld%lld%d", &L, &R, &K);
        ll ans = cal(R) - cal(L - 1);
        printf("Case #%d: %lld\n", Cas, ans);
    }
    return 0;
}

