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
const int maxn = 1e5 + 5;
const double eps = 1e-8;
const double pi = acos(-1.0);

int sign(long double x) {
    if(x < -eps) return -1;
    else if(x > eps) return 1;
    else return 0;
}

struct Point {
    double x, y;
    Point() {}
    Point(double x, double y):x(x), y(y) {}
    Point operator - (const Point &b) const {
        return Point(x - b.x, y - b.y);
    }
    double length() {
        return sqrt(x * x + y * y);
    }

    void read() {
        scanf("%lf%lf", &x, &y);
    }
};

double dis(Point a, Point b) {
    return (b - a).length();
}

long double sqrDis(Point a, Point b) {
    Point t = b - a;
    return (long double)t.x * t.x + t.y * t.y;
}

struct Circle {
    Point center;
    double r;
    Circle() {}
    Circle(Point center, double r):center(center), r(r) {};
    void read() {
        center.read();
        scanf("%lf", &r);
    }
};

bool isInCircle(Point p, Circle c) {
    return sign(sqrDis(p, c.center) - c.r * c.r) <= 0;
}

double cosc(double a, double b, double c) {
    return (a * a + b * b - c * c) / (2 * a * b);
}

Circle circles[maxn];
Point p;
double v, T, R;
int n;

vector<pair<double, int> > V;

double cal_range() {
    sort(V.begin(), V.end());
    double last;
    double res = 0;
    int cnt = 0;
    for (int i = 0; i < (int)V.size(); i++) {
        if(cnt > 0) {
            res += V[i].xx - last;
        }
        last = V[i].xx;
        cnt += V[i].yy;
    }
    return res;
}

void add_interval(double l, double r) {
    V.push_back(make_pair(l, 1));
    V.push_back(make_pair(r, -1));
}

double tangent_length(Point p, Circle c) {
    double d = dis(p, c.center);
    return sqrt(d * d - c.r * c.r);
}

bool isIntersect(Circle a, Circle b) {
    double d = sqrDis(a.center, b.center);
    return sign(d - (a.r + b.r) * (a.r + b.r)) < 0;
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    p.read();
    scanf("%lf%lf", &v, &T);
    R = v * T;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        circles[i].read();
    }
    for (int i = 0; i < n; i++) {
        if(isInCircle(p, circles[i])) {
            // prln("fuck");
            printf("%.9f\n", 1.0);
            return 0;
        }
        
        if(!isIntersect(Circle(p, R), circles[i])) {
            continue;
        }

        double tangent = tangent_length(p, circles[i]);
        double d = dis(p, circles[i].center); 
        double ang, mid;
        mid = atan2((circles[i].center - p).y, 
                (circles[i].center - p).x);
        if(R >= tangent) {
            ang = asin(circles[i].r / d);
        } else {
            ang = acos(cosc(R, d, circles[i].r));
        }
        double up = fmod(mid + ang + 2 * pi, 2 * pi);
        double down = fmod(mid - ang + 2 * pi, 2 * pi);
        // pr(down); prln(up);
        if(sign(down - up) <= 0) {
            add_interval(down, up);
        } else {
            add_interval(0, up);
            add_interval(down, 2 * pi);
        }
    }
    double range = cal_range();
    printf("%.9f\n", range / (2 * pi));
    return 0;
}
