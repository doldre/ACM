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
const int maxn = 100 + 5;
const int inf = 0x3f3f3f3f;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
char mp[maxn][maxn];
int d[maxn*maxn];
int dist[maxn*maxn][maxn*maxn];
int N, M;
int id(pii p) {
    return p.xx * M + p.yy;
}

int bfs(pii s, pii t) {
    memset(d, inf, sizeof(d));
    d[id(s)] = 0;
    queue<pii> que;
    que.push(s);
    while(!que.empty()) {
        pii cur = que.front(); que.pop();
        int x = cur.xx, y = cur.yy;
        if(cur == t) return d[id(cur)];
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir], ny = y + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(d[id(pii(nx, ny))] >= inf && mp[nx][ny] == '.') {
                pii nxt = pii(nx, ny);
                d[id(nxt)] = d[id(cur)] + 1;
                que.push(nxt);
            }
        }
    }
    return d[id(t)];
}

const int maxk = 4;
pii T[maxk + 1];

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(scanf("%d%d", &N, &M) == 2 && N && M) {
        for (int i = 0; i < N; i++) {
            scanf("%s", mp[i]);
            for (int j = 0; j < M; j++) {
                if(mp[i][j] == '@') {
                    T[0] = pii(i, j);
                }
            }
        }

        int K; scanf("%d", &K);
        for (int i = 1; i <= K; i++) {
            scanf("%d%d", &T[i].xx, &T[i].yy);
            T[i].xx--; T[i].yy--;
        }
       
        for (int i = 0; i <= K; i++) {
            for (int j = 0; j <= K; j++) {
                if(i == j) continue;
                int t = bfs(T[i], T[j]);
                dist[id(T[i])][id(T[j])] = t;
            }
        }
        int A[] = {0, 1, 2, 3, 4};
        int ans = inf;
        do {
            int tmp = 0;
            for (int i = 0; i < K; i++) {
                tmp  += dist[id(T[A[i]])][id(T[A[i+1]])];
            }
            ans = min(ans, tmp);
        } while(next_permutation(A + 1, A + K + 1));

        if(ans == inf) ans = -1;
        printf("%d\n", ans);
    }
    return 0;
}

