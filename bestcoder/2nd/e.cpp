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
#define lowbit(x) (x&-x)
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn = 1e5 + 5;
struct SegT {
    int cover[maxn<<2], sum[maxn<<2];

    void push_up(int rt, int size) {
        if(cover[rt] > 0) {
            sum[rt] = size;
        } else if(size == 1) {
            sum[rt] = 0;
        } else {
            sum[rt] = sum[rt<<1] + sum[rt<<1|1];
        }
    }

    void build(int l, int r, int rt) {
        cover[rt] = sum[rt] = 0;
        if(l == r) return;
        int m = (l + r) >> 1;
        build(lson);
        build(rson);
    }

    void update(int L, int R, int flag, int l, int r, int rt) {
        if(L <= l && r <= R) {
            cover[rt] += flag;
            push_up(rt, r - l + 1);
            return;
        }
        int m = (l + r) >> 1;
        if(L <= m) update(L, R, flag, lson);
        if(m < R) update(L, R, flag, rson);
        push_up(rt, r - l + 1);
    }
}seg;

map<int, vector<int> > mp;
vector<pair<int, pii> > buf[maxn];
int n, x;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &x);
        mp.clear();
        for (int i = 1; i <= n; i++) {
            int t; scanf("%d", &t);
            mp[t].push_back(i);
        }
        for (int i = 0; i <= n; i++) buf[i].clear();
        map<int, vector<int> >::iterator it;
        for (it = mp.begin(); it != mp.end(); it++) {
            vector<int> &v = it->second;
            int len = v.size();
            int last = 0;
            for (int i = 0; i < len; i++) {
                if(i + x - 1 >= len) break;
                int l1 = last + 1;
                int r1 = v[i];
                last = v[i];
                int l2 = v[i+x-1];
                int r2 = i + x >= len ? n : v[i+x] - 1;
                // prln(it->first);
                // pr(l1); pr(r1); pr(l2); prln(r2);
                buf[l1].push_back(make_pair(1, pii(l2, r2)));
                buf[r1+1].push_back(make_pair(-1, pii(l2, r2)));
            }
        }
        seg.build(1, n, 1);
        ll res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < (int)buf[i].size(); j++) {
                int flag = buf[i][j].xx, l = buf[i][j].yy.xx, r = buf[i][j].yy.yy;
                seg.update(l, r, flag, 1, n, 1);
            }
            // prln(seg.sum[1]);
            res += seg.sum[1];
        }
        printf("%lld\n", res);
    }
    return 0;
}

