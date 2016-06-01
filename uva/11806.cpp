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

const int mod = 1000007;

const int maxn = 500 + 5;
int C[maxn][maxn];

void init() {
    memset(C, 0, sizeof(C));
    for (int i = 0; i < maxn; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
        }
    }
}
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    init();
    int T;
    cin >> T;
    for (int Cas = 1; Cas <= T; Cas++) {
        int m, n, k;
        cin >> m >> n >> k;
        int ans = 0;
        for (int mask = 0; mask < 16; mask++) {
            int r = m, c = n;
            int b = 0;
            if(mask & 1) {
                r--;
                b++;
            }
            if(mask & 2) {
                r--;
                b++;
            }
            if(mask & 4) {
                c--;
                b++;
            }
            if(mask & 8) {
                c--;
                b++;
            }
            if(b & 1) {
                ans = (ans + mod - C[c*r][k]) % mod;
            } else {
                ans = (ans + C[c*r][k]) % mod;
            }
        }
        printf("Case %d: %d\n", Cas, ans);
    }
    return 0;
}
