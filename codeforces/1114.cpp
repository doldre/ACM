#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
const int maxn = 500 + 5;
const int maxf = 10000 + 5;
const int inf = 0x3f3f3f3f;
int dp[maxf];
int P[maxn], W[maxn];
int n;
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int E, F;
        scanf("%d%d", &E, &F);
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &P[i], &W[i]);
        }
        int maxw = F - E;
        dp[0] = 0;
        for (int i = 1; i <= maxw; i++) dp[i] = inf;
        for (int i = 0; i < n; i++) {
            int p = P[i], w = W[i];
            for (int j = w; j <= maxw; j++) {
                dp[j] = min(dp[j], dp[j-w] + p);
            }
        }
        if(dp[maxw] < inf) {
             printf("The minimum amount of money in the piggy-bank is %d.\n", dp[maxw]);
        } else {
            printf("This is impossible.\n");
        }
    }
    return 0;
}
