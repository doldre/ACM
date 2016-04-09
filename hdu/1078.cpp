#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
const int maxn = 100 + 5;
int mp[maxn][maxn];
int dp[maxn][maxn];
int n, k;

int dfs(int i, int j) {
    if(dp[i][j]) return dp[i][j];
    int res = 0;
    for (int det = 1; det <= k; det++) {
        if(i - det >= 0 && mp[i-det][j] > mp[i][j]) res = max(res, dfs(i - det, j));
        if(i + det < n && mp[i+det][j] > mp[i][j]) res = max(res, dfs(i + det, j));
        if(j - det >= 0 && mp[i][j - det] > mp[i][j]) res = max(res, dfs(i, j - det));
        if(j + det < n && mp[i][j + det] > mp[i][j]) res = max(res, dfs(i, j + det));
    }
    return dp[i][j] = mp[i][j] + res;
}
int main() {
    while(scanf("%d%d", &n, &k) == 2 && n != - 1 && k != -1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &mp[i][j]);
            }
        }
        memset(dp, 0, sizeof(dp));
        printf("%d\n", dfs(0, 0));
    }
    return 0;
}
