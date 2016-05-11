const double eps = 1e-9;
const int maxn = 1e5 + 5;

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
}lines[maxn];

bool StrictCross(Line a, Line b) {
    return sign((a.s - b.s).det(b.e - b.s)) * sign((a.e - b.s).det(b.e - b.s)) < 0 &&
        sign((b.s - a.s).det(a.e - a.s)) * sign((b.e - a.s).det(a.e - a.s)) < 0;
}

