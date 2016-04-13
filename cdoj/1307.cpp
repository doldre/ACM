#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 5000 + 5;;
typedef long long ll;
int dp[maxn][maxn];
const int mod = (int)1e9 + 7;

int main() {
    for (int i = 1; i < maxn; i++) dp[1][i] = 1;
    for (int i = 2; i < maxn; i++) {
        for (int j = 1; j < maxn; j++) {
            if(j <= (i + 1) / 2) dp[i][j] = (dp[i][j-1] + dp[i-j][j]) % mod;
            else dp[i][j] = dp[i][j-1];
        }
    }

    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        cout << dp[n][(n+1)/2] << endl;
    }
    return 0;
}
