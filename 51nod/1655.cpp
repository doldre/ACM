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

const int MAXN = 100 + 5;
int G[MAXN][MAXN];

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", n);
        if((n - 1) % 2 != 0) {
            puts("No solution");
        } else {
            for (int i = 1; i <= n; i++) {
                for (int j = i + 1; j <= n; j++) {
                    printf("%d %d %d ", i, j, (i + j) % n + 1);
                }
            }
            puts("");
        }
    }
    return 0;
}

