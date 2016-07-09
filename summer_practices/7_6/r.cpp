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
const int maxn = 100 + 5;
double dp[maxn][maxn][maxn];

bool judge(int a, int b, int c) {
    int t = (a > 0) + (b > 0) + (c > 0);
    return t >= 2;
}
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int r, s, p;
    scanf("%d%d%d", &r, &s, &p);
    dp[r][s][p] = 1;
    double ansr = 0, anss = 0, ansp = 0;

    for (int i = r; i >= 0; i--) {
        for (int j = s; j >= 0; j--) {
            for (int k = p; k >= 0; k--) {
                if(judge(i + 1, j, k)) dp[i][j][k] += dp[i+1][j][k] * double((i+1)*k)/double((i+1)*j + (i+1)*k + j*k);
                if(judge(i, j + 1, k)) dp[i][j][k] += dp[i][j+1][k] * double((j+1)*i)/double(i*(j+1) + i*k + (j+1)*k);
                if(judge(i, j, k + 1)) dp[i][j][k] += dp[i][j][k+1] * double((k+1)*j)/double(i*j + i*(k+1) + j*(k+1));
            }
        }
    }

    for (int i = 1; i < maxn; i++) {
        ansr += dp[i][0][0];
        anss += dp[0][i][0];
        ansp += dp[0][0][i];
    }

    printf("%.9f %.9f %.9f\n", ansr, anss, ansp);
    return 0;
}
