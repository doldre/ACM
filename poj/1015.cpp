#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
typedef long long ll;
const int maxn = 2000 + 5;
const ll inf = ll(1e13);
ll A[maxn];
ll buf[maxn];
ll dp[maxn][maxn];
ll dedp[maxn][maxn];
int N;

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        buf[i] = A[i];
    }
    for (int i = 1; i <= N + 1; i++) {
        for (int j = 0; j <= N + 1; j++) {
            dp[i][j] = inf;
            dedp[i][j] = inf;
        }
    }
    sort(buf + 1, buf + N + 1);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = min(dp[i][j], min(dp[i-1][j] + abs(A[i] - buf[j]), dp[i][j-1]));
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = N; j >= 1; j--) {
            dedp[i][j] = min(dedp[i][j], min(dedp[i-1][j] + abs(A[i] - buf[j]), dedp[i][j+1]));
        }
    }
    ll ans = min(dp[N][N], dedp[N][1]);
    cout << ans << endl;
    return 0;
}
