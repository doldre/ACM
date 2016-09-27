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
const int MAXN = 15 + 5;
ll A[MAXN];
ll B[MAXN];
int T, n, x0;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &T);
    while(T--) {
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
        scanf("%d%d", &n, &x0);
        for (int i = 0; i <= n; i++) {
            scanf("%lld", &A[i]);
        }
        for (int i = n - 1; i >= 0; i--) {
            B[i] = A[i+1] + B[i+1] * x0;
        }
        ll r = A[0] + B[0] * x0;
        printf("%lld\n", r);
        for (int i = 0; i <= n - 1; i++) {
            printf("%lld ", B[i]);
        }
        printf("\n");
    }
    return 0;
}

