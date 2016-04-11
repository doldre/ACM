#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps = 1e-9;
const double T = 1e9;
const double step = 0.99;
const double inf = 1e15;
const double k = 1e-7;
typedef long long ll;
struct Point {
    ll x, y;
};

double dist(Point a, Point b) {
    return sqrt(((double)b.x - a.x) * (b.x - a.x) + ((double)b.y - a.y) * ((double)b.y - a.y));
}

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

Point A, B, C;
double J(Point p) {
    return dist(A, p) + 2*dist(p, B) + 3*dist(p, C);
}

double solve() {
    srand(10);
    double te = T;
    Point cur = C;
    double ans = inf;
    while(te > eps) {
        bool flag = 1;
        while(flag) {
            flag = 0;
            for (int i = 0; i < 4; i++) {
                Point z;
                z.x = cur.x + dx[i] * te;
                z.y = cur.y + dy[i] * te;
                double tp = J(z);
                if(ans > tp) {
                    ans = tp;
                    cur = z;
                    flag = 1;
                }
            }
        }
        te *= step;
    }
    return ans;
}

int main() {
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
    printf("%.6f\n", solve());
}
