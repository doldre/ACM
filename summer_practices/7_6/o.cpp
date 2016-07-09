/************************************************
 *Author        :mathon
 *Email         :luoxinchen96@gmail.com
*************************************************/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stack>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
#define xx first
#define lowbit(x) (x&-x)
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 1000 + 5;
double dp[maxn][maxn];

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n, s;
    scanf("%d%d", &n, &s);
    dp[n][s] = 0;
    for (int i = n; i >= 0; i--) {
        for (int j = s; j >= 0; j--) {
            if(i == n && j == s) continue;
            double p1 = double(i) / n, p2 = double(j) / s;
            double t = 1 - p1 * p2;
            dp[i][j] += (dp[i+1][j] + 1/ t) * (1 - p1) * p2 / t; 
            dp[i][j] += (dp[i+1][j+1] + 1/ t) * (1 - p1)*(1-p2)/t; 
            dp[i][j] += (dp[i][j+1] + 1/ t) * p1 * (1 - p2) / t; 
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            printf("%.4f ", dp[i][j]);
        }
        puts("");
    }

    printf("%.4f\n", dp[0][0]);
    return 0;
}

