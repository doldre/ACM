#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 5;
struct Pad {
    int x1, x2, h;
}pads[maxn];
int dp[maxn][2];
bool cmp(const Pad &a, const Pad &b) {
    return a.h > b.h;
};
int N, X, Y, MAX;
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d%d", &N, &X, &Y, &MAX);
        for (int i = 0; i < N; i++) {
            scanf("%d%d%d", &pads[i].x1, &pads[i].x2, &pads[i].h);
            dp[i][0] = dp[i][1] = inf;
        }
        dp[N][0] = dp[N][1] = inf;
        pads[N] = {-inf, inf, 0};
        sort(pads, pads + N + 1, cmp);
        int i;
        for (i = 0; i <= N; i++) {
            if(pads[i].x1 <= X && pads[i].x2 >= X && pads[i].h <= Y) {
                if(i == N) {
                    dp[N][0] = Y - pads[i].h;
                    break;
                }
                dp[i][0] = Y - pads[i].h + X - pads[i].x1;
                dp[i][1] = Y - pads[i].h + pads[i].x2 - X;
                break;
            }
        }

        for (; i <= N; i++) {
            int x = pads[i].x1, h = pads[i].h;
            for (int j = i + 1; j <= N; j++) {
                if(h - pads[j].h > MAX) break;
                if(j == N) {
                    dp[j][0] = min(dp[j][0], dp[i][0] + h - pads[j].h);
                    break;
                }
                if(pads[j].x1 <= x && pads[j].x2 >= x) {
                    int d = h - pads[j].h;
                    dp[j][0] = min(dp[j][0], dp[i][0] + d + x - pads[j].x1);
                    dp[j][1] = min(dp[j][1], dp[i][0] + d - x + pads[j].x2);
                    break;
                }
            }
            x = pads[i].x2;
            for (int j = i + 1; j <= N; j++) {
                if(h - pads[j].h > MAX) break;
                if(j == N) {
                    dp[j][0] = min(dp[j][0], dp[i][1] + h - pads[j].h);
                    break;
                }
                if(pads[j].x1 <= x && pads[j].x2 >= x) {
                    int d = h - pads[j].h;
                    dp[j][0] = min(dp[j][0], dp[i][1] + d + x - pads[j].x1);
                    dp[j][1] = min(dp[j][1], dp[i][1] + d - x + pads[j].x2);
                    break;
                }
            }
        }
        printf("%d\n", dp[N][0]);
    }
    return 0;
}
