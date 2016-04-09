#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

const int maxn = 300000 + 5;
int dp[maxn], A[maxn];
int n;
int main() {
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &A[i]);
            dp[i] = 1;
        }
        int ans = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if(A[i] > A[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    ans = max(ans, dp[i]);
                }
            }
        }
        printf("%d\n", ans);
    }
}
