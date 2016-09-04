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

const double Beta = acos(9.0 / 16.0);
const double C = acos(-3.0 / 4.0);
const double pi = acos(-1);
double area(double a, double b, double c) {
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while (T--) {
        double l; scanf("%lf", &l);
        double circle = pi * (l / 2) * (l / 2);
        double a = pi * l * l * Beta / (2 * pi) - 0.5 * l * l * sin(Beta);
        double b = area(sqrt(7) / (2 * sqrt(2)) * l, l / 2, l / 2);
        double c = (pi - C) / (2 * pi) * pi * l * l / 4;
        double ans = circle - 2 * (a + b + c);
        printf("%.2f\n", ans);
    }
    return 0;
}

