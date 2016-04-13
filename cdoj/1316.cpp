#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int maxn = 2000 + 5;
const int maxk = 10 + 5;
int A[maxk], B[maxk];
int board[maxn][maxn];
int boardsum[maxn][maxn];
int brushsum[maxn][maxn];
int n, m, K;
void brush(int x1, int y1, int x2, int y2) {
    int sum = boardsum[x2][y2] - boardsum[x2][y1-1] - boardsum[x1-1][y2] + boardsum[x1-1][y1-1];
    if(sum < (y2 - y1 + 1) * (x2 - x1 + 1)) return;
    brushsum[x1][y1]++;
    brushsum[x2+1][y1]--;
    brushsum[x1][y2+1]--;
    brushsum[x2+1][y2+1]++;
}

int main() {
    scanf("%d%d", &n, &m);
    getchar();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c = getchar();
            if(c == 'B') board[i][j] = 1;
            else board[i][j] = 0;
        }
        getchar();
    }

    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        scanf("%d%d", &A[i], &B[i]);
    }

    for (int i = 1; i <= n; i++) {
        int t = 0;
        for (int j = 1; j <= m; j++) {
            t += board[i][j];
            boardsum[i][j] = boardsum[i-1][j] + t;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if(board[i][j]) {
                for (int k = 0; k < K; k++) {
                    int a = A[k], b = B[k];
                    swap(a, b);
                    int x1, y1, x2, y2;
                    x1 = max(1, i - b + 1), y1 = max(1, j - a + 1);
                    x2 = i, y2 = j;
                    brush(x1, y1, x2, y2);
                    y1 = j; y2 = min(m, j + a - 1);
                    brush(x1, y1, x2, y2);
                    x1 = i, y1 = j;
                    x2 = min(n, i + b - 1), y2 = min(m, j + a - 1);
                    brush(x1, y1, x2, y2);
                    x1 = i, y1 = max(1, j - a + 1);
                    x2 = min(n, i + b - 1), y2 = j;
                    brush(x1, y1, x2, y2);
                }
            }
        }
    }
    bool ok = true;
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= m; j++) {
            sum += brushsum[i][j];
            brushsum[i][j] = brushsum[i-1][j] + sum;
//            printf("%d ", brushsum[i][j]);
            if(board[i][j] > 0 && brushsum[i][j] == 0) {
                ok = false;
                break;
            }
        }
//        printf("\n");
    }
    if(ok) {
        printf("POSSIBLE\n");
    } else printf("IMPOSSIBLE\n");
    return 0;
}
