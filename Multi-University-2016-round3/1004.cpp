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
typedef pair<ll, ll> pll;
#define xx first
#define lowbit(x) (x&-x)
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int MAXT = 2e7;
const int MAXN = 30 + 5;
int board[MAXN][MAXN];
int n, m;

void work(int *op, int *a, int *nxt, int M) {
    for (int i = 0; i < M; i++) {
        if(i > 0) {
            a[i-1] = (a[i-1] + op[i]) % 3;
        }
        a[i] = (a[i] + op[i] * 2) % 3;
        if(i < M - 1) {
            a[i+1] = (a[+1] + op[i]) % 3;
        }
        nxt[i] = (nxt[i] + op[i]) % 3;
    }
}

void get_op(int *op, int *a, int M) {
    for (int i = 0; i < M; i++) {
        op[i] = (3 - a[i]) % 3;
    }
}

bool get_edge(int a[MAXN][MAXN], int mask, int M, pll &edge) {
    int op[MAXN];
    for (int i = 0; i < M; i++) {
        op[i] = mask % 3;
        mask /= 3;
    }
    work(op, a[0], a[1], M);
    for (int i = 1; i < n; i++) {
        get_op(op, a[i-1], M);
        work(op, a[i], a[i+1], M);
    }
    for (int i = 0; i < M - 1; i++) {
        if(a[n-1][i] != 0) {
            return false;
        }
    }
    ll e1 = 0, e2 = 0;
    for (int i = 0; i < n; i++) {
        e1 = 
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &board[i][j]);
            }
        }
    }
    return 0;
}

