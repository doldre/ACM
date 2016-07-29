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
const int MAXN = 900;
const int INF = 0x3f3f3f3f;
const int MOD = 7;
int a[MAXN][MAXN];
int x[MAXN];

inline int gcd(int a, int b) {
    return a == 0 ? b : gcd(b, a % b);
}

inline int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

ll inv(ll a, ll m) {
    if(a == 1) return 1;
    return inv(m % a, m) * (m - m / a) % m;
}

int Gauss(int equ, int var) {
    int max_r, col, k;
    for (k = 0, col = 0; k < equ && col < var; k++, col++) {
        max_r = k;
        for (int i = k + 1; i < equ; i++) {
            if(abs(a[i][col]) > abs(a[max_r][col])) max_r = i;
        }
        
        if(a[max_r][col] == 0) {
            k--;
            continue;
        }
        if(max_r != k) {
            for (int j = col; j < var + 1; j ++) {
                swap(a[k][j], a[max_r][j]);
            }
        }
        for (int i = k + 1; i < equ; i++) {
            if(a[i][col] != 0) {
                int LCM = lcm(abs(a[i][col]), abs(a[k][col]));
                int ta = LCM / abs(a[i][col]);
                int tb = LCM / abs(a[k][col]);
                if(a[i][col] * a[k][col] < 0) tb = -tb;
                for (int j = col; j < var + 1; j++) {
                    a[i][j] = ((a[i][j] * ta - a[k][j] * tb) % MOD 
                            + MOD) % MOD;
                }
            }
        }
        for (int i = k; i < equ; i++) {
            if(a[i][col] != 0) {
                return -1;
            }
        }
    }
    for (int i = k; i < equ; i++) {
        if(a[i][col] != 0) {
            return -1; //无解
        }
    }
    if(k < var) return var - k; // 多解
    for (int i = var - 1; i >= 0; i--) {
        int temp = a[i][var];
        for (int j = i + 1; j < var; j++) {
            if(a[i][j] != 0) {
                temp -= a[i][j] * x[j];
                temp = (temp % MOD + MOD) % MOD;
            }
        }
        x[i] = (temp * inv(a[i][i], MOD)) % MOD;
    }
    return 0;
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    return 0;
}

