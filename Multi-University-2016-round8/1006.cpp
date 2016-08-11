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
const int MAXN = 1e5 + 5;

int V[MAXN];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;  scanf("%d", &T);
    while (T--) {
        int n, C;
        scanf("%d%d", &n, &C);
        for (int i = 0; i < n; i++) {
            int t;
            scanf("%d%d%d", &V[i], &t, &t);
        }
        sort(V, V + n);
        int q;
        scanf("%d", &q);
        for (int i = 0; i < q; i++) {
            int t, k;
            scanf("%d%d", &t, &k);
            double ans = (2.0*C*t + double(V[k-1]) * double(V[k-1]));
            printf("%.3f\n", sqrt(ans));
        }
    }
    return 0;
}

