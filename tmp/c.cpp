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
const int MAXN = 20; //最大点数
int n, m; //点数，边数
int G[MAXN][MAXN];
int dp[1<<MAXN][MAXN];
int path[1<<MAXN][MAXN]; //记录路径

void get_path(int mask, int j) {
    if(mask == 0) return;
    get_path(mask ^ (1<<j), path[mask][j]);
    printf("%d ", j);
}

bool solve() {
    dp[0][0] = 1;
    for (int mask = 0; mask < (1<<n); mask++) {
        for (int i = 0; i < n; i++) {
            if(dp[mask][i]) {
                for (int j = 0; j < n; j++) {
                    if(!G[i][j]) continue;
                    if(!((mask>>j) & 1)) {
                        dp[mask|1<<j][j] = 1;
                        path[mask|1<<j][j] = i;
                    }
                }
            }
        }
    }
    if(dp[(1<<n)-1][0]) {
        printf("0 ");
        get_path((1<<n)-1, 0);
        return true;
    }
    return false;
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m); // 输入图的点数，边数
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v); //输入一条边, 0 1,表示节点0 和节点1 有条边
        G[u][v] = G[v][u] = 1;
    }
    if(solve()) puts("yes");
    else puts("no");
    return 0;
}

