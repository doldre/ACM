#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
const int maxm = 20 + 5;
const int maxn = 200 + 5;
const int maxv = 400 + 5;
int dp[maxv][maxv][maxm];
int n, m;
int D[maxn], P[maxn];
int main() {
    while(scanf("%d%d", &n, &m) == 2) {
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &D[i], &P[i]);
        }
        dp[0][0][0] = 1;
    }
}
