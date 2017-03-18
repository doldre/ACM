const ll mod = 1e4 + 7;
int fac[mod + 7];
void init() {
    fac[0] = 1;
    for (int i = 1; i <= mod; ++i) fac[i] = (LL)fac[i - 1] * i % mod;
}
LL power(LL a, LL b) {
    LL x = a % mod, ret = 1;
    while (b) {
        if (b & 1) ret = ret * x % mod;
        x = x * x % mod;
        b >>= 1;
    }
    return ret;
}
LL C(int n, int m, int mod) {
    return m > n ? 0 : fac[n] * power((LL)fac[m] * fac[n - m], mod - 2) % mod;
}
LL Lucas(LL n, LL m, int mod) {
    return m ? (LL)C(n % mod, m % mod, mod) * Lucas(n / mod, m / mod, mod) % mod : 1;
}
