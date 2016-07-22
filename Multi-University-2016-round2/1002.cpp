#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
const int mod = 1e9 + 7;
const int maxn = (1<<16) + 100;
const int maxm = (1<<8) + 100;
const int inf = 0x3f3f3f3f;
const ll inff = 0x3f3f3f3f3f3fLL;
ll ds[maxm][maxm];
int A[maxn];
char opt[20];
int OP;
int n;
ll f[maxn];

vector<int> G[maxn];

int op(int a, int b) {
    if(OP == 1) return a & b;
    else if(OP == 2) return a ^ b;
    else return a | b;
}

void dfs(int u) {
    ll ma = 0;
    int low_8 = A[u] & ((1<<8)-1);
    int high_8 = A[u] >> 8;
    for (int h = 0; h < (1<<8); h++) {
        ma = max(ma, (op(high_8, h) << 8) + ds[h][low_8]);
    }
    f[u] = ma;
    ll *buf = new ll[maxm];
    memcpy(buf, ds[high_8], sizeof(ll) * maxm);
    for (int l = 0; l < (1<<8); l++) {
        ds[high_8][l] = max(ds[high_8][l], f[u] + op(l, low_8));
    }
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        dfs(v);
    }
    memcpy(ds[high_8], buf, sizeof(ll) * maxm);
    delete[] buf;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        scanf("%s", opt);
        if(strcmp(opt, "AND") == 0) OP = 1;
        if(strcmp(opt, "XOR") == 0) OP = 2;
        if(strcmp(opt, "OR") == 0) OP = 3;

        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
        }
        for (int i = 0; i <= n; i++) {
            G[i].clear();
        }
        for (int i = 2; i <= n; i++) {
            int fa;scanf("%d", &fa);
            G[fa].push_back(i);
        }
        for (int i = 0; i < maxm; i++) {
            for (int j = 0; j < maxm; j++) {
                ds[i][j] = -inf;
            }
        }
        memset(f, 0, sizeof(f));
        dfs(1);
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
           ans = (ans + ((ll)f[i] + A[i]) * i % mod) % mod; 
        }
        printf("%lld\n", ans);
    }
    return 0;
}
