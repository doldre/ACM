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

const double INF = 1e15;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    double a, b;
    int n;
    scanf("%lf%lf", &a, &b);
    scanf("%d", &n);
    double ans = INF;
    for (int i = 0; i < n; i++) {
        double x, y, v;
        scanf("%lf%lf%lf", &x, &y, &v);
        double tmp = sqrt((a - x) * (a - x) + (b - y) * (b - y)) / v;
        ans = min(ans, tmp);
    }
    printf("%.9f\n", ans);
    return 0;
}

