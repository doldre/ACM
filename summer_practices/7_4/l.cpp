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
#define lowbit(x) (x&-x)
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int mod = 1000007;
const int maxn = 500 + 5;
int C[maxn][maxn];

void init() {
    for (int i = 0; i < maxn; i++) {
        C[i][0] = 1; C[i][i] = 1;
    }
    for (int i = 2; i < maxn; i++) {
        for (int j = 1; j < i; j++) {
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
        }
    }
}

int N, M, K;

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    init();
    int T;
    scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        scanf("%d%d%d", &N, &M, &K);
        int ans = 0;
        for (int mask = 1; mask < 16; mask++) {
            int r = N, c = M, b = 0;
            if(mask & 1) r--, b++;
            if(mask & 2) r--, b++;
            if(mask & 4) c--, b++;
            if(mask & 8) c--, b++;
            if(b % 2 == 1) {
                ans = (ans + C[r * c][K] + mod) % mod;
            } else {
                ans = (ans + mod - C[r * c][K]) % mod;
            }
        }
        // prln(ans);
        ans = ((C[N*M][K] - ans) % mod + mod) % mod;
        printf("Case %d: %d\n", Cas, ans);
    }
    return 0;
}

