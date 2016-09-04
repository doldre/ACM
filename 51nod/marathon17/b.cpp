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

const ll mod = 1e9 + 7;

struct Mat {
    ll a[2][2];
    Mat() {
        memset(a, 0, sizeof(a));
    }
    Mat operator * (const Mat &b) const {
        Mat c;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    c.a[i][j] = (c.a[i][j] + a[i][k] * b.a[k][j]) % mod;
                }
            }
        }
        return c;
    }
};

Mat mat_pow(Mat a, ll n) {
    Mat res;
    for (int i = 0; i < 2; i++) res.a[i][i] = 1;
    while(n > 0) {
        if(n & 1) {
            res = res * a;
        }
        a = a * a;
        n >>= 1;
    }
    return res;
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    Mat A;
    A.a[0][0] = 1; A.a[0][1] = 2;
    A.a[1][0] = 1; A.a[1][1] = 1;
    Mat res;
    res.a[0][0] = 1; res.a[1][0] = 1;
    ll n;
    scanf("%lld", &n);
    res = mat_pow(A, n - 1) * res;
    ll t = res.a[0][0];
    ll m;
    if(n & 1) {
        m = (t * t + 1) % mod;
    } else {
        m = (t * t) % mod;
    }
    printf("%lld\n", m);
    return 0;
}

