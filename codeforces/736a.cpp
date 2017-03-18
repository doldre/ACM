#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
int main() {
    long long n;
    scanf("%lld", &n);
    long long a = 3, b = 2;
    int res = 0;
    while(b <= n) {
        res++;
        long long t = a;
        a = a + b;
        b = t;
    }
    printf("%d\n", res);
}
