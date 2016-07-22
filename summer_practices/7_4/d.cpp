#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
#define pr(x) cout << #x << " = " << x << " " 
#define prln(x) cout << #x << " = " << x << endl
typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 500 + 5;
int mp[maxn][maxn];
struct DSU {
    int par[maxn*maxn], n;
    void init(int n) {
        this->n = n;
        for (int i = 0; i <= n; i++) {
            par[i] = i;
        }
    }

    int find(int x) {
        return x == par[x] ? x : par[x] = find(par[x]);
    }

    void merge(int a, int b) {
        a = find(a), b = find(b);
        par[b] = a;
    }
}dsu;

int T, N, M, Q;
char str[maxn];

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int id(int x, int y) {
    return x * M + y + 1;
}

int s, t;
void work(int x, int y) {
    if(x == 0) {
        dsu.merge(s, id(x, y));
    }
    if(x == N - 1) {
        dsu.merge(t, id(x, y));
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
            if(mp[nx][ny] == 0) {
                dsu.merge(id(x, y), id(nx, ny));
            }
        }
    }
}

int qx[maxn*maxn], qy[maxn*maxn];

int main() {
#ifdef LOCAL
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", 'w', stdout);
#endif
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &N, &M);
        for (int i = 0; i < N; i++) {
            scanf("%s", str);
            for (int j = 0; j < M; j++) {
                mp[i][j] = str[j] - '0';
            }
        }
        scanf("%d", &Q);
        for (int i = 1; i <= Q; i++) {
            scanf("%d%d", &qx[i], &qy[i]);
            mp[qx[i]][qy[i]] = 1;
        }

        dsu.init(N*M + 1);
        s = 0, t = N * M + 1;
            
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if(mp[i][j] == 0) {
                    work(i, j);
                }
            }
        }
        
        if(dsu.find(s) == dsu.find(t)) {
            printf("-1\n");
        } else {
            int i;
            for (i = Q; i >= 1; i--) {
                mp[qx[i]][qy[i]] = 0;
                work(qx[i], qy[i]);
                if(dsu.find(s) == dsu.find(t)) {
                    printf("%d\n", i);
                    break;
                }
            }
            if(i == 0) {
                printf("0\n");
            }
        }
    }
    return 0;
}
