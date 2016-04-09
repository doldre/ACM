#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
const int maxn = 200000 + 5;

int flag[2*maxn];
int ans[maxn];
int bit[2*maxn];
int n, m;
int L[maxn], R[maxn], buf[2*maxn];
int NO[maxn*2];
void add(int i, int x) {
    while(i <= m) {
        bit[i] += x;
        i += (i&-i);
    }
}

int sum(int i) {
     int res = 0;
     while(i > 0) {
         res += bit[i];
         i -= (i&-i);
     }
     return res;
}

int ID(int x) {
    return lower_bound(buf, buf + m, x) - buf + 1;
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &L[i], &R[i]);
        buf[i*2] = L[i];
        buf[i*2 + 1] = R[i];
    }
    sort(buf, buf + 2 * n);
    m = 2*n;
    for (int i = 0; i < n; i++) {
        L[i] = ID(L[i]);
        NO[L[i]] = i;
        R[i] = ID(R[i]);
        flag[L[i]] = R[i];
        add(R[i], 1);
    }

    for (int i = 1; i <= m; i++) {
        if(flag[i]) {
            int t = sum(flag[i]) - sum(i);
            ans[NO[i]] = t;
            add(flag[i], -1);
        }
    }
    for (int i = 0; i < n; i++) {
         printf("%d\n", ans[i] - 1);
    }
    return 0;
}
