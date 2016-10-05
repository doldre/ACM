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

struct Node {
    ll absv, v, pos;
    Node () {}
    Node (ll absv, ll v, ll pos): absv(absv), v(v), pos(pos) {}
    bool operator < (const Node &b) const {
        return absv > b.absv;
    }
};
const int MAXN = 2e5 + 5;
int n, k, x;
ll ans[MAXN];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d%d", &n, &k, &x);
    int cntp = 0, cntn = 0, cnt0 = 0;;
    priority_queue<Node> que;
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        que.push(Node(abs(a), a, i));
        cntp += a > 0;
        cntn += a < 0;
        cnt0 += a == 0;
    }
    for (int i = 0; i < k; i++) {
        Node cur = que.top(); que.pop();
        if(cnt0 > 0 || cntn % 2 == 0) {
            cntp -= cur.v > 0;
            cntn -= cur.v < 0;
            cnt0 -= cur.v == 0;
            if(cur.v > 0) {
                cur.v -= x;
                cur.absv = abs(cur.v);
            } else if(cur.v == 0) {
                if(cntn % 2 == 0) {
                    cur.v -= x;
                } else {
                    cur.v += x;
                }
                cur.absv = abs(cur.v);
            } else {
                cur.v += x;
                cur.absv = abs(cur.v);
            }
            cntp -= cur.v > 0;
            cntn -= cur.v < 0;
            cnt0 -= cur.v == 0;
        } else {
            cntp -= cur.v > 0;
            cntn -= cur.v < 0;
            cnt0 -= cur.v == 0;
            if(cur.v >= 0) {
                cur.v += x;
                cur.absv = abs(cur.v);
            } else {
                cur.v -= x;
                cur.absv = abs(cur.v);
            }
            cntp -= cur.v > 0;
            cntn -= cur.v < 0;
            cnt0 -= cur.v == 0;
        }
        que.push(cur);
    }
    while(!que.empty()) {
        Node cur = que.top(); que.pop(); 
        ans[cur.pos] = cur.v;
    }
    for (int i = 0; i < n; i++) {
        printf("%lld ", ans[i]);
    }
    return 0;
}

