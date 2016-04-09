#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;
#define N 1000005
struct data{int x, y, v;} a[N];
int Row[N], Column[N], R[N], C[N], row[N], column[N];
int num[N], f[N], ans[N], id, n, m, k, Case;
int cmp(const data &a, const data &b) {
     return a.v < b.v;
}

inline int ID(int x, int y) {
     return (x - 1) * m + y;
}

int get(int u) {
     return f[u] == u ? u : f[u] = get(f[u]);
}

void solve(int s, int t) {
     ++Case;
     for (int i = s; i <= t; i++) {
         f[i] = i, num[i] = 0;
     }
     for(int i = s; i <= t; i++) {
         if(Row[a[i].x] != Case) {
             R[a[i].x] = Case, R[a[i].x] = i;
         } else {
              f[get(i)] = get(R[a[i].x]);
         }
         if(Column[a[i].y] != Case) {
              Column[a[i].y] = Case, C[a[i].y] = i;
         } else {
             f[get(i)] = get(C[a[i].y]);
         }
     }

     for (int i = s; i <= t; i++) {
          num[get(i)] = max(num[get(i)], max(row[a[i].x], column[a[i].y]));
     }
     for (int i = s; i <= t; i++) {
          if (get(i) == i) num[i]++;
     }
     for (int i = s; i <= t; i++) {
          ans[ID(a[i].x, a[i].y)] = num[get(i)];
          row[a[i].x] = max(row[a[i].x], num[get(i)]);
          column[a[i].y] = max(column[a[i].y], num[get(i)]);
     }
}

int main() {
     scanf("%d%d", &n, &m);
     for (int i = 1; i <= n; i++) {
         for(int j = 1; j <= m; j++) {
              id = ID(i, j);
              scanf("%d", &a[id].v);
              a[id].x = i, a[id].y = j;
         }
     }
     sort(a + 1, a + m * n + 1, cmp);
     k = 1;
     for (int i = 2; i <= n*m + 1; i++) {
         if (i == n * m + 1 || a[i].v != a[k].v) {
             solve(k, i - 1), k = i;
         }
     }

     for (int i = 1; i <= n; i++) {
         for(int j = 1; j <= m; j++) {
             printf("%d%c", ans[ID(i, j)], j < m ? ' ' : '\n');
         }
     }
     return 0;
}

