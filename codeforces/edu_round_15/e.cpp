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
const ll INF = 1e18;
const int MAXN = 1e5 + 5;
const int BIT = 35;
int nxt[MAXN][BIT];
ll cost[MAXN][BIT], min_cost[MAXN][BIT];
int main(void) {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n;
    ll k;
    scanf("%d%lld", &n, &k);
    // for (int i = 0; i < n; i++) {
        // for (int j = 0; j < BIT; j++) {
            // min_cost[i][j] = INF;
        // }
    // }
    for (int i = 0; i < n; i++) {
        scanf("%d", &nxt[i][0]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &cost[i][0]);
        min_cost[i][0] = cost[i][0];
    }

    for (int i = 1; i < BIT; i++) {
        for (int j = 0; j < n; j++) {
            nxt[j][i] = nxt[nxt[j][i-1]][i-1];
            cost[j][i] = cost[j][i-1] + cost[nxt[j][i-1]][i-1];
            min_cost[j][i] = min(min_cost[j][i-1], min_cost[nxt[j][i-1]][i-1]);
        }
    }
    
    for (int i = 0; i < n; i++) {
        ll s = 0, Min = INF;
        int u = i;
        for (int i = 0; i < BIT; i++) {
            if((k >> i) & 1) {
                s += cost[u][i];
                Min = min(Min, min_cost[u][i]);
                u = nxt[u][i];
            }
        }
        printf("%lld %lld\n", s, Min);
    }
    return 0;
}

