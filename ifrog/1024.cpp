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
const int MAXN = 250 + 5;
const int prime[] = {2, 3, 5, 7, 11, 13}, cnt_prime = 6;
const ll MOD = 841815229;
int max_factor[MAXN];
int flag[MAXN];
vector<int> vec[MAXN];
ll N;
int M;
ll dp[2][1<<6][MAXN];

ll per[MAXN];
void cal_per(ll n, int m) {
    per[0] = 1;
    for (int i = 1; i <= m; i++) {
        per[i] = (per[i-1] * ((n - i + 1) % MOD)) % MOD;
    }
}

void init() {
    for (int i = 2; i < MAXN; i++) {
        if(!max_factor[i]) {
            for (int j = i; j < MAXN; j += i) {
                max_factor[j] = i;
            }
        }
    }

    for (int i = 2; i < MAXN; i++) {
        vec[max_factor[i]].push_back(i);
    }

    for (int i = 0; i < cnt_prime; i++) {
        for (int j = prime[i]; j < MAXN; j += prime[i]) {
            flag[j] |= 1 << i;
        }
    }
}

ll cnt[MAXN];
ll solve() {
    int now = 0;
    memset(dp, 0, sizeof(dp));
    dp[now][0][0] = 1;
    for (int i = 2; i < MAXN; i++) {
        now ^= 1;
        memcpy(dp[now], dp[now ^ 1], sizeof(dp[now]));
        for (auto x: vec[i]) {
            if(x > M) continue;
            for (int j = 0; j <= min(N, (ll)M); j++) {
                for (int mask = 0; mask < 1<<6; mask++) {
                    if(dp[now^1][mask][j] && (mask & flag[x]) == 0) { 
                        dp[now][mask | flag[x]][j+1] += 
                            dp[now^1][mask][j];
                        dp[now][mask | flag[x]][j+1] %= MOD;
                    }
                }
            }
        }
    }
    memset(cnt, 0, sizeof(cnt));
    for (int mask = 0; mask < 1<<6; mask++) {
        for (int j = 0; j <= min(N, (ll)M); j++) {
            cnt[j] = (cnt[j] + dp[now][mask][j]) % MOD;
        }
    }
    
    ll ans = 0;
    cal_per(N, min(N, (ll)M));
    for (int i = 0; i <= min(N, (ll)M); i++) {
        // pr(cnt[i]); prln(per[i]);
        ans = (ans + per[i] * cnt[i] % MOD) % MOD;
    }
    return ans;
}


int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    init();
    int T; scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        scanf("%lld%d", &N, &M);
        ll ans = solve();
        printf("Case #%d: %lld\n", Cas, ans);
    }
    return 0;
}

