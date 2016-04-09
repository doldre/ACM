#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

const int maxn = 100 + 5;
char str[maxn];

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("B-large.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        scanf("%s", str);
        int len = strlen(str);
        int ans = 0;
        int p = 0;
        if(str[0] == '-') {
            ans = 1;
            for (; p < len && str[p] == '-'; p++);
        }
        for (; p < len; p++) {
            if(str[p] == '-') {
                ans += 2;
                for (; p < len && str[p] == '-'; p++);
            }
        }
        printf("Case #%d: ", Cas);
        printf("%d\n", ans);
    }
    return 0;
}
