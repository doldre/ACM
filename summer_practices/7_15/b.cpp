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
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
map<pll, int> board;
// 0 表示黑， 1 表示白
struct DSU {
    map<pll, pll> par; 
    map<pll, ll> cnt;

    void init() {
        par.clear();
        cnt.clear();
    }

    void erase(pll pos) {
        par.erase(par.find(pos));
        cnt.erase(cnt.find(pos));
    }

    ll get_liberty(pll pos) {
        pos = find(pos);
        return cnt[pos];
    }

    pll find(pll x) {
        if(par.find(x) == par.end()) {
            par[x] = x;
            cnt[x] = 0;
        }
        if(par[x] == x) {
            return x;
        } else {
            return par[x] = find(par[x]);
        }
    }

    void modify(pll pos, int add) {
        pos = find(pos);
        cnt[pos] += add;
    }

    void merge(pll a, pll b) {
        a = find(a), b = find(b);
        cnt[a] += cnt[b];
        par[b] = a;
    }
}dsu;

void push(pll pos, int color) {
    int x = pos.xx, y = pos.yy;
    int add = 4;
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir], ny = y + dy[dir];
        if(nx == 0 || ny == 0) add--;
        if(board.find(pll(nx, ny)) != board.end()) {
            dsu.modify(pll(nx, ny), -1);
            add--;
            if(board[pll(nx, ny)] == color) {
                dsu.merge(pos, pll(nx, ny));
            }
        }
    }
    board[pos] = color;
    dsu.modify(pos, add);
}

void dfs(pll pos, int color) {
    board.erase(board.find(pos));
    dsu.erase(pos);
    int x = pos.xx, y = pos.yy;
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir], ny = y + dy[dir];
        if(board.find(pll(nx, ny)) != board.end()) {
            if(board[pll(nx, ny)] == color) {
                dfs(pll(nx, ny), color);
            } else {
                dsu.modify(pll(nx, ny), 1);
            }
        }
    }
}

void check(pll pos, int color) {
    int x = pos.xx, y = pos.yy;
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir], ny = y + dy[dir];
        if(board.find(pll(nx, ny)) != board.end()) {
            if(board[pll(nx, ny)] != color && 
                    dsu.get_liberty(pll(nx, ny)) == 0) {
                dfs(pll(nx, ny), board[pll(nx, ny)]);
            }
        }
    }
    if(dsu.get_liberty(pos) == 0) {
        dfs(pos, color);
    }
}

int main(void) {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        int n; scanf("%d", &n);
        board.clear();
        dsu.init();
        for (int i = 0; i < n; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            int color = i % 2;
            push(pll(x, y), color);
            check(pll(x, y), color);
        } 
        map<pll, int>::iterator it;
        int cnt_b = 0, cnt_w = 0;
        for (it = board.begin(); it != board.end(); it++) {
            // printf("%lld %lld: %d\n", it->xx.xx, it->xx.yy, it->yy);
            // printf("%lld\n", dsu.get_liberty(it->xx));
            if(it->yy == 0) cnt_b++;
            else cnt_w++;
        }
        printf("%d %d\n", cnt_b, cnt_w);
    }
    return 0;
}

