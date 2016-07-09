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
const int maxn = 15;
int M, N;
int src[maxn];
int dp[maxn];
int buf[maxn];
int ans[maxn];
void work(int &x, int mask) {
    for (int i = 0; i < N; i++) {
        if((mask >> i) & 1) {
            x ^= 1<<i;
            x ^= (1<<i) >> 1;
            if(i < N - 1) x ^= ((1<<i)<<1);
        }
    }
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &M, &N);
    memset(dp, 0, sizeof(0));
    memset(src, 0, sizeof(src));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int x; scanf("%d", &x);
            src[i] |= x << (N - j - 1);
        }
    }
    int cnt = inf;
    for (int mask = 0; mask < (1 << N); mask++) {
        memcpy(dp, src, sizeof(src));
        int t = mask;
        for (int i = 0; i < M; i++) {
            work(dp[i], t);
            buf[i] = t;
            if(i + 1 < M) {
                dp[i+1] ^= t;
            }
            t = dp[i];
        }
        if(dp[M-1] == 0) {
            int t = 0;
            for (int i = 0; i < M; i++) {
                t += __builtin_popcount(buf[i]);
            }
            if(t < cnt) {
                cnt = t;
                memcpy(ans, buf, sizeof(buf));
            }
        }
    }
    if(cnt == inf) {
        printf("IMPOSSIBLE\n");
    } else {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d%c", ((ans[i]>>(N-1-j)) & 1), 
                        j == N - 1 ? '\n' : ' ');
            }
        }
    }
    return 0;
}

