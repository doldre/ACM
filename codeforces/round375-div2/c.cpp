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

const int MAXN = 2000 + 5;
int A[MAXN], B[MAXN];
int cnt[MAXN];
queue<int> pos[MAXN];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    queue<int> g;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        if(A[i] > m) g.push(i);
        else {
            cnt[A[i]]++;
            pos[A[i]].push(i);
        }
    }
    set<pii> st;
    int ans = 0x3f3f3f3f, num = 0;
    for (int i = 1; i <= m; i++) {
        st.insert(pii(cnt[i], i));
        ans = min(cnt[i], ans);
    }
    int tmp = 0;
    vector<pii> buf;
    while(!g.empty()) {
        int x = g.front(); g.pop();
        pii cur = *st.begin();
        st.erase(cur);
        buf.push_back(pii(x, cur.yy));
        cur.xx++;
        tmp++;
        st.insert(cur);
        if(st.begin()->xx > ans) {
            ans = st.begin()->xx;
            num = tmp;
            for (auto p: buf) {
                A[p.xx] = p.yy;
            }
            buf.clear();
        }
    }
    while(st.begin()->xx < st.rbegin()->xx - 1) {
        pii s = *st.begin(), e = *st.rbegin();
        st.erase(s); st.erase(e);
        s.xx++, e.xx--;
        int p = pos[e.yy].front(); pos[e.yy].pop();
        tmp++;
        buf.push_back(pii(p, s.yy));
        st.insert(s); st.insert(e);
        if(st.begin()->xx > ans) {
            ans = st.begin()->xx;
            num = tmp;
            for (auto pp: buf) {
                A[pp.xx] = pp.yy;
            }
            buf.clear();
        }
    }
    printf("%d %d\n", ans, num);
    for (int i = 1; i <= n; i++) {
        printf("%d ", A[i]);
    }
    return 0;
}

