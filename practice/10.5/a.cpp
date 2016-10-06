#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define pr(x) cout << #x << " = " << x << " "
#define prln(x) cout << #x << " = " << x << endl
const int MAXN = 1e5 + 5;
char str[MAXN];
int A[MAXN];
int n;
const char easy[] = "easy";
int dp[MAXN][4][20];
int last[MAXN][4][20];
int convert(char c) {
    for (int i = 0; i <= 3; i++) {
        if(c == easy[i]) return i;
    }
    return 0;
}

void init() {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 4; j++) {
            dp[i][j][0] = j == 2 && A[i] == 3;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 4; j++) {
            last[i][j][0] = (A[i] == (j+1) % 4) ? A[i] : j;
        }
    }
    for (int k = 1; k < 20; k++) {
        for (int i = 1; i + (1<<k) - 1 <= n; i++) {
            for (int j = 0; j < 4; j++) {
                int t = last[i][j][k-1];
                dp[i][j][k] = dp[i][j][k-1] + dp[i+(1<<(k-1))][t][k-1];
                last[i][j][k] = last[i+(1<<(k-1))][t][k-1];
            }
        }
    }
}
int main() {
    scanf("%s", str);
    n = strlen(str);
    for (int i = 0; i < n; i++) {
        A[i+1] = convert(str[i]);
    }
    init();
    int m; scanf("%d", &m);
    while(m--) {
        int l, r; scanf("%d%d", &l, &r);
        int k = (r - l + 1);
        int i = 0;
        int ans = 0, ed = 3;
        while(k > 0) {
            if(k & 1) {
                ans += dp[l][ed][i];
                ed = last[l][ed][i];
                l = l + (1<<i);
            }
            i++;
            k >>= 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
