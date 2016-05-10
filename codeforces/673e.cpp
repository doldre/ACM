/************************************************
 *Author        :mathon
 *Created Time  :一  5/ 9 17:45:04 2016
 *Problem class:
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
#define sa(n) scanf("%d", &(n))
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 2e5 + 5;
double sum[maxn], rev[maxn], sumres[maxn];
double A[maxn];
double dp[maxn][50 + 5];
int que[maxn], head, tail;

double gety(int i, int k) {
    return dp[i][k-1] - sumres[i] + sum[i] * rev[i];
}

double cost(int j, int i) {
    return sumres[i] - sumres[j] - sum[j]*(rev[i] - rev[j]);
}

int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n, K;
    sa(n); sa(K);
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &A[i]);
        sum[i] = sum[i-1] + A[i];
        rev[i] = rev[i-1] + 1/A[i];
        sumres[i] = sumres[i-1] + sum[i] / A[i];
        /* pr(sum[i]); pr(rev[i]); prln(sumres[i]); */
        dp[i][1] = sumres[i];
        /* prln(sumres[i]); */
    }
    for (int k = 2; k <= K; k++) {
        head = tail = 0;
        que[tail++] = k-1;
        for (int i = k; i <= n; i++) {
            while(head + 1 < tail) {
                int qi = i, qj = que[head+1], qk = que[head];
                double yj = gety(qj, k), yk = gety(qk, k);
                double xj = sum[qj], xk = sum[qk];
                /* pr(yj - yk); */
                /* prln(rev[qi] * (xj - xk)); */
                /* pr(qi); prln(rev[qi]); */
                if(yj - yk <= rev[qi] * (xj - xk)) head++;
                else break;
            }
            int t = que[head];
            /* pr(i);prln(t); */
            dp[i][k] = dp[t][k-1] + cost(t, i);
            /* pr(cost(t, i)); */
            /* prln(dp[i][k]); */
            while(head + 1 < tail) {
                int qi = i, qj = que[tail - 1], qk = que[tail - 2];
                double yi = gety(qi, k), yj = gety(qj, k), yk = gety(qk, k);
                double xi = sum[qi], xj = sum[qj], xk = sum[qk];
                if((yi - yj) * (xj - xk) <= (yj - yk) * (xi - xj)) tail--;
                else break;
            }
            que[tail++] = i;
        }
    }
    printf("%.10f\n", dp[n][K]);
    return 0;
}
