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
const ll mod = 1e9 + 7;
const int MAXN = 100 + 5;
const int MAXM = 5e4 + 5;
const int MAX = 100 + 5;
const int N = 100 + 5;
int mu[MAX];//莫比乌斯函数
int tot;
vector<int> fac[MAXN];
void getMu(){       
	for(int i=1;i<N;i++)
		mu[i]=1;
	for(int i=2;i<N;i++){
		if(mu[i]==0)continue;
		mu[i]=-mu[i];
		for(int j=i*2;j<N;j+=i)
			mu[j]+=mu[i];
	}

    for (int i = 1; i < MAXN; i++) {
        for (int j = i; j < MAXN; j += i) {
            fac[j].push_back(i);
        }
    }
}

ll dp[MAXN][MAXN][MAXN]; //dp[x][i][j]
int n, m;

struct Edge {
    int u, v, w;
    Edge() {}
    Edge(int u, int v, int w): u(u), v(v), w(w) {}
}edge[MAXM];

void modify(int flag, int u, int v, int w) {
    for (auto x: fac[w]) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if(dp[x][i][u] == 0 || dp[x][v][j] == 0) continue;
                if(i != j) dp[x][i][j] = (dp[x][i][j] + 
                        flag * dp[x][i][u] * dp[x][v][j] % mod + mod) % mod;
            }
        }
    }
}

int main() {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
#endif
    // init();
    getMu();
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        edge[i] = Edge(u, v, w);
        for (auto x: fac[w]) {
            dp[x][u][v]++;
        }
    }
    for (int x = 1; x <= 100; x++) {
        for (int i = 1; i <= n; i++) {
            dp[x][i][i] = 1;
        }
    }
    for (int x = 1; x <= 100; x++) {
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if(dp[x][i][k] == 0 || dp[x][k][j] == 0) continue;
                    if(i != k && k != j) dp[x][i][j] = (dp[x][i][j] + 
                            dp[x][i][k] * dp[x][k][j] % mod) % mod;
                }
            }
        }
    }

    ll ans = 0;
    for (int x = 1; x <= 100; x++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if(dp[x][i][j] == 0) continue;
                if(i != j) ans = (ans + dp[x][i][j] * mu[x] % mod + mod) % mod;
            }
        }
    }
    printf("%lld\n", ans);
    int T; scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        x--;
        modify(-1, edge[x].u, edge[x].v, edge[x].w);
        edge[x].w = y;
        modify(1, edge[x].u, edge[x].v, edge[x].w);
        ll ans = 0;
        for (int x = 1; x <= 100; x++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if(dp[x][i][j] == 0) continue;
                    if(i != j) ans = (ans + dp[x][i][j] * mu[x] % mod + mod) % mod;
                }
            }
        }
        printf("%lld\n", (ans % mod + mod) % mod);
    }
}
