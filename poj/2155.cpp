/************************************************
 *Author        :mathon
 *Created Time  :五  4/29 11:56:40 2016
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
#define lowbit(x) (x&-x)
#define yy second
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++)
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl

const int maxn = 1000 + 10;

struct Bit {
    int bit[maxn][maxn];
    int n;
    void init(int _n) {
        n = _n;
        memset(bit, 0, sizeof(bit));
    }

    void add(int x, int y, int v) {
        for (int i = x; i <= n; i += lowbit(i)) {
            for (int j = y; j <= n; j+= lowbit(j)) {
                bit[i][j] += v;
            }
        }
    }

    int querry(int x, int y) {
        int res = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            for (int j = y; j > 0; j -= lowbit(j)) {
                res += bit[i][j];
            }
        }
        return res;
    }
}bit;

char op[20];
int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, Q;
        scanf("%d%d", &n, &Q);
        bit.init(n + 1);
        for (int k = 0; k < Q; k++) {
            scanf("%s", op);
            if (op[0] == 'C') {
                int x1, y1, x2, y2;
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                bit.add(x1, y1, 1);
                bit.add(x2 + 1, y2 + 1, 1);
                bit.add(x2 + 1, y1, -1);
                bit.add(x1, y2 + 1, -1);
            } else {
                int x, y;
                scanf("%d%d", &x, &y);
                int t = bit.querry(x, y);
                /* pr(t); */
                printf("%c\n", "01"[t % 2]);
            }
        }
        if(T > 0) printf("\n");
    }
    return 0;
}
