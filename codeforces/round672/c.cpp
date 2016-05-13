
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
#define sa(n) scanf("%d", &(n))
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl


const double eps = 1e-9;

int sign(double x) {
    if(x > eps) return 1;
    else if(x < -eps) return -1;
    else return 0;
}

struct Point {
    double x, y;
    Point() {}
    Point (double x, double y):x(x), y(y) {}
    Point operator - (const Point &b) const {
        return Point(x - b.x, y - b.y);
    }
    double det(const Point &b) const {
        return x * b.y - y * b.x;
    }
    double dot(const Point &b) const {
        return x * b.x + y * b.y;
    }
};

struct Line {
    Point s, e;
    Line() {}
    Line(Point s, Point e):s(s), e(e) {}
};

bool StrictCross(Line a, Line b) {
    return sign((a.s - b.s).det(b.e - b.s)) * sign((a.e - b.s).det(b.e - b.s)) < 0 &&
        sign((b.s - a.s).det(a.e - a.s)) * sign((b.e - a.s).det(a.e - a.s)) < 0;
}

bool LineCross(Line a, Line b) {
    return max(a.s.x, a.e.x) >= min(b.s.x, b.e.x) &&
           max(b.s.x, b.e.x) >= min(a.s.x, a.e.x) &&
           max(a.s.y, a.e.y) >= min(b.s.y, b.e.y) &&
           max(b.s.y, b.e.y) >= min(a.s.y, a.e.y) &&
           sign((a.s - b.s).det(b.e - b.s)) * sign((a.e - b.s).det(b.e - b.s)) <= 0 &&
           sign((b.s - a.s).det(a.e - a.s)) * sign((b.e - a.s).det(a.e - a.s)) <= 0;
}

double dist(Point a, Point b) {
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

const int maxn = 1e5 + 5;
Point ps[maxn];

int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n;
    Point a, b, t;
    scanf("%lf%lf%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y, &t.x, &t.y);
    sa(n);
    for (int i = 0; i < n; i++) {
        scanf("%lf%lf", &ps[i].x, &ps[i].y);
    }
    double res = 0;
    for (int i = 0; i < n; i++) {
        res += dist(ps[i], t) * 2;
    }
    int s1 = 0, s2 = 0;
    double t1 = 1e15;
    for (int i = 0; i < n; i++) {
        if(dist(ps[i], a) - dist(ps[i], t) < t1) {
            t1 = dist(ps[i], a) - dist(ps[i], t);
            s1 = i;
        }
    }
    double t2 = 0;
    for (int i = 0; i < n; i++) {
        if(dist(ps[i], b) - dist(ps[i], t) < t2 && i != s1) {
            t2 = dist(ps[i], b) - dist(ps[i], t);
            s2 = i;
        }
    }
    int ss1 = 0, ss2 = 0;
    double tt1 = 0, tt2 = 1e15;
    for (int i = 0; i < n; i++) {
        if(dist(ps[i], b) - dist(ps[i], t) < tt2) {
            tt2 = dist(ps[i], b) - dist(ps[i], t);
            ss2 = i;
        }
    }
    for (int i = 0; i < n; i++) {
        if(dist(ps[i], a) - dist(ps[i], t) < tt1 && i != ss2) {
            tt1 = dist(ps[i], a) - dist(ps[i], t);
            ss1 = i;
        }
    }
    double tmp = min(t1 + t2, tt1 + tt2);
    printf("%.10f\n", res + tmp);
    return 0;
}
