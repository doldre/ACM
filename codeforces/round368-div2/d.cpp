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
#include <bitset>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
#define xx first
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
template<class T> inline T lowbit(T x) { return x & (-x); }

const int MAXN = 1e3 + 5, MAXQ = 1e5 + 5;
bitset<1024> bit[MAXQ + MAXN];
int cnt = 0;
int root[MAXQ][MAXN];
int ans[MAXQ];

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= q; i++) {
        int op;
        scanf("%d", &op);
        if(op == 1) {
            int a, b;
            scanf("%d%d", &a, &b);
            memcpy(root[i], root[i-1], sizeof(root[i]));
            bit[++cnt] = bit[root[i][a]];
            root[i][a] = cnt;
            ans[i] = ans[i-1];
            if (!bit[cnt][b]) {
                ans[i]++;
                bit[cnt][b] = true;
            }
        } else if(op == 2) {
            int a, b;
            scanf("%d%d", &a, &b);
            memcpy(root[i], root[i-1], sizeof(root[i]));
            bit[++cnt] = bit[root[i][a]];
            root[i][a] = cnt;
            ans[i] = ans[i-1];
            if (bit[cnt][b]) {
                ans[i]--;
                bit[cnt][b] = false;
            }
        } else if(op == 3) {
            int a;
            scanf("%d", &a);
            memcpy(root[i], root[i-1], sizeof(root[i]));
            bit[++cnt] = bit[root[i][a]];
            root[i][a] = cnt;
            int tmp = bit[cnt].count();
            if(bit[cnt][0]) tmp -= (1024 - m);
            bit[cnt].flip();
            ans[i] = ans[i-1];
            ans[i] += m - tmp - tmp;
        } else if(op == 4) {
            int k; scanf("%d", &k);
            memcpy(root[i], root[k], sizeof(root[i]));
            ans[i] = ans[k];
        }
        printf("%d\n", ans[i]);
    }
    return 0;
}

