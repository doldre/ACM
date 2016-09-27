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
const int MAXN = 1e3 + 5;
struct Stu {
    int score, sign;
    vector<int> chose;
    int cur;
    bool operator < (const Stu &b) const {
        if(cur != b.cur) return cur > b.cur;
        else return sign > b.sign;
    }
};

vector<Stu> S[105];
int n, m;
int V[MAXN];
int ans[MAXN];

void solve(vector<Stu> &A) {
    priority_queue<Stu> que;
    for (auto stu: A) {
        stu.cur = 0;
        que.push(stu);
    }
    while(!que.empty()) {
        Stu stu = que.top(); que.pop();
        if(V[stu.chose[stu.cur]] > 0) {
            V[stu.chose[stu.cur]]--;
            ans[stu.sign] = stu.chose[stu.cur];
        } else if(stu.cur < (int)stu.chose.size() - 1) {
            stu.cur++;
            que.push(stu);
        }
    }
}
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &V[i]);
    }
    for (int i = 1; i <= n; i++) {
        Stu stu;
        int p; scanf("%d", &p);
        stu.score = p;
        int q; scanf("%d", &q);
        stu.sign = i;
        for (int j = 1; j <= q; j++) {
            int c; scanf("%d", &c);
            stu.chose.push_back(c);
        }
        S[p].push_back(stu);
    }
    memset(ans, -1, sizeof(ans));
    for (int i = 100; i >= 0; i--) {
        solve(S[i]);
    }
    for (int i = 1; i <= n; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}

