#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main() {
    unsigned long long n, m;
    while(scanf("%llu%llu", &n, &m) == 2 && n && m) {
        if(n > m) swap(n, m);
        printf("%llu\n", 2*n*(n-1)*(3*m-n-1)/3 + n*m*(m+n-2));
    }
    return 0;
}
