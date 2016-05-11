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

const int inf = 0x3f3f3f3f;
const int maxn = 100;
Line lines[maxn];
Point points[maxn * 2];
int n;

int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int p_num = 0;
    points[p_num++] = Point(0, 0);
    points[p_num++] = Point(0, 100);
    points[p_num++] = Point(100, 0);
    points[p_num++] = Point(100, 100);
    sa(n);
    for (int i = 0; i < n; i++) {
        scanf("%lf%lf", &points[p_num].x, &points[p_num].y);
        p_num++;
        scanf("%lf%lf", &points[p_num].x, &points[p_num].y);
        p_num++;
        lines[i] = Line(points[p_num - 1], points[p_num - 2]);
    }
    int ans = inf;
    Point s;
    scanf("%lf%lf", &s.x, &s.y);
    for (int i = 0; i < p_num; i++) {
        Line l(s, points[i]);
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(StrictCross(l, lines[i])) cnt++;
        }
        ans = min(ans, cnt + 1);
    }
    printf("Number of doors = %d\n", ans);
    return 0;
}
