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

const int MAXN = 2e5 + 5;
struct DSU {
    int par[MAXN];
    void init(int n) {
        for (int i = 0; i <= n; i++) par[i] = i;
    }
    bool is_same(int a, int b) {
        a = find(a); b = find(b);
        return a == b;
    }
    int find(int x) {
        return x == par[x] ? x : par[x] = find(par[x]);
    }
    void merge(int a, int b) {
        a = find(a), b = find(b);
        par[a] = par[b];
    }
}dsu;

vector<pii> es;
queue<pii> none, rs, rt, st;
int n, m;
int s, t, ds, dt;

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        es.push_back(pii(a, b));
    }
    scanf("%d%d%d%d", &s, &t, &ds, &dt);
    for (int i = 0; i < m; i++) {
        if((es[i].xx == s && es[i].yy == t) ||
           (es[i].xx == t && es[i].yy == s)) {
            st.push(es[i]);
        } else if(es[i].xx == s || es[i].yy == s) {
            rs.push(es[i]);
        } else if(es[i].xx == t || es[i].yy == t) {
            rt.push(es[i]);
        } else none.push(es[i]);
    }
    dsu.init(n);
    vector<pii> ans;
    int cnt = 0;
    while(!none.empty()) {
        pii p = none.front(); none.pop();
        if(!dsu.is_same(p.xx, p.yy)) {
            dsu.merge(p.xx, p.yy);
            ans.push_back(p);
            cnt++;
        }
    }
    while(cnt < n - 1 && (ds > 0 || dt > 0) && (!rs.empty() || !rt.empty())) {
        pii p;
        if((ds > dt && !rs.empty()) || rt.empty()) {
            p = rs.front(); rs.pop();
            if(!dsu.is_same(p.xx, p.yy) && ds > 0) {
                dsu.merge(p.xx, p.yy);
                ans.push_back(p);
                ds--;
                cnt++;
            }
        } else {
            p = rt.front(); rt.pop();
            if(!dsu.is_same(p.xx, p.yy) && dt > 0) {
                dsu.merge(p.xx, p.yy);
                ans.push_back(p);
                dt--;
                cnt++;
            }
        }
    }
    while(cnt < n - 1 && !st.empty() && ds > 0 && dt > 0) {
        pii p = st.front(); st.pop();
        if(!dsu.is_same(p.xx, p.yy)) {
            dsu.merge(p.xx, p.yy);
            ans.push_back(p);
            ds--; dt--;
            cnt++;
        }
    }
    if(cnt == n - 1) {
        puts("Yes");
        for (auto x: ans) {
            printf("%d %d\n", x.xx, x.yy);
        }
    } else puts("No");
    return 0;
}

