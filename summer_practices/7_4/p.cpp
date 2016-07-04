#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
#define pr(x) cout << #x << " = " << x << " " 
#define prln(x) cout << #x << " = " << x << endl
typedef pair<int, int> pii;
typedef long long ll;

struct Point {
    ll x, y;
    Point() {}
    Point(ll x, ll y):x(x), y(y) {}
    bool operator < (const Point &b) const {
        return x < b.x;
    }
    Point operator - (const Point &b) const {
        return Point(x - b.x, y - b.y);
    }
};
typedef Point vec;

ll cross_product(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

struct Line {
    Point s, t;
    Line() {}
    Line(Point s, Point t):s(s), t(t) {}
    bool operator < (const Line &b) const {
        return s < b.s;
    }
    vec get_vec() {
        return t - s;
    }
};

const int maxn = 1000 + 5;
Line ls[maxn];
int n, m, X1, Y1, X2, Y2, cntls;

bool judge(Line a, Line b) {
    return cross_product(a.get_vec(), b.get_vec()) > 0;
}

int get_id(int x, int y) {
    int l = 0, r = cntls - 1;
    while(l < r - 1) {
        int m = (l + r) >> 1;
        if(!judge(ls[m], Line(ls[m].s, Point(x, y)))) {
            l = m;
        } else {
            r = m;
        }
    }
    return r;
}

int res[maxn];
int cnt[maxn];
int main() {
#ifdef LOCAL
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", 'w', stdout);
#endif
    while(scanf("%d%d", &n, &m) == 2 && n) {
        scanf("%d%d%d%d", &X1, &Y1, &X2, &Y2);
        cntls = 0;
        ls[cntls++] = Line(Point(X1, Y2), Point(X1, Y1));
        ls[cntls++] = Line(Point(X2, Y2), Point(X2, Y1));
        for (int i = 0; i < n; i++) {
            int u, l;
            scanf("%d%d", &u, &l);
            ls[cntls++] = Line(Point(l, Y2), Point(u, Y1));
        }
        sort(ls, ls + cntls);
        memset(cnt, 0, sizeof(cnt));
        memset(res, 0, sizeof(res));
        for (int i = 0; i < m; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            int id = get_id(x, y);
            cnt[id]++;
        }

        for (int i = 0; i < cntls; i++) {
            res[cnt[i]]++;
        }
        
        printf("Box\n");
        for (int i = 1; i <= m; i++) {
            if(res[i] > 0) {
                printf("%d: %d\n", i, res[i]);
            }
        }
    }

	return 0;
}
