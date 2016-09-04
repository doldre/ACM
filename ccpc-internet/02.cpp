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
const int MAXN = 1000;
const int mod = 1e9 + 7;
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

int var, equ;
int Rank()
{
	int i, j, r, k, u;
    i = j = 0;
    while(i < equ && j < var) {
        r = i;
        for(k = i; k < equ; k++) {
            if(a[k][j]) {
                r = k;
                break;
            }
        }
        if(a[r][j]){
            if(r != i){
                for(k = 0; k <= var; k++) swap(a[i][k], a[r][k]);
            }
            for(u = i + 1; u < equ; u++){
                if(a[u][j]){
                    for(k = j; k <= var; k++){
                        a[u][k] ^= a[i][k];
                    }
                }
            }
            i++;
        }
        j++;
    }
    return i;//有界变量
}

const int maxn = 3e3 + 5;
int prime[maxn];
int cnt_prime;
bool isprime[maxn];

ll fast_pow(ll x, ll n) {
    ll ans = 1;
    while(n > 0) {
        if(n & 1) {
            ans = ans * x % mod;
        }
        x = (x * x) % mod;
        n >>= 1;
    }
    return ans;
}

void init_prime() {
    cnt_prime = 0;
    memset(isprime, true, sizeof(isprime));
    for (int i = 2; i < maxn; i++) {
        if(isprime[i]) {
            prime[cnt_prime++] = i;
            for (int j = i + i; j < maxn; j += i) {
                isprime[j] = false;
            }
        }
    }
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    init_prime();
    int T; scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        int n; scanf("%d", &n);
        memset(a, 0, sizeof(a));
        ll x;
        int maxj = 0;
        for (int i = 0; i < n; i++) {
            scanf("%lld", &x);
            for (int j = 0; j < cnt_prime; j++) {
                int cnt = 0;
                while(x % prime[j] == 0) {
                    maxj = max(maxj, j);
                    cnt++;
                    x /= prime[j];
                }
                a[j][i] = cnt % 2;
            }
        }
        maxj++;
        for (int i = 0; i < maxj; i++) {
            a[i][n] = 0;
        }
        var = n, equ = maxj;
        ll cnt_var = var - Rank();
        ll ans = (fast_pow(2, cnt_var) - 1 + mod) % mod;
        printf("Case #%d:\n%lld\n", Cas, ans);
    }
    return 0;
}

