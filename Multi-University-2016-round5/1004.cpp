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
const int MAXN = 2000 + 5;

struct Point {
    ll x, y;
    Point() {}
    Point(ll x, ll y): x(x), y(y) {}
    void read() {
        scanf("%lld%lld", &x, &y);
    }
    Point operator - (const Point &b) const {
        return Point(x - b.x, y - b.y);
    }
    ll cross(const Point &b) const {
        return x * b.y - y * b.x;
    }
    ll dot(const Point &b) const {
        return x * b.x + y * b.y;
    }
    void print() {
        printf("x = %lld, y = %lld\n", x, y);
    }
}ps[MAXN];
int n;

bool cmp(const Point &a, const Point &b) {
    if(a.y * b.y <= 0) {
        if(a.y > 0 || b.y > 0) return a.y < b.y;
        if(a.y == 0 && b.y == 0) return a.x < b.x;
    }
    return a.cross(b) > 0;
}

Point buf[MAXN * 2];

int main(void) {
#ifdef MATHON
    freopen("1004.in", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while(scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            ps[i].read();
        }
        ll ans = 0;
        for (int k = 0; k < n; k++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if(k == j) continue;
                buf[cnt++] = ps[j] - ps[k];
            }
            sort(buf, buf + cnt, cmp);
            memcpy(buf + cnt, buf, sizeof(Point) * cnt);
            ll tmp = 0;
            for (int i = 0, j = 0; i < cnt; i++) {
                if(i == j) while(j < i + cnt && buf[i].cross(buf[j]) == 0 && buf[i].dot(buf[j]) > 0) j++;
                while(j < i + cnt && buf[i].cross(buf[j]) > 0 && buf[i].dot(buf[j]) > 0) j++;
                tmp += j - i - 1;
            }
            tmp = (cnt) * (cnt - 1) / 2  - tmp;
            ans += tmp;
        }
        ans = ll(n) * (n -1) * (n - 2) / 6 - ans;
        printf("%lld\n", ans);
    }
    return 0;
}

