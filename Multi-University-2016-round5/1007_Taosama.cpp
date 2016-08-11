//
//  Created by TaoSama on 2016-08-02
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
LL l, r, f[4][20][N];
int k;

int sta[5];
const int ten[] = {1, 10, 100, 1000, 10000, 100000};
int get(int x, int i) {
    return x / ten[i] % 10;
}

int add(int x, int y) {
    if(!x) {
        int ret = 0;
        for(int i = 0; i < k - 1; ++i)
            ret = ret * 10 + y;
        return ret;
    }
    return (x * 10 + y) % ten[k];
}

int digit[20];

LL dfs(int i, int pre, bool first, bool e) {
    if(!i) return 1;
    if(!e && ~f[k-2][i][pre]) return f[k-2][i][pre];
    LL ret = 0;
    int to = e ? digit[i] : 9;
    for(int d = 0; d <= to; ++d) {
        bool ok = true;
        if(!first) {
            for(int j = 0; j < k - 1; ++j) {
                if(get(pre, j) == d) {
                    ok = false;
                    break;
                }
            }
        }
        if(!ok) continue;
        ret += dfs(i - 1, first && !d ? 0 : add(pre, d),
                   first && !d, e && d == to);
    }
    return e ? ret : f[k-2][i][pre] = ret;
}


LL calc(LL x) {
    int cnt = 0;
    for(; x; x /= 10) digit[++cnt] = x % 10;
    return dfs(cnt, 0, 1, 1);
}


int main() {
#ifdef LOCAL
//    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    memset(f, -1, sizeof f);
    while(scanf("%lld%lld%d", &l, &r, &k) == 3) {
        LL ans = calc(r) - calc(l - 1);
        printf("%lld\n", ans);
    }

    return 0;
}
