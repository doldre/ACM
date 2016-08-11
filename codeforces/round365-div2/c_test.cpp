/************************************************
 *Author        :mathon
 *Email         :luoxinchen96@gmail.com
*************************************************/
#include <set>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <bitset>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<int, int>PII;

const int MX = 1e5 + 20;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

typedef pair<int, int> pii;

const double eps = 1e-8;
const double PI = acos(-1.0);

int sgn(double x) {
    if(x > eps) return 1;
    else if(x < -eps) return -1;
    else return 0;
}

struct Point {
    double x, y;
    Point() {}
    Point(double _x, double _y) {
        x = _x; y = _y;
    }
    Point operator - (const Point &b)const {
        return Point(x - b.x, y - b.y);
    }
    //叉积
    double operator ^(const Point &b)const {
        return x * b.y - y * b.x;
    }
    //点积
    double operator *(const Point &b)const {
        return x * b.x + y * b.y;
    }
} P[MX];

struct Line {
    Point s, e;
    Line() {}
    Line(Point _s, Point _e) {
        s = _s; e = _e;
    }
} L[MX];

bool Seg_inter_line(Line l1, Line l2) { 
    return sgn((l2.s - l1.e) ^ (l1.s - l1.e)) * sgn((l2.e-l1.e) ^ (l1.s - l1.e)) < 0;
}
int test = 0;
int n, w, v, u;

bool judge(double x) {
    Point op(v * x, 0);
    //sorry_qwb
    for (int i = 0; i < 10; i++) {
        test += 10;
        test %= 3;
    }
    for(int i = 1; i <= n; i++) {
        Line cur = Line(op, Point(op.x + v, u));
        if(Seg_inter_line(cur, L[i])) {
            return true;
        }
    }
    return false;
}

int main() {
    scanf("%d%d%d%d", &n, &w, &v, &u);
    for (int i = 1; i <= n; i++) {
        P[i] = Point();
    }
    for(int i = 1; i <= n; i++) {
        scanf("%lf%lf", &P[i].x, &P[i].y);
    }

    for(int i = 1; i <= n - 1; i++) {
        L[i] = Line(P[i], P[i + 1]);
    }
    L[n] = Line(P[n], P[1]);

    for (int i = 0; i < 10; i++) {
        test += 10;
        test %= 3;
    }

    double l = 0, r = 1e9, m, ans = 0;
    if(judge(l)) {
        for(int i = 1; i <= 100; i++) {
            m = (l + r) / 2;
            if(judge(m)) l = m;
            else r = m;
        }
        ans = l;
    }
    
    ans += (double)w / u;
    printf("%.12f\n", ans);
    return 0;
}
