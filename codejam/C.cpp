#include <cstdio>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
// 18位素数：154590409516822759
// 19位素数：2305843009213693951 (梅森素数)
// 19位素数：4384957924686954497
LL prime[6] = {2, 3, 5, 233, 331};
LL qmul(LL x, LL y, LL mod) { // 乘法防止溢出， 如果p * p不爆LL的话可以直接乘； O(1)乘法或者转化成二进制加法


    return (x * y - (long long)(x / (long double)mod * y + 1e-3) *mod + mod) % mod;
    /*
    LL ret = 0;
    while(y) {
        if(y & 1)
            ret = (ret + x) % mod;
        x = x * 2 % mod;
        y >>= 1;
    }
    return ret;
    */
}
LL qpow(LL a, LL n, LL mod) {
    LL ret = 1;
    while(n) {
        if(n & 1) ret = qmul(ret, a, mod);
        a = qmul(a, a, mod);
        n >>= 1;
    }
    return ret;
}
bool Miller_Rabin(LL p) {
    if(p < 2) return 0;
    if(p != 2 && p % 2 == 0) return 0;
    LL s = p - 1;
    while(! (s & 1)) s >>= 1;
    for(int i = 0; i < 5; ++i) {
        if(p == prime[i]) return 1;
        LL t = s, m = qpow(prime[i], s, p);
        while(t != p - 1 && m != 1 && m != p - 1) {
            m = qmul(m, m, p);
            t <<= 1;
        }
        if(m != p - 1 && !(t & 1)) return 0;
    }
    return 1;
}
typedef long long ll;
const int maxn = 500;
int T = 1;
int N = 16, J = 50;
char str[maxn];

ll interpre(char s[], int base) {
    ll res = 0;
    for (int i = N - 1; i >= 0; i--) {
        res = res * base + s[i];
    }
    return res;
}

ll solve(ll x) {
    for (ll i = 2; i <= 10; i++) {
        if(x % i == 0) return i;
    }
    return -1;
}
ll ans[maxn];
vector<ll> ansv[maxn];
int main() {
    freopen("C-small.txt", "w", stdout);
    str[0] = str[N-1] = 1;
    int cnt = 0;
    for (int i = 0; i < (1<<(N-2)); i++) {

        for (int j = 1; j <= (N-2); j++) {
            str[j] = (i>>(j-1)) & 1;
        }
        vector<ll> buf;
        ll x;
        bool ok = true;
        for (int base = 2; base <= 10; base++) {
            x = interpre(str, base);
            if(Miller_Rabin(x)) {
                ok = false;
                break;
            }
            ll t = solve(x);
            if(t != -1) buf.push_back(t);
            else break;
        }

        if(buf.size() == 9) {
            ans[cnt] = x;
            ansv[cnt] = buf;
            cnt++;
            if(cnt == J) break;
        }
    }
    printf("Case #1:\n");
    for (int i = 0; i < J; i++) {
        cout << ans[i];
        for (ll x: ansv[i]) cout << " " << x;
        printf("\n");
    }
}
