#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    freopen("large.in", "r", stdin);
    freopen("large.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        printf("Case #%d: ", Cas);
        int n;
        int mask = 0;
        scanf("%d", &n);
        if(n == 0) {
            printf("INSOMNIA\n");
            continue;
        }
        int x = 0;
        for (int i = 1; mask != 1023; i++) {
            x += n;
            int t = x;
            while(t > 0) {
                int m = t % 10;
                mask |= (1<<m);
                t /= 10;
            }
        }
        printf("%d\n", x);
    }
    return 0;
}
