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
typedef long double ld;
#define xx first
#define lowbit(x) (x&-x)
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const double eps = 1e-9;

int sign(ld x) {
    if(x < -eps) {
        return -1;
    } else if(x > eps) {
        return 1;
    } else return 0;
}

struct Point3 {
    ld x, y, z;
    Point3() {}
    Point3(ld x, ld y, ld z): x(x), y(y), z(z) {}
    Point3 operator - (const Point3 &b) const {
        return Point3(x - b.x, y - b.y, z - b.z);
    }
    
    Point3 operator + (const Point3 &b) const {
        return Point3(x + b.x, y + b.y, z + b.z);
    }
    
    ld dot(const Point3 &b) const {
        return x * b.x + y * b.y + z * b.z;
    }

    Point3 cross(const Point3 &b) const {
        return Point3(y * b.z - z * b.y, z * b.x - x * b.z, x * b.y - y * b.x);
    }
};

typedef Point3 Vector3;


ld sqr(ld x) {
    return x * x;
}

ld dist(const Point3 &a, const Point3 &b) {
    return sqrt((b - a).dot(b - a));
};

ld Area2(Point3 A, Point3 B, Point3 C) {
    ld a = dist(B, C), b = dist(A, C), c = dist(A, B);
    ld s = (a + b + c) / 2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

ld Volume6(Point3 A, Point3 B, Point3 C, Point3 D) {
    return (D-A).dot((B-A).cross(C-A));
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif 
    double x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4;
    while(cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x3 >> y3 >> z3 >>
            x4 >> y4 >> z4) {
        Point3 A(x1, y1, z1), B(x2, y2, z2), C(x3, y3, z3), D(x4, y4, z4);
        ld s1 = Area2(B, C, D);
        ld s2 = Area2(A, C, D);
        ld s3 = Area2(A, B, D);
        ld s4 = Area2(B, C, A);
        if(s1 == 0 || s2 == 0 || s3 == 0 || s4 == 0) {
            puts("O O O O");
            continue;
        }
        double x, y, z, r;
        ld t = s1 + s2 + s3 + s4;
        x = (s1 * x1  + s2 * x2 + s3 * x3 + s4 * x4) / t;
        y = (s1 * y1  + s2 * y2 + s3 * y3 + s4 * y4) / t;
        z = (s1 * z1  + s2 * z2 + s3 * z3 + s4 * z4) / t;
        r = abs(Volume6(A, B, C, D))/2/t;
        if(r == 0) {
            puts("O O O O");
        } else {
            printf("%.4f %.4f %.4f %.4f\n", x, y, z, r);
        }
    }
    return 0;
}

