#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef pair<int, int> pii;
const int maxn = 100000 + 5;
int dp[maxn][15];
int A[maxn][15];
int main() {
    int n;
    while(scanf("%d", &n) == 1 && n) {
        memset(A, 0, sizeof(A));
        memset(dp, 0, sizeof(dp));
        dp[0][6] = 0;
        int maxT = 0;
        for (int i = 0; i < n; i++) {
            int x, T;
            scanf("%d%d", &x, &T);
            maxT = max(maxT, T);
            A[T][x+1]++;
        }

        for (int i = maxT; i >= 0; i--) {
            for (int j = 1; j <= 11; j++) {
                for (int k = -1; k <= 1; k++) {
                    dp[i][j] = max(dp[i][j], dp[i+1][j+k] + A[i][j]);
                }
            }
        }
        cout << dp[0][6] << endl;
    }
    return 0;
}
