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
const int maxn = 1e5 + 5;
int X[maxn];
ll tot;
int n;

bool judge(int x) {
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        int t = X[i] + x;
        int p = upper_bound(X + i + 1, X + n, t) - X;
        cnt += p - i - 1;
    }
    return cnt < tot;
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
     while(scanf("%d", &n) == 1) {
         int l = 0, r = 0;
         for (int i = 0; i < n; i++) {
             scanf("%d", &X[i]);
             r = max(r, X[i]);
         }
         r += 1;
         sort(X, X + n);
         tot = ll(n) * (n - 1) / 2;
         tot = (tot + 1) / 2;
         while(l < r - 1) {
             int m = (l + r) >> 1;
             if(judge(m)) {
                 l = m;
             } else {
                 r = m;
             }
         }
         printf("%d\n", r);
     }
    return 0;
}

