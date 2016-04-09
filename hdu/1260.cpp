#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 2000 + 5;
const int inf = 0x3f3f3f3f;
int S[maxn];
int D[maxn];
int dp[maxn];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &S[i]);
        }
        for (int i = 2; i <= n; i++) {
            scanf("%d", &D[i]);
        }

        dp[1] = S[1];
        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[i-1] + S[i], dp[i - 2] + D[i]);
        }
        int hour = 8, min = 0, sec = dp[n];
        min = sec / 60; sec = sec % 60;
        hour += min / 60; min = min % 60;
        printf("%02d:%02d:%02d am\n", hour, min, sec);
    }
    return 0;
}
