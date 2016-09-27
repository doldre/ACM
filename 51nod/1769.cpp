#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int MAXN = 5e5 + 5;
const int MAXM = 1e6 + 5;
ll g[MAXN], f[MAXN], h[MAXN];
ll inv[MAXN];
bool is_prime[MAXN];
int n;
ll k;
char str[MAXM];
void init() {
    inv[1] = 1;
    for (int i = 2; i <= 10000; i++) {
        inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    }
}
void cal_g() {
    memset(is_prime, true, sizeof(is_prime));
    for (int i = 1; i <= n; i++) g[i] = 1;
    for (int i = 2; i <= n; i++) {
        if(is_prime[i]) {
            for (int j = i; j <= n; j += i) {
                is_prime[j] = false;
                ll t = 1;
                int c = 1;
                int x = j;
                while(x % i == 0) {
                    t = (t * (k + c - 1) % MOD * inv[c]) % MOD;
                    c++;
                    x /= i;
                }
                g[j] = (g[j] * t) % MOD;
            }
        }
    }
    for (int i = 1; i <= n; i++) h[i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            h[j] = (h[j] + f[i] * g[j / i]) % MOD;
        }
    }
}

int main() {
    init();
    scanf("%d", &n);
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        k = (k * 10 + str[i] - '0') % MOD;
    }
    for (int i = 1; i <= n; i++) scanf("%lld", &f[i]);
    cal_g();
    for (int i = 1; i <= n; i++) {
        printf("%lld ", g[i]);
    }
    puts("");
    for (int i = 1; i <= n; i++) {
        printf("%lld ", h[i]);
    }
    return 0;    
}
