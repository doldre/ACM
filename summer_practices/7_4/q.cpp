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
const int maxn = 300 + 5;
const double eps = 1e-9;

int sgn(double x) {
    if(x > eps) return 1;
    else if(x < -eps) return -1;
    else return 0;
}

struct Point {
    double x, y;
    Point() {}
    Point(double x, double y):x(x), y(y) {}
    void read() {
        scanf("%lf%lf", &x, &y);
    }
    double det(const Point &b) const {
        return x * b.y - y * b.x;
    }
    double dot(const Point &b) const {
        return x * b.x + y * b.y;
    }

    Point operator - (const Point &b) const {
        return Point(x - b.x, y - b.y);
    }
}ps[maxn];

struct Line {
    Point s, t;
    Line(Point s, Point t): s(s), t(t) {}
    Line() {}
    void read() {
        s.read(); t.read();
    }
}ls[maxn];


bool strict_cross(Line a, Line b) {
    return sgn((b.t - b.s).det(a.s - b.s)) * sgn((b.t - b.s).det(a.t - b.s)) < 0 &&
        sgn((a.t - a.s).det(b.s - a.s)) * sgn((a.t - a.s).det(b.t - a.s)) < 0;
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    Point X;
    int cntps = 0;
    ps[cntps++] = Point(0, 0);
    // ps[cntps++] = Point(0, 100);
    // ps[cntps++] = Point(100, 0);
    // ps[cntps++] = Point(100, 100);
    for (int i = 0; i < n; i++) {
        ls[i].read();
        ps[cntps++] = ls[i].s;
        ps[cntps++] = ls[i].t;
    }
    X.read();
    int ans = maxn;
    for (int i = 0; i < cntps; i++) {
        Line l(X, ps[i]);
        int t = 1;
        for (int j = 0; j < n; j++) {
            if(strict_cross(l, ls[j])) {
                t++;
            }
        }
        ans = min(ans,  t);
    }
    printf("Number of doors = %d\n", ans);
    return 0;
}

