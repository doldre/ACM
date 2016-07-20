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
const int maxn = 200 + 10;
struct Matrix {
    ll a[maxn][maxn];
    int n, m;
    Matrix() {
        n = m = 0;
        memset(a, -1, sizeof(a));
    }
    
    Matrix(int n, int m): n(n), m(m) {
        memset(a, -1, sizeof(a));
    }

    inline void I() {
        for (int i = 0; i < n; i++) a[i][i] = 0;
    }
    inline Matrix operator * (const Matrix &x) {
        Matrix res(n, x.m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < x.m; j++) {
                for (int k = 0; k < m; k++) {
                    if(a[i][k] != -1 && x.a[k][j] != -1) {
                        res.a[i][j] = max(res.a[i][j], a[i][k] + x.a[k][j]);
                    }
                }
            }
        }
        return res;
    }
    void debug() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf("%lld ", a[i][j]);
            }
            puts("");
        }
    }
};

inline Matrix mat_pow(Matrix a, ll b) {
    Matrix c(a.n, a.m);
    c.I();
    while(b) {
        if(b & 1) {
            c = c * a;
        }
        a = a * a;
        b >>= 1;
    }
    return c;
}

char str[maxn][maxn];
ll n, l, A[maxn];
const int AC_SIGMA = 26, AC_N = 210;
struct AC_automaton {
    int next[AC_N][AC_SIGMA], fail[AC_N];
    ll end[AC_N];
    int root, L;
    int newnode() {
        for (int i = 0; i < AC_SIGMA; i++) {
            next[L][i] = -1;
        }
        end[L] = 0;
        return L++;
    }

    void init() {
        L = 0;
        root = newnode();
    }

    void insert(char buf[], int v) {
        int len = strlen(buf);
        int now = root;
        for (int i = 0; i < len; i++) {
            if(next[now][buf[i] - 'a'] == -1) {
                next[now][buf[i] - 'a'] = newnode();
            }
            now = next[now][buf[i] - 'a'];
        }
        end[now] += v;
    }

    void build() {
        queue<int> Q;
        fail[root] = root;
        for (int i = 0; i < AC_SIGMA; i++) {
            if(next[root][i] == -1) {
                next[root][i] = root;
            } else {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        }
        while(!Q.empty()) {
            int now = Q.front();
            if(fail[now] != root) {
                end[now] += end[fail[now]];
            }
            Q.pop();
            for (int i = 0; i < 26; i++) {
                if(next[now][i] == -1) {
                    next[now][i] = next[fail[now]][i];
                } else {
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
            }
        }
    }
}ac;


int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%lld%lld", &n, &l);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &A[i]);
    }
    ac.init();
    for (int i = 1; i <= n; i++) {
        scanf("%s", str[i]);
        ac.insert(str[i], A[i]);
    }
    ac.build();
    Matrix dp(ac.L, ac.L);
    for (int i = 0; i < ac.L; i++) {
        for (int j = 0; j < 26; j++) {
            dp.a[ac.next[i][j]][i] = max(dp.a[ac.next[i][j]][i], 
                    ac.end[ac.next[i][j]]);
        }
    }
    // dp.debug();
    Matrix ans(ac.L, 1);
    ans.a[0][0] = 0;
    dp = mat_pow(dp, l);
    ans = dp * ans;
    ll res = 0;
    for (int i = 0; i < ac.L; i++) {
        res = max(res, ans.a[i][0]);
    }
    cout << res << endl;
    return 0;
}

