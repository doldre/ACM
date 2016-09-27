typedef long long ll;
const ll MOD = 7;
const int MAXN = 400;
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

