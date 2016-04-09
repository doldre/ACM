#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 5;
char str[maxn][maxn];
int dp[maxn][maxn];
int n;
int dfs(int i, int j) {
    if(i < 0 || i >= n || j < 0 || j >= n) return 0;
    if(dp[i][j]) return dp[i][j];
    int cnt = 1;
    for (int k = 1; i - k >= 0 && j + k < n; k++) {
        if(str[i - k][j] != str[i][j + k]) {
            break;
        }
        cnt++;
    }
    return dp[i][j] = min(cnt, dfs(i - 1, j + 1) + 1);
}
int main() {
    while(scanf("%d", &n) == 1 && n) {
        for (int i = 0; i < n; i++) {
            scanf("%s", str[i]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = 0;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dfs(i, j));
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
