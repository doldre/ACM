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
int n, m, k;

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
    for (int i = 1; i <= n; i++) {
        int t = 0;
        for (int j = 1; j <= m; j++) {
            t += board[i][j];
            boardsum[i][j] = boardsum[i-1][j] + t;
        }
    }
}
