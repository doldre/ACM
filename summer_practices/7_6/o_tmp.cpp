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
double pro[maxn][maxn];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n, s;
    scanf("%d%d", &n, &s);
    dp[0][0] = 0;
    pro[0][0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            double p1 = double(i) / n, p2 = double(j) / s;
            double t = 1 - p1 * p2;
            if(pro[0][0] == 0) continue;
            pro[i+1][j] += pro[i][j] * (1 - p1) * p2 / t;
            pro[i+1][j+1] += pro[i][j] * (1 - p1) * (1 - p2) / t;
            pro[i][j+1] += pro[i][j] * p1 * (1 - p2) / t;
            dp[i+1][j] += (dp[i][j] + 1/ t) * (1 - p1) * p2 / t; 
            dp[i+1][j+1] += (dp[i][j] + 1/ t) * (1 - p1)*(1-p2)/t; 
            dp[i][j+1] += (dp[i][j] + 1/ t) * p1 * (1 - p2) / t; 
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            printf("%.4f ", dp[i][j]);
        }
        puts("");
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            printf("%.4f ", pro[i][j]);
        }
        puts("");
    }
    
    printf("%.4f\n", dp[n][s]);
    return 0;
}
