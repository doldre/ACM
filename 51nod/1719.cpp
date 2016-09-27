#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
int A, B, n;
double a, b;
const double pi = acos(-1);
void cal() {
    a = b = 0;
    for (int k = 1; k <= 10000; k++) {
        a += cos(k) * ((double)A/(k + sin(k)));
        b += sin(k) * ((double)A/(k + sin(k)));
        a += -sin(k) * ((double)B/(k + cos(k)));
        b += cos(k) * ((double)B/(k + cos(k)));
    }
}
int main() {
    scanf("%d%d%d", &A, &B, &n);
    cal();
    double phi = acos(a / sqrt(a*a + b * b));
    double ans = phi * n + (double)n * (n - 1) / 2 * pi;
    printf("%.3f\n", ans);
}
    
