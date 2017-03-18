#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
int A[MAXN];
int L[MAXN], R[MAXN];
ll sum[MAXN];
int w;
ll n;
bool check(ll h) {
    memset(L, 0, sizeof(L));
    memset(R, 0x3f, sizeof(R));
    for (int i = 1; i <= w; i++) {
        if(A[i] >= h) return true;
        int t1 = i + h - A[i];
        int t2 = i - (h - A[i]);
        if(t1 <= w) L[t1] = max(L[t1], i);
        if(t2 >= 1) R[t2] = min(R[t2], i);
    }
    for (int i = 1; i <= w; i++) L[i] = max(L[i], L[i - 1]);
    for (int i = w; i >= 1; i--) R[i] = min(R[i], R[i + 1]);
    for (int i = 1; i <= w; i++) {
        if(L[i] == 0 || R[i] == INF) continue;
        ll tmp = (ll)(h + h - (i - L[i] - 1)) * (i - L[i]) / 2;
        tmp += (R[i] - i - 1) * (h - 1 + (h - (R[i] - i - 1))) / 2;
        tmp -= sum[R[i]-1] - sum[L[i]];
        if(tmp <= n) return true;
    }
    return false;
}

int main() {
    freopen("landscape.in", "r", stdin);
    freopen("landscape.out", "w", stdout);
    scanf("%d%lld", &w, &n);
    for (int i = 1; i <= w; i++) {
        scanf("%d", &A[i]);
        sum[i] = sum[i-1] + A[i];
    }
    ll l = 0, r = 1e9 + 1e5 + 1;
    while(l < r - 1) {
        ll m = (l + r) >> 1;
        if(check(m)) {
            l = m;
        } else r = m;
    }
    cout << l << endl;
    return 0;
}
