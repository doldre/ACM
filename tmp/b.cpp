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
const int inf = 0x3f3f3f3f;
const int maxn = 500 + 5;
int mp[maxn][maxn];
int A[maxn];
int n;
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
    }
    memset(mp, 0x3f, sizeof(mp));
    for (int i = 1; i <= n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        mp[a][b] = 1;
        mp[b][a] = 1;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if(gcd(A[i], A[j]) == 1) {
                ans += mp[i][j];
            }
        }
    }
    printf("%d\n", ans);
    return 0;

