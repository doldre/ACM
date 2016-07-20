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
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int N = 1e4 + 10, inf = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
typedef pair<double, double> P;
P a[N];

double dfs(int l, int r) {
    if(l == r) return inf;
    int m = (l + r) >> 1;
    double x = a[m].xx;
    double d = min(dfs(l, m), dfs(m + 1, r));
    inplace_merge(a + l, a + m + 1, a + r + 1, [](P x, P y) {
            return x.yy < y.yy;
    });

    vector<int> v;
    for (int i = l; i <= r; i++) {
        if(abs(a[i].xx - x) >= d) continue;
        
        for (int j = v.size() - 1; j >= 0; j--) {
            int k = v[j];
            double dy = a[i].yy - a[k].yy;
            if(dy >= d) break;
            double dx = a[i].xx - a[k].xx;
            d = min(d, hypot(dx, dy));
        }
        v.push_back(i);
    }
    return d;
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(scanf("%d", &n) == 1 && n) {
        for (int i = 1; i <= n; i++) {
            scanf("%lf%lf", &a[i].xx, &a[i].yy);
        }
        sort(a + 1, a + 1 + n);

        double d = dfs(1, n);
        if(d >= 1e4) {
            puts("INFINITY");
        } else {
            printf("%.4f\n", d);
        }
    }
    return 0;
}

