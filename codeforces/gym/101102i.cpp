#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 2e5 + 5;
int X[MAXN], Y[MAXN], cntx, cnty;
int r, c;

int solve(int a[], int n, int limit) {
    int res = 0;
    int mi = 0, ma = 0, pos = 0;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        pos += a[i];
        if(flag) {
            if(pos >= limit) {
                res++;
                pos = limit - 1;
            } else if(pos < 0) {
                res++;
                pos = 0;
            }
        } else {
            mi = min(mi, pos);
            ma = max(ma, pos);
            if(ma - mi + 1 >= limit) {
                flag = true;
                res += ma - mi + 1 > limit;
                if(pos == mi) {
                    pos = 0;
                } else pos = limit - 1;
            }
        }
    }
    return res;
}

char str[MAXN];
int main() {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &r, &c);
        scanf("%s", str);
        cntx = 0, cnty = 0;
        int len = strlen(str);
        for (int i = 0; i < len; i++) {
            if(str[i] == '>') X[cntx++] = 1;
            else if(str[i] == '<') X[cntx++] = -1;
            else if(str[i] == '^') Y[cnty++] = -1;
            else if(str[i] == 'v') Y[cnty++] = 1;
        }
        int ans = solve(X, cntx, c) + solve(Y, cnty, r);
        printf("%d\n", ans);
    }
}
