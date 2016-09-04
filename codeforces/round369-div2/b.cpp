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

const int MAXN = 500 + 5;

ll A[MAXN][MAXN];
int n;
ll cal_row(int r) {
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        res += A[r][i];
    }
    return res;
}

ll cal_col(int c) {
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        res += A[i][c];
    }
    return res;
}

ll cal_md() {
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        res += A[i][i];
    }
    return res;
}

ll cal_od() {
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        res += A[i][n-i+1];
    }
    return res;
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    int r = 0, c = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%lld", &A[i][j]);
            if(A[i][j] == 0) r = i, c = j;
        }
    }
    ll has = -1, none = -1;
    bool ok = true;
    for (int i = 1; i <= n; i++) {
        ll t = cal_row(i);
        if(i == r) {
            if(has == -1) has = t;
            else if(t != has) {
                ok = false;
                break;
            }
        } else {
            if(none == -1) none = t;
            else if(none != t) {
                ok = false;
                break;
            }
        }
        t = cal_col(i);
        if(i == c) {
            if(has == -1) has = t;
            else if(t != has) {
                ok = false;
                break;
            }
        } else {
            if(none == -1) none = t;
            else if(none != t) {
                ok = false;
                break;
            }
        }
    }
    ll t = cal_md();
    if(r == c) {
        if(t != has) {
            ok = false;
        }
    } else {
        if(t != none) {
            ok = false;
        }
    }
    t = cal_od();
    if(c == n - r + 1) {
        if(t != has) {
            ok = false;
        }
    } else {
        if(t != none) {
            ok = false;
        }
    }
    if(n == 1) {
        ok = true;
        none = 1;
        has = 0;
    }
    if(none - has <= 0) ok = false;
    if(!ok) {
        printf("-1\n");
    } else {
        printf("%lld\n", none - has);
    }
    return 0;
}

