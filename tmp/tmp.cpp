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

/************************************************
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
          佛祖保佑，pass system test
*************************************************/

const double eps = 1e-6;
const int maxn = 1e5 + 5;

int sign (double x) {
    if(x > eps) return 1;
    else if(x < eps) return -1;
    else return 0;
}

struct Point {
    double x, y;
    Point() {}
    Point (double x, double y):x(x), y(y) {}
    Point operator - (const Point &b) const {
        return Point(x - b.x, y - b.y);
    }
    ll det(const Point &b) const {
        return x * b.y - y * b.x;
    }
    ll dot(const Point &b) const {
        return x * b.x + y * b.y;
    }
};


struct Line {
    Point s, e;
    Line() {}
    Line(Point s, Point e):s(s), e(e) {}
};

bool OnSeg(Point P, Line L) {
     return sign((L.s - P).det(L.e - P)) == 0 &&
            sign((P.x - L.s.x) * (P.x - L.e.x)) <= 0 &&
            sign((P.y - L.s.y) * (P.y - L.e.y)) <= 0;
}

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

int PointInRec(Point a, Point p[], int n) {
    for (int i = 0; i < n; i++) {
        if(sign((p[i] - a).det(p[(i + 1) % n] - a) < 0)) return -1;
        else if(OnSeg(a, Line(p[i], p[(i+1) % n]))) return 0;
    }
    return 1;
}

int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n;
    sa(n);
    while(n--) {
        Point s, e;
        double x1, y1, x2, y2;
        scanf("%lf%lf%lf%lf", &s.x, &s.y, &e.x, &e.y);
        scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);
        Point ps[10];
        ps[0] = Point(x1, y1);
        ps[1] = Point(x2, y1);
        ps[2] = Point(x2, y2);
        ps[3] = Point(x1, y2);
        Line li[4];
        li[0] = Line(ps[0], ps[1]);
        li[1] = Line(ps[1], ps[2]);
        li[2] = Line(ps[2], ps[3]);
        li[3] = Line(ps[3], ps[0]);
        Line lx = Line(s, e);
        bool ok = false;
        for (int i = 0; i < 4; i++) {
            if(LineCross(lx, li[i])) {
                ok = true;
                break;
            }
        }
        if(PointInRec(s, ps, 4) >= 0 || PointInRec(e, ps, 4) >= 0) ok = true;
        if(ok) {
            printf("T\n");
        } else printf("F\n");
    }
    return 0;
}
