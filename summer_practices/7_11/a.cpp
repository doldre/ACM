/************************************************
 *Author        :mathon
 *Email         :luoxinchen96@gmail.com
*************************************************/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stack>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
#define xx first
#define lowbit(x) (x&-x)
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int inf = 0x3f3f3f3f;
const int maxn = 200 + 5;
char mp[maxn][maxn];
pii ps[maxn];
int cntps;
int used[maxn][maxn];
int timestamp;
int N, M;

pii dir1[] = {pii(0, 1), pii(1, 0), pii(-1, 0)};
pii dir2[] = {pii(1, 0), pii(0, -1), pii(0, -1)};

bool legal(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int work(int mask) {
    timestamp++;
    int cntcover = 0;
    for (int i = 0; i < cntps; i++) {
        if((mask>>i)&1) {
            int x = ps[i].xx, y = ps[i].yy;
            if(x - 1 >= 0 && mp[x-1][y] == '#') return inf;
            if(x - 1 >= 0 && used[x-1][y] != timestamp) {
                used[x-1][y] = timestamp;
                cntcover++;
            }
            if(used[x][y] != timestamp) {
                used[x][y] = timestamp;
                cntcover++;
            }
            if(y + 1 < M && mp[x][y+1] == '#') return inf;
            if(y + 1 < M && used[x][y+1] != timestamp) {
                used[x][y+1] = timestamp;
                cntcover++;
            }
        }
    }
    if(cntcover == cntps) return __builtin_popcount(mask);
    for (int i = 0; i < cntps; i++) {
        if(((mask >> i) & 1) == 0) {
            int x = ps[i].xx, y = ps[i].yy;
            for (int i = 0; i < 3; i++) {
                int t = 0;
                int nx, ny;
                nx = x + dir1[i].xx, ny = y + dir1[i].yy;
                if(legal(nx, ny)  && mp[nx][ny] == '#') continue;
                if(legal(nx, ny) && used[nx][ny] != timestamp) t++;
                if(used[x][y] != timestamp) t++;
                nx = x + dir2[i].xx, ny = y + dir2[i].yy;
                if(legal(nx, ny) && mp[nx][ny] == '#') continue;
                if(legal(nx, ny) && used[nx][ny] != timestamp) t++;
                if(t + cntcover == cntps) return __builtin_popcount(mask) + 1;
            }
        }
    }
    return inf;
}


int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(scanf("%d%d", &N, &M) == 2 && N && M) {
        memset(used, 0, sizeof(used));
        timestamp = 0;
        cntps = 0;
        for (int i = 0; i < N; i++) {
            scanf("%s", mp[i]);
            for (int j = 0; j < M; j++) {
                if(mp[i][j] == '.') {
                    ps[cntps++] = pii(i, j);
                }
            }
        }
        int ans = inf; 
        for (int i = 0; i < (1<<cntps); i++) {
            ans = min(ans, work(i));
        }
        if(ans == inf) ans = -1;
        printf("%d\n", ans);
    }
    return 0;
}

