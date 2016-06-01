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
#define sa(n) scanf("%d", &(n))
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 4096;
const double eps = 1e-9;
double A[maxn];
int n;
double t;
void dfs(int deep, int num, double v) {
    if(deep > n) return;
    double det = min(v, 1 - A[num]);
    v -= det;
    A[num] += det;
    if(v > eps) {
        dfs(deep + 1, num + deep, v / 2);
        dfs(deep + 1, num + deep + 1, v / 2);
    }
}
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin >> n >> t;
    dfs(1, 1, t);
    int ans = 0;
    for (int i = 1; i < maxn; i++) {
        /* prln(A[i]); */
        if(abs(A[i] - 1) < eps) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
