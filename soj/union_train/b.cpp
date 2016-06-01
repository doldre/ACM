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
#define sa(n) scanf("%d", &(n))
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 100;
int G[maxn][maxn];
int mp[maxn][maxn];
vector<int> ps[maxn][maxn];
int used[maxn];
bool ok;

void dfs(int u) {
    if(used[u]) {
        ok = false;
        /* prln(u); */
        return;
    }
    used[u] = true;
    for (int i = 1; i <= 9; i++) {
        if(G[u][i]) dfs(i);
    }
    used[u] = false;
}
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    for (int i = 1; i <= 9; i++) {
        int y = (i - 1) % 3 + 1;
        int x = (i - 1) / 3 + 1;
        for (int k = 0; k < 2; k++) {
            for (int j = 0; j < 2; j++) {
                ps[x + k][y + j].push_back(i);
            }
        }
    }
    scanf("%d", &T);
    while(T--) {
        memset(G, 0, sizeof(G));
        for (int i = 1; i <= 4; i++) {
            for (int j = 1; j <= 4; j++) {
                int u;
                scanf("%d", &u);
                for (int k = 0; k < (int)ps[i][j].size(); k++) {
                    int v = ps[i][j][k];
                    /* pr(i); pr(j); */
                    /* prln(v); */
                    if(v != u) {
                        G[u][v] = true;
                        /* printf("%d --> %d\n", u, v); */
                    }
                }
            }
        }
        bool res = true;
        for (int i = 1; i <= 9; i++) {
            memset(used, 0, sizeof(used));
            ok = true;
            dfs(i);
            if(!ok) {
                res = false;
                break;
            }
        }
        if(res) {
            printf("Lucky dog!\n");
        } else {
            printf("BOOM!\n");
        }
    }
    return 0;
}
