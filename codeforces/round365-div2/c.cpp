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
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
template<class T> inline T lowbit(T x) { return x & (-x); }

const int MAXN = 1e4 + 5;
struct Point {
    int x, y;
    Point() {}
    Point(int x, int y):x(x), y(y) {}
    Point operator - (const Point &b) const {
        return Point(x - b.x, y - b.y);
    }

    ll det(const Point &b) {
        return (ll)x * b.y - (ll)y * b.x;
    }

    ll dot(const Point &b) {
        return (ll)x * b.x + (ll)y * b.y;
    }
    
    void read() {
        scanf("%d%d", &x, &y);
    }

}ps[MAXN*2];

int n, w, v, u;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d%d%d", &n, &w, &v, &u);
    for (int i = 0; i < n; i++) {
        ps[i].read();
    }
    // reverse(ps, ps + n);
    memcpy(ps + n, ps, sizeof(Point) * n);
    Point s(0, 0), t(v, u);
    bool flag = false;
    int k = 0;
    double ans = 0;
    for (int i = 0; i < n; i++) {
        if((ps[i] - s).det(t) < 0) {
            flag = true;
        }
        if((ps[i] - s).det(ps[k] - s) >= 0) {
            k = i;
        }
    }
    if(!flag) {
        ans = (double)w / u;
    } else {
        Point last(0, 0);
        for (int i = k; i < 2 * n; i++) {
            if((ps[i] - last).det(t) <= 0) break;
            ans += (double)(ps[i] - last).x / v;
            last = ps[i];
        }
        ans += (double)(w - last.y) / u;
    }
    printf("%.9f\n", ans);
    return 0;
}

