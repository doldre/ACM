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

const int MAXN = 1e3 + 5;
int board[MAXN][MAXN];
int row[MAXN];
int n, m, q;

int main(void) {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d", &n, &m, &q);
        memset(board, 0, sizeof(board));
        for (int i = 1; i <= n; i++) row[i] = i;
        while(q--) {
            int op; scanf("%d", &op);
            if(op == 1) {
                int c, x, y;
                scanf("%d%d%d", &c, &x, &y);
                x = row[x];
                board[x][y] = c;
            } else {
                int x1, x2; scanf("%d%d", &x1, &x2);
                swap(row[x1], row[x2]);
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                printf("%c", ".wb"[board[row[i]][j]]);
            }
            puts("");
        }
    }
    return 0;
}

