/************************************************
 *Author        :mathon
 *Created Time  :一  4/25 14:21:18 2016
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
vector<int> vi;
#define xx first
#define yy second
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++)
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl

const int maxn = 100 + 5;
const int maxq = 1e4 + 5;
int A[maxn][maxn];
int OP[maxq], R[maxq], C[maxq], X[maxq];
int n, m, q;
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &OP[i]);
        if(OP[i] == 1) {
            scanf("%d", &R[i]);
            R[i]--;
        } else if(OP[i] == 2) {
            scanf("%d", &C[i]);
            C[i]--;
        } else {
            scanf("%d%d%d", &R[i], &C[i], &X[i]);
            R[i]--;
            C[i]--;
        }
    }

    for (int i = q - 1; i >= 0; i--) {
        if(OP[i] == 1) {
            int r = R[i];
            int t = A[r][m-1];
            for (int j = m - 1; j > 0; j--) {
                A[r][j] = A[r][j-1];
            }
            A[r][0] = t;
        } else if(OP[i] == 2) {
            int c = C[i];
            int t = A[n-1][c];
            for (int j = n - 1; j > 0; j--) {
                A[j][c] = A[j-1][c];
            }
            A[0][c] = t;
        } else if(OP[i] == 3) {
            int r = R[i], c = C[i];
            A[r][c] = X[i];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d%c", A[i][j], (j == m - 1 ?  '\n' : ' '));
        }
    }
    return 0;
}
