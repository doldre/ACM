#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
const int maxn = 500 + 5;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
char mp[maxn][maxn];
char buf[maxn][maxn];
int X[maxn*maxn], Y[maxn*maxn];
bool used[maxn][maxn];
int N, M;
int Q;
bool dfs(int x, int y) {
    used[x][y] = true;
    if (x == N - 1) return true;
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir], ny = y + dy[dir];
        if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (!used[nx][ny] && buf[nx][ny] == '0') {
            if(dfs(nx, ny)) {
                return true;
            }
        }
    }
    return false;
}
bool check() {
    memset(used, 0, sizeof(used));
    for (int j = 0; j < M; j++) {
        if(!used[0][j] && buf[0][j] == '0') {
            if(dfs(0, j)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        memset(mp, 0, sizeof(mp));
        memset(buf, 0, sizeof(buf));
        memset(X, 0, sizeof(X));
        memset(Y, 0, sizeof(Y));
        scanf("%d%d", &N, &M);
        for (int i = 0; i < N; i++) {
            scanf("%s", mp[i]);
        }
        scanf("%d", &Q);
        for (int i = 0; i < Q; i++) {
             scanf("%d%d", &X[i], &Y[i]);
        }
        int l = -1, r = Q + 1;
        while(l < r - 1) {
            int m = (l + r) >> 1;
            memset(buf, 0, sizeof(buf));
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    buf[i][j]= mp[i][j];
                }
            }
            for (int i = 0; i < m && i < Q; i++) {
                buf[X[i]][Y[i]] = '1';
            }
            if(check()) {
                l = m;
            } else {
                r = m;
            }
        }
        if (r == Q + 1) r = -1;
        printf("%d\n", r);
    }
    return 0;
}
