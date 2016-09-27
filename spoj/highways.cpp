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
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
template<class T> inline T lowbit(T x) { return x & (-x); }

const int MX = 15 + 5;
const double eps = 1e-9;
typedef double Matrix[MX][MX];

Matrix A, S;

void gauss(Matrix A, int n) {
    int i, j, k, r;
    for(i = 0; i < n; i++) {
        r = i;
        for(j = i + 1; j < n; j++) {
            if(fabs(A[j][i]) > fabs(A[r][i])) r = j;
        }
        if(r != i) for(j = 0; j <= n; j++) swap(A[r][j], A[i][j]);

        for(k = i + 1; k < n; k++) {
            if(fabs(A[i][i]) < eps) continue;
            double f = A[k][i] / A[i][i];
            for(j = i; j <= n; j++) A[k][j] -= f * A[i][j];
        }
    }
}

int C[MX][MX];
int main(void) {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        int n, m;
        memset(C, 0, sizeof(C));
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            a--; b--;
            C[a][b]--;
            C[b][a]--;
            C[a][a]++;
            C[b][b]++;
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                A[i][j] = C[i][j];
            }
        }
        gauss(A, n - 1);
        double ans = 1;
        for (int i = 0; i < n - 1; i++) ans *= A[i][i];
        printf("%.0f\n", fabs(ans));
    }
    return 0;
}

