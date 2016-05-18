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
#define sa(n) scanf("%d", &(n))
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const ll mod = 1e9 + 7;
const int maxm = 500 + 5;

struct Mat {
    ll m[3][3];
    Mat() {
        memset(m, 0, sizeof(m));
    }
    void print() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf("%lld ", m[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
};

Mat mat_multy(const Mat &A, const Mat &B) {
    Mat C;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                C.m[i][j] = (C.m[i][j] + A.m[i][k] * B.m[k][j]) % mod;
            }
        }
    }
    return C;
}

Mat mat_pow(Mat A, ll n) {
    Mat res;
    for (int i = 0; i < 3; i++) res.m[i][i] = 1;
    while(n) {
        if(n & 1) {
            res = mat_multy(res, A);
        }
        A = mat_multy(A, A);
        n >>= 1;
    }
    return res;
}

ll X[maxm];
ll n;
int m;

int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    sa(T);
    while(T--) {
        Mat O;
        O.m[0][0] = 0; O.m[1][0] = 0; O.m[2][0] = 1;
        Mat A;
        A.m[2][0] = 1; A.m[2][1] = 1; A.m[2][2] = 1;
        A.m[1][2] = 1; A.m[0][1] = 1;
        scanf("%lld%d", &n, &m);
        for (int i = 1; i <= m; i++) {
            scanf("%lld", &X[i]);
        }
        sort(X + 1, X + m + 1);
        ll last = 0;
        Mat last_mat = O;
        /* last_mat.print(); */
        for (int i = 1; i <= m; i++) {
            ll x = X[i];
            last_mat = mat_multy(mat_pow(A, x - last), last_mat);
            last_mat.m[2][0] = 0;
            last = x;
        }
        last_mat = mat_multy(mat_pow(A, n - last), last_mat);
        printf("%lld\n", last_mat.m[2][0]);
    }
    return 0;
}
