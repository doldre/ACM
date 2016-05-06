/************************************************
 *Author        :mathon
 *Created Time  :四  5/ 5 21:25:41 2016
 *Problem class:
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
vector<int> vi;
#define xx first
#define lowbit(x) (x&-x)
#define yy second
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++)
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const double eps = 1e-11;

int dcmp(double x) {
    if(fabs(x) < eps) return 0;
    if(x < 0) return -1;
    else return 1;
}

struct Point {
    double x, y;
    Point() {}
    Point(double x, double y):x(x), y(y) {}
    double det(const Point &b) const {
        return x * b.y - y * b.x;
    }

    Point operator - (const Point &b) const {
        return Point(x - b.x, y - b.y);
    }
};

Point crosspoint(Point a, Point b, Point c, Point d) {
    double k = ((a - c).det(c - d)) / ((a - b).det(c - d));
    Point res = a;
    res.x += (b.x - a.x) * k;
    res.y += (b.y - a.y) * k;
    return res;
}
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    sa(T);
    puts("INTERSECTING LINES OUTPUT");
    while(T--) {
        Point a, b, c, d;
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf",
                &a.x, &a.y, &b.x, &b.y, &c.x, &c.y, &d.x, &d.y);
        if(dcmp((b - a).det(d - c) == 0)) {
            if(dcmp((c - a).det(d - a)) == 0) {
                printf("LINE\n");
            } else {
                printf("NONE\n");
            }
        } else {
            Point p = crosspoint(a, b, c, d);
            printf("POINT %.2f %.2f\n", p.x, p.y);
        }
    }
    printf("END OF OUTPUT\n");
    return 0;
}
