#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#define prln(x) cout << #x << " = " << x << endl
#define pr(x) cout << #x << " = " << x << " "
using namespace std;

const double eps = 1e-9;

int sgn(double x) {
    if(x > eps) return 1;
    else if (x < -eps) return -1;
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

double dist(const Point &a, const Point &b) {
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

typedef Point Vector;

struct Line {
    Point s, e;
    Line() {}
    Line (Point s, Point e): s(s), e(e) {}
};

bool LineCross(Line a, Line b) {
    return max(a.s.x, a.e.x) >= min(b.s.x, b.e.x) &&
        max(b.s.x, b.e.x) >= min(a.s.x, a.e.x) &&
        max(a.s.y, a.e.y) >= min(b.s.y, b.e.y) &&
        max(b.s.y, b.e.y) >= min(a.s.y, a.e.y) &&
        sgn((b.s - a.e).det(a.s - a.e)) * sgn((b.e - a.e).det(a.s - a.e)) < 0 &&
        sgn((a.s - b.e).det(b.s - b.e)) * sgn((a.e - b.e).det(b.s - b.e)) < 0;
}

const double inf = 1e13;
const int maxn = 100 + 5;
Line segs[maxn];
Point pts[maxn];
double d[maxn][maxn];
const int W = 10, H = 10;
int cntpts, cntsegs;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    int n;
    while(scanf("%d", &n) == 1 && n != -1) {
        cntpts = 0, cntsegs = 0;
        pts[cntpts++] = Point(0, 5);
        pts[cntpts++] = Point(10, 5);
        for (int i = 0; i < n; i++) {
            double x, y1, y2, y3, y4;
            scanf("%lf%lf%lf%lf%lf", &x, &y1, &y2, &y3, &y4);
            pts[cntpts++] = Point(x, y1);
            pts[cntpts++] = Point(x, y2);
            pts[cntpts++] = Point(x, y3);
            pts[cntpts++] = Point(x, y4);
            segs[cntsegs++] = Line(Point(x, 0), Point(x, y1));
            segs[cntsegs++] = Line(Point(x, y2), Point(x, y3));
            segs[cntsegs++] = Line(Point(x, y4), Point(x, H));
        }
        //prln(cntpts);
        //prln(cntsegs);

        for (int i = 0; i < maxn; i++) {
            for (int j = 0; j < maxn; j++) {
                d[i][j] = inf;
            }
        }

        for (int i = 0; i < cntpts; i++) {
            for (int j = i + 1; j < cntpts; j++) {
                Line l = Line(pts[i], pts[j]);
                bool ok = true;
                for (int k = 0; k < cntsegs; k++) {
                    if(LineCross(l, segs[k])) {
                        ok = false;
                        break;
                    }
                }
                if(ok) {
                    d[j][i] = d[i][j] = dist(pts[i], pts[j]);
                    /* prln(d[j][i]); */
                }
            }
        }

        for (int k = 0; k < cntpts; k++) {
            for (int i = 0; i < cntpts; i++) {
                for (int j = 0; j < cntpts; j++) {
                    if(d[i][k] + d[k][j] < d[i][j]) {
                        d[i][j] = d[i][k] + d[k][j];
                    }
                }
            }
        }
        printf("%.2f\n", d[0][1]);
    }
    return 0;
}
