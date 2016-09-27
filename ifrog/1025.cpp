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
typedef long long LL;
const int MAXN = 150 + 5;
const int INF = 0x3f3f3f3f;
const ll MOD = 1e9 + 7;
const int MX = 150 + 5;  
const int mod = 1e9 + 7;  
  
ll a[MAXN][MAXN]; //增广矩阵
ll x[MAXN]; //解集

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

ll inv(ll a, ll mod) {
    if(a == 1) return 1;
    return inv(mod % a, mod) * (mod - mod / a) % mod;
}

int Gauss(int equ, int var) {
    int max_r, col, k;
    for (k = 0, col = 0; k < equ && col < var; k++, col++) {
        max_r = k;
        for (int i = k + 1; i < equ; i++) {
            if(abs(a[i][col]) > abs(a[max_r][col]))
                max_r = i;
        }
        if(a[max_r][col] == 0)  {
            k--;
            continue;
        }
        if(max_r != k) 
            for (int j = col; j < var + 1; j++) 
                swap(a[k][j], a[max_r][j]);
        for (int i = k + 1; i < equ; i++) {
            if(a[i][col] != 0) {
                ll LCM = lcm(abs(a[i][col]), abs(a[k][col]));
                ll ta = LCM / abs(a[i][col]);
                ll tb = LCM / abs(a[k][col]);
                if(a[i][col] * a[k][col] < 0) tb -= tb;
                for (int j = col; j < var + 1; j++) 
                    a[i][j] = ((a[i][j]*ta - a[k][j]*tb)%MOD + MOD)%MOD;
            }
        }
    }
    for (int i = k; i < equ; i++) 
        if(a[i][col] != 0)
            return -1;
    if(k < var) return var - k;
    for (int i = var - 1; i >= 0; i--) {
        ll temp = a[i][var];
        for (int j = i + 1; j < var; j++) {
            if(a[i][j] != 0) {
                temp -= a[i][j] * x[j];
                temp = (temp%MOD + MOD) % MOD;
            }
        }
        x[i] = (temp * inv(a[i][i], MOD)) % MOD;
    }
    return 0;
}

LL power(LL a, LL b) {  
    LL ret = 1;  
    while(b) {  
        if(b & 1) ret = ret * a % mod;  
        a = a * a % mod;  
        b >>= 1;  
    }  
    return ret;  
}  
typedef LL Matrix[MX][MX];  
void gauss(Matrix A, int n) {  
    int i, j, k, r;  
    for(i = 0; i < n; i++) {  
        r = i;  
        for(j = i + 1; j < n; j++) {  
            if(abs(A[j][i]) > abs(A[r][i])) r = j;  
        }  
        if(r != i) for(j = 0; j <= n; j++) swap(A[r][j], A[i][j]);  
  
        for(k = i + 1; k < n; k++) {  
            LL f = A[k][i] * power(A[i][i], mod - 2) % mod;  
            for(j = i; j <= n; j++) A[k][j] = (A[k][j] - f * A[i][j]) % mod;  
        }  
    }  
  
    for(i = n - 1; i >= 0; i--) {  
        for(j = i + 1; j < n; j++) {      
            A[i][n] = (A[i][n] - A[j][n] * A[i][j]) % mod;  
        }  
        A[i][n] = A[i][n] * power(A[i][i], mod - 2) % mod;  
    }  
}  
// inline ll gcd(ll a, ll b) {
    // return b == 0 ? a : gcd(b, a % b);
// }

// inline ll lcm(ll a, ll b) {
    // return a / gcd(a, b) * b;
// }


ll inv26 = inv(26, MOD);

const int AC_SIGMA = 26, AC_N = 200;
struct AC_automaton {
    int next[AC_N][AC_SIGMA], fail[AC_N], end[AC_N];
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

    void insert(char buf[]) {
        int len = strlen(buf);
        int now = root;
        for (int i = 0; i < len; i++) {
            if(next[now][buf[i] - 'a'] == -1) {
                next[now][buf[i] - 'a'] = newnode();
            }
            now = next[now][buf[i] - 'a'];
        }
        end[now] ++;
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
            if(end[fail[now]]) end[now] = 1;
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

    int querry(char buf[]) {
        int len = strlen(buf);
        int now = root;
        int res = 0;
        for (int i = 0; i < len; i++) {
            now = next[now][buf[i] - 'a'];
            int temp = now;
            while(temp != root) {
                res += end[temp];
                end[temp] = 0;
                temp = fail[temp];
            }
        }
        return res;
    }
}AC;

char str[MAXN];

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        int n; scanf("%d", &n);
        AC.init();
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++) {
            scanf("%s", str);
            AC.insert(str);
        }
        AC.build();
        for (int i = 0; i < AC.L; i++) {
            if(AC.end[i]) {
                a[i][i] = 1;
                continue;
            }
            for (int j = 0; j < AC_SIGMA; j++) {
                a[i][AC.next[i][j]] += inv26;
                a[i][AC.next[i][j]] %= MOD;
            }
            a[i][i] = (a[i][i] - 1 + MOD) % MOD;
            a[i][AC.L] = (MOD - 1);
        }
        Gauss(AC.L, AC.L);
        // gauss(a, AC.L);
        // prln(flag);
        printf("Case #%d: %lld\n", Cas, (x[0] + MOD) % MOD);
    }
    return 0;
}

