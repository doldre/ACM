/************************************************
 *Author        :mathon
 *Created Time  :五  4/22 19:08:45 2016
 *Problem class:
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
vector<int> vi;
#define xx first
#define yy second
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++)
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl

const int maxn = 1000 + 5;
ll M[maxn][maxn];
ll row[maxn], col[maxn];
ll addrow[maxn], addcol[maxn];
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, m, q;
        scanf("%d%d%d", &n, &m, &q);
        for (int i = 1; i <= n; i++) {
            row[i] = i;
            addrow[i] = 0;
        }
        for (int i = 1; i <= m; i++) {
            col[i] = i;
            addcol[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                scanf("%I64d", &M[i][j]);
            }
        }
        for (int i = 0; i < q; i++) {
            int a, x, y;
            scanf("%d%d%d", &a, &x, &y);
            if(a == 1) {
                swap(row[x], row[y]);
            } else if(a == 2) {
                swap(col[x], col[y]);
            } else if(a == 3) {
                int xx = row[x];
                addrow[xx] += y;
            } else if(a == 4) {
                int yy = col[x];
                addcol[yy] += y;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int x = row[i], y = col[j];
                printf("%I64d%c", M[x][y] + addrow[x] + addcol[y], j == m ? '\n' : ' ');
            }
        }
    }
    return 0;
}
