#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
const int maxn = 100000 + 5;
const int maxm = 5000 + 5;
int res[maxn];
pii row[maxm], column[maxm];
struct node {
     int op, rc, a, pos;
}ops[2*maxm];

bool cmp(const node &a, const node &b) {
     return a.pos < b.pos;
}

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < k; i++) {
        int op, rc, a;
        scanf("%d%d%d", &op, &rc, &a);
        rc--;
        if(op == 1) {
             row[rc].first = i;
             row[rc].second = a;
        } else {
             column[rc].first = i;
             column[rc].second = a;
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(row[i].second > 0) {
            ops[cnt++] = (node) {1, i, row[i].second, row[i].first};
        }
    }
    for(int i = 0; i < m; i++) {
        if(column[i].second > 0) {
            ops[cnt++] = (node) {2, i, column[i].second, column[i].first};
        }
    }
    sort(ops, ops + cnt, cmp);
    for(int i = 0; i < cnt; i++) {
        if(ops[i].op == 1) {
            for(int j = 0; j < m; j++) {
                res[ops[i].rc * m + j] = ops[i].a;
            }
        } else {
            for(int j = 0; j < n; j++) {
                res[j * m + ops[i].rc] = ops[i].a;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d%c", res[i * m + j], j == m - 1 ?  '\n' : ' ');
        }
    }
    return 0;
}
