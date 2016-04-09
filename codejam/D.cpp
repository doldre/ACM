#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    freopen("D-small.in", "r", stdin);
    freopen("D-small.txt", "w", stdout);
    int T;
    int k , c, s;
    scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        scanf("%d%d%d", &k, &c, &s);
        printf("Case #%d:", Cas);
        for (int i = 1; i <= s; i++) {
            printf(" %d", i);
        }
        printf("\n");
    }
    return 0;
}
