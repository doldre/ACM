#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXP 1000005
using namespace std;

int n, m, ans[MAXP], fa[MAXP], f[MAXP], x[MAXP], y[MAXP], cnt;
struct node {
    int num, id, x, y;
    bool operator < (const node &a) const { return num < a.num; }
}a[MAXP];

int root(int u) {
    if(fa[u] == u) return u;
    return fa[u] = root(fa[u]);
}

int main() {
     scanf("%d%d", &n, &m);
     for(int i = 1, p; i <= n; i++) {
         for(int j = 1; j <= m; j++) {
             scanf("%d", &p);
             ++cnt;
             a[cnt] = (node){p, cnt, i, j + n};
         }
     }
}
