#include <cstdio>
#include <iostream>
using namespace std;
const double eps = 1e-9;
const int maxn = 2000 + 5;
double dp[maxn][maxn];
double c[maxn];
int main(void)
{
    int n, m, k;
    double p1, p2, p3, p4;
    while(cin >> n >> m >> k) {
        cin >> p1 >> p2 >> p3 >> p4;
        if((1 - p1) < eps || p4 < eps) {
            printf("0.00000\n");
            continue;
        }
        double p21 = p2 / (1 - p1), p31 = p3 / (1 - p1), p41 = p4 / (1 - p1);
        dp[1][1] = p41 / (1 - p21);
        for (int i = 2; i <= n; i++) {
            c[1] = p41;
            for (int j = 2; j <= i; j++) {
                if(j <= k) {
                    c[j] = dp[i-1][j-1] * p31 + p41;
                } else {
                    c[j] = dp[i-1][j-1] * p31;
                }
            }

            double p = 1, tmp = 0;
            for (int j = i; j >= 1; j--) {
                tmp += p * c[j];
                p *= p21;
            }
            dp[i][i] = tmp / (1 - p);
            dp[i][1] = dp[i][i] * p21 + p41;
            for (int j = 2; j < i; j++) {
                dp[i][j] = dp[i][j-1] * p21 + c[j];
            }
        }
        printf("%.5f\n", dp[n][m]);
    }
    return 0;
}
