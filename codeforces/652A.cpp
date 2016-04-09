#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <map>
using namespace std;
typedef long long ll;
const int maxn = 300000 + 5;
int A[maxn];
int flag[maxn];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        A[x] = i;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        int p1 = A[a], p2 = A[b];
        flag[max(p1, p2)] = max(flag[max(p1, p2)], min(p1, p2));
    }
    ll ans = 0;
    int l = 0;
    for (int r = 1; r <= n; r++) {
         l = max(l, flag[r]);
         ans += (r - l);
    }
    printf("%I64d\n", ans);
    return 0;
}
