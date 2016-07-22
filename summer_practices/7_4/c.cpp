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
const int maxm = 2000 + 5;
struct DSU {
    int par[maxn], r[maxn], n;
    void init(int n) {
        this->n = n;
        for (int i = 0; i <= n; i++) {
            par[i] = i; r[i] = 0;
        }
    }
    
    int find(int x) {
        if(x != par[x]) {
            int fx = par[x];
            par[x] = find(par[x]);
            r[x] = (r[x] + r[fx]) % 3;
        }
        return par[x];
    }

    bool merge(int x, int y, int t) {
        int fx = find(x), fy = find(y);
        if(fx == fy) {
            if((r[y] + t) % 3 != r[x]) return false;
            else return true;
        } else {
            par[fx] = fy;
            r[fx] = (r[y] -r[x] + t + 3) % 3;
            return true;
        }
    }
}dsu;

int N, M;
int err[maxn], maxerr, cnt;
int U[maxm], V[maxm], T[maxm];
int main() {
#ifdef LOCAL
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", 'w', stdout);
#endif
    while(scanf("%d%d", &N, &M) != EOF) {
        for (int i = 0; i < M; i++) {
            char c;
            // scanf("%d%c%d", &U[i], &c, &V[i]);
            scanf("%d", &U[i]);
            while((c = getchar()) == ' ');
            scanf("%d", &V[i]);
            if(c == '=') T[i] = 0;
            if(c == '<') T[i] = 1;
            if(c == '>') T[i] = 2;
        }
        
        maxerr = 0, cnt = 0;
        int res = 0;
        memset(err, -1, sizeof(err));
        for (int judge = 0; judge < N; judge++) {
            dsu.init(N);
            for (int i = 0; i < M; i++) {
                int x = U[i], y = V[i], t = T[i];
                if(x == judge || y == judge) continue;
                if(!dsu.merge(x, y, t)) {
                    err[judge] = i + 1;
                    maxerr = max(maxerr, err[judge]);
                    break;
                }
            }
            if(err[judge] == -1) {
                cnt++;
                res = judge;
            }
        }
        if(cnt == 0) {
            printf("Impossible\n");
        } else if(cnt == 1) {
            printf("Player %d can be determined to be the judge after %d lines\n", res, maxerr);
        } else if(cnt > 1) {
            printf("Can not determine\n");
        }
    }
    return 0;
}
