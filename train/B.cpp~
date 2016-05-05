/************************************************
 *Author        :mathon
 *Created Time  :四  5/ 5 10:00:09 2016
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
const int maxn = 5000 + 5;
int n, m;
struct Point {
    int x, y;
    Point() {}
    Point (int x, int y):x(x), y(y) {}
    int crosProduct(const Point &b) {
        return x * b.y - y * b.x;
    }
};

struct seg {
    Point a, b;
    int crosP(Point x) {
        Point v1 = Point(b.x - a.x, b.y - a.y);
        Point v2 = Point(x.x - a.x, x.y - a.y);
        return v1.crosProduct(v2);
    }
    bool operator < (const seg&b) const {
        return a.x < b.a.x;
    }
}seg[maxn];
int cal_pos(Point x) {
    int l = 0, r = n + 2;
    while(r - l > 1) {
        int m = (l + r) >> 1;
        if(seg[m].crosP(x) > 0) {
            r = m;
        } else l = m;
    }
    return r;
}

int cnt[maxn];
int res[maxn];
int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(scanf("%d%d", &n, &m) == 2 && n != 0) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        seg[0] = {Point(x1, y2), Point(x1, y1)};
        seg[n+1] = {Point(x2, y2), Point(x2, y1)};
        for (int i = 1; i <= n; i++) {
            int u, l;
            scanf("%d%d", &u, &l);
            seg[i] = {Point(l, y2), Point(u, y1)};
        }
        sort(seg, seg + n + 2); 
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= m; i++) {
            Point x;
            scanf("%d%d", &x.x, &x.y);
            int p = cal_pos(x);
            //prln(p);
            cnt[p]++;
        }
        for (int i = 0; i <= m; i++) res[i] = 0;

        for (int i = 0; i <= n; i++) {
            res[cnt[i+1]]++;
            //pr(cnt[i+1]);
        }
        puts("Box");
        for (int i = 1; i <= m; i++) {
            if(res[i] > 0) {
                printf("%d: %d\n", i, res[i]);
            }
        }
    }
    return 0;
}
