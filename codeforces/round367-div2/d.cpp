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

const int MAXN = 2e5 * 60;
struct Trie {
    int nxt[MAXN][2];
    int tot;
    int cnt[MAXN];
    int root;
    void init() {
        tot = 0;
        root = 0;
        nxt[root][0] = nxt[root][1] = -1;
        cnt[root] = 0;
    }
    int newnode() {
        ++tot;
        nxt[tot][0] = nxt[tot][1] = -1;
        cnt[tot] = 0;
        return tot;
    }
    void add(int x) {
        int p = 0;
        for (int i = 30; i >= 0; i--) {
            int t = (x >> i) & 1;
            if(nxt[p][t] == -1) {
                nxt[p][t] = newnode();
            }
            p = nxt[p][t];
            cnt[p]++;
        }
    }
    void del(int x) {
        int p = 0;
        for (int i = 30; i >= 0; i--) {
            int t = (x >> i) & 1;
            if(cnt[nxt[p][t]] == 1) {
                int tmp = nxt[p][t];
                nxt[p][t] = -1;
                p = tmp;
            } else p = nxt[p][t];
            cnt[p]--;
        }
    }
    int query(int x) {
        int res = 0;
        int p = 0;
        for (int i = 30; i >= 0; i--) {
            int t = (x >> i) & 1;
            if(nxt[p][!t] != -1) {
                res |= 1 << i;
                p = nxt[p][!t];
            } else {
                p = nxt[p][t];
            }
        }
        return res;
    }
}trie;
                
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int q;
    trie.init();
    trie.add(0);
    scanf("%d", &q);
    getchar();
    for (int i = 0; i < q; i++) {
        char op[20];
        int x;
        scanf("%s %d", op, &x);
        if(op[0] == '+') {
            trie.add(x);
        } else if(op[0] == '-') {
            trie.del(x);
        } else if(op[0] == '?') {
            int ans = trie.query(x);
            printf("%d\n", ans);
        }
    }
    return 0;
}

