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

const int MAXN = 50 + 5;
int A[MAXN][MAXN];
int n, m;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        memset(A, 0, sizeof(A));
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                scanf("%d", &A[i][j]);
                if(A[i][j]) ans++;
            }
        }
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= m + 1; j++) 
                ans += abs(A[i][j] - A[i][j-1]);
        for (int j = 1; j <= m; j++) 
            for (int i = 1; i <= n + 1; i++) 
                ans += abs(A[i][j] - A[i-1][j]);
        printf("%d\n", ans);
    }
    return 0;
}

