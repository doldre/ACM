#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
const int MAXN = 5e4 + 5;
ll dp[MAXN];

void init() {
    dp[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        for (int j = 1; j <= i; j++) {
            int t = j*(3*j-1)/2;
            if(t > i) break;
            if(j & 1) dp[i] = (dp[i] + dp[i-t]) % MOD;
            else dp[i] = (dp[i] - dp[i-t] + MOD) % MOD;
            t = j * (3*j + 1) / 2;
            if(t > i) break;
            if(j & 1) dp[i] = (dp[i] + dp[i-t]) % MOD;
            else dp[i] = (dp[i] - dp[i-t] + MOD) % MOD;
        }
    }
}

int main() {
    init();
    int n;
    scanf("%d", &n);
    printf("%lld\n", dp[n]);
    return 0;
}
