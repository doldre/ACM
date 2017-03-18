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

const ll MOD = 1e9 + 7;
const int MAXN  = 1e5 + 5;
ll dp[MAXN];
int sum[MAXN];
map<int, int> cnt;

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int N; scanf("%d", &N);
    cnt.clear();
    for (int i = 1; i <= N; i++) {
        int a; scanf("%d", &a);
        sum[i] = sum[i-1] + a;
    }
    dp[0] = 1;
    cnt[0] = 1;
    ll all = 1;
    for (int i = 1; i <= N; i++) {
        int tmp = 0;
        if(cnt.count(sum[i]) != 0) {
            tmp = cnt[sum[i]];
        } 
        dp[i] = ((all - tmp) % MOD + MOD) % MOD;
        cnt[sum[i]] = (tmp + dp[i]) % MOD;
        all = (all + dp[i]) % MOD;
    }
    printf("%lld\n", dp[N]);
    return 0;
}

