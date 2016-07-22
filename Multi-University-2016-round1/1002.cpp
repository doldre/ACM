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
const int maxn = 20;
int sg[1<<maxn];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    sg[0] = 0;
    for (int mask = 1; mask < (1<<maxn); mask++) {
        int last = -1;
        int used[maxn + 5];
        memset(used, 0, sizeof(used));
        for (int i = 0; i < maxn; i++) {
            if(!((mask >> i) & 1)) {
                last = i;
            }
            if(((mask >> i) & 1) && last != - 1) {
                used[sg[mask ^ (1<<i) ^ (1<<last)]] = 1;
            }
        }
        int t = 0;
        while(used[t]) t++;
        sg[mask] = t;
    }
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        int ans = 0;
        while(n--) {
            int m;
            scanf("%d", &m);
            int mask = 0;
            for (int i = 0; i < m; i++) {
                int x;
                scanf("%d", &x);
                mask |= (1<<(20 - x));
            }
            ans ^= sg[mask];
        }
        if(ans) {
            printf("YES\n");
        } else printf("NO\n");
    }
    return 0;
}

