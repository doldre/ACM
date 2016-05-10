#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
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
        sgn((b.s - a.e).det(a.s - a.e)) * sgn((b.e - a.e).det(a.s - a.e)) <= 0 &&
        sgn((a.s - b.e).det(b.s - b.e)) * sgn((a.e - b.e).det(b.s - b.e)) <= 0;
}
