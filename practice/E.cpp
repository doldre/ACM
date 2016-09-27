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

const int MAXN = 1e5 + 5;
const double pi = acos(-1);
int n;
struct Point {
    ll x, y;
    Point() {}
    Point(ll x, ll y) :x(x), y(y) {}
    void read() {
        scanf("%lld%lld", &x, &y);
    }
    Point operator - (const Point &rhs) const {
        return Point(x - rhs.x, y - rhs.y);
    }
    ll dot(const Point &rhs) const {
        return x * rhs.y - y * rhs.x;
    }
    ll det(const Point &rhs) const {
        return x * rhs.x + y * rhs.y;
    }
    double len() {
        return sqrt(x * x + y * y);
    }
}ps[MAXN];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        ps[i].read();
    }
    int ans = 0;
    double angle = 0;
    for (int i = 0; i < n; i++) {
        Point a = ps[(i+2)%n] - ps[(i+1)%n];
        Point b = ps[(i+1)%n] - ps[i];
        if(a.dot(b) >= 0) {
            angle += pi - acos(a.det(b) / a.len() / b.len());
            ans++;
        } else {
            angle += pi + acos(a.det(b) / a.len() / b.len());
        }
    }
    // prln(angle);
    if(fabs(angle - (n-2)*pi) <= 0.1) ans = n - ans;
    printf("%d\n", ans);
    return 0;
}

