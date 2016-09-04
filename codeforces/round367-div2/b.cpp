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
int X[MAXN];
int pre_sum[MAXN];
int n;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        pre_sum[x]++;
    }
    for (int i = 1; i < MAXN; i++) {
        pre_sum[i] += pre_sum[i-1];
    }
    int q;
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        int m; scanf("%d", &m);
        m = min(MAXN - 1, m);
        printf("%d\n", pre_sum[m]);
    }
    return 0;
}

