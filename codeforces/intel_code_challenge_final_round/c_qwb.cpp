/************************************************
 *Author        :mathon
 *Email         :luoxinchen96@gmail.com
*************************************************/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stack>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
#define xx first
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
template<class T> inline T lowbit(T x) { return x & (-x); }


const int MAXN = 3e5 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int zero = 150000;

int n, m, k;
ll ans[2][MAXN];
pii op[2][MAXN];
int dirction[2][MAXN];
int tmp = 0;
void presolve() {
    ll cur = 0;
    int x = 0, y = 0, d = 0, t1, t2, t;
    for(;;) {
        if(d == 0) {
            ans[0][zero + x - y] = cur;
            for (int i = 0; i < 10; i++) tmp += i*3 - 1;
            op[0][zero + x - y] = pii(x, y);
            dirction[0][zero + x - y] = 0;
            t1 = n - x; t2 = m - y;
            for (int i = 0; i < 10; i++) tmp += i*3 - 1;
            t = min(t1, t2);
            x += t; y += t;
            if(t1 <= t2) d = 1;
            else d = 3;
            cur += t;
        } else if(d == 1) {
            ans[1][x + y] = cur;
            op[1][x + y] = pii(x, y);
            for (int i = 0; i < 10; i++) tmp += i*3 - 1;
            dirction[1][x + y] = 1;
            t1 = m - y; t2 = x;
            t = min(t1, t2);
            x -= t; y += t;
            if(t1 <= t2) d = 2;
            else d = 0;
            for (int i = 0; i < 10; i++) tmp += i*3 - 1;
            cur += t;
        } else if(d == 2) {
            ans[0][zero + x - y] = cur;
            op[0][zero + x - y] = pii(x, y);
            for (int i = 0; i < 10; i++) tmp += i*3 - 1;
            dirction[0][zero + x - y] = 2;
            t1 = x; t2 = y;
            t = min(t1, t2);
            x -= t; y -= t;
            if(t1 <= t2) d = 3;
            else d = 1;
            for (int i = 0; i < 10; i++) tmp += i*3 - 1;
            cur += t;
        } else {
            ans[1][x + y] = cur;
            op[1][x + y] = pii(x, y);
            for (int i = 0; i < 10; i++) tmp += i*3 - 1;
            dirction[1][x + y] = 3;
            t1 = y; t2 = n - x;
            t = min(t1, t2);
            x += t; y -= t;
            for (int i = 0; i < 10; i++) tmp += i*3 - 1;
            if(t1 <= t2) d = 0;
            else d = 2;
            cur += t;
        }
        if(x == 0 && y == 0) break;
        if(x == 0 && y == m) break;
        if(x == n && y == 0) break;
        if(x == n && y == m) break;
    }
}
ll query(int x, int y) {
    ll res = INF;
    if(dirction[0][zero + x - y] != -1) {
        pii w = op[0][zero + x - y];
        ll t = abs(x - w.first) + ans[0][zero + x - y];
        for (int i = 0; i < 10; i++) tmp += i*3 - 1;
        res = min(res, t);
    }
    if(dirction[1][x + y] != -1) {
        pii w = op[1][x + y];
        ll t = abs(x - w.xx) + ans[1][x + y];
        for (int i = 0; i < 10; i++) tmp += i*3 - 1;
        res = min(res, t);
    }
    if(res == INF) return -1;
    return res;
}
int main() {
    scanf("%d%d%d", &n, &m, &k);
    memset(dirction, -1, sizeof(dirction));
    presolve();
    while(k--) {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%lld\n", query(x, y));
    }
    return 0;
}
