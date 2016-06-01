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
const int maxn = 25 + 5;
int can[maxn][maxn];
int orig[maxn][maxn];
int used[maxn];
int N;
char str[maxn];

bool dfs(int dep, int A[]) {
    if(dep >= N) return true;
    int p = A[dep];
    bool res = true;
    bool ok = false;
    for (int i = 0; i < N; i++) {
        if(can[p][i] && !used[i]) {
            ok = true;
            used[i] = true;
            res &= dfs(dep + 1, A);
            used[i] = false;
        }
    }
    return ok & res;
}

int check() {
    int A[maxn];
    for (int i = 0; i < N; i++) {
        A[i] = i;
    }
    bool ok = true;
    do {
        ok &= dfs(0, A);
    } while(next_permutation(A, A + N));
    return ok;
}

int solve() {
    int len = 1<<(N * N);
    for (int i = 0; i < N * N; i++) {
        for (int mask = 0; mask < len; mask++) {
            if(__builtin_popcount(mask) == i) {
                bool ok = true;
                for (int k = 0; k < N * N; k++) {
                    if(((mask >> k) & 1)) {
                        int x = k / N, y = k % N;
                        if(orig[x][y] == 1) {
                            ok = false;
                            break;
                        }
                    }
                }
                if(ok) {
                    memcpy(can, orig, sizeof(can));
                    for (int k = 0; k < N * N; k++) {
                        if((mask >> k) & 1) {
                            int x = k / N, y = k % N;
                            can[x][y] = 1;
                        }
                    }
                    if(check()) {
                        return i;
                    }
                }
            }
        }
    }
}
int main(void)
{
#ifdef LOCAL
   freopen("D-in.txt", "r", stdin);
   freopen("D-out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%s", str);
            for (int j = 0; j < N; j++) {
                if(str[j] == '0') {
                    orig[i][j] = 0;
                } else if(str[j] == '1') {
                    orig[i][j] = 1;
                }
            }

        }
        int ans = solve();
        printf("Case #%d: %d\n", Cas, ans);
    }
    return 0;
}
