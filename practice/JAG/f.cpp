#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define pr(x) cout << #x << " = " << x << " "
#define prln(x) cout << #x << " = " << x << endl
typedef long long ll;
const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;
struct Node {
    int a, b, d;
    Node () {}
    Node (int a, int b):a(a), b(b) {
        d = a - b;
    }
}nds[MAXN];

bool cmp(const Node &a, const Node &b) {
    return a.d > b.d;
}

int C[MAXN];
ll SD[MAXN], SC[MAXN];
int catch_day[MAXN];
int N, L;

int solve(int i) {
    int l = 0, r = N + 1;
    while(l < r - 1) {
        int m = (l + r) >> 1;
        ll x = SD[m-1];
        if(m >= i) {
            x = SD[m] - nds[i].d;
        }
        if(x >= L - nds[i].a) {
            r = m;
        } else l = m;
    }
    if(catch_day[i] < r || r > N) return INF;
    else return r;
}

int main() {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d", &N, &L);
    for (int i = 1; i <= N; i++) {
        int a, b; scanf("%d%d", &a, &b);
        nds[i] = Node(a, b);
    }
    for (int i = 1; i <= N; i++) {
        scanf("%d", &C[i]);
        SC[i] = SC[i-1] + C[i];
    }
    sort(nds + 1, nds + N + 1, cmp);
    for (int i = 1; i <= N + 1; i++) {
        SD[i] = SD[i-1] + nds[i].d;
    }
    int last = 1;
    for (int i = 1; i <= N; i++) {
        for (; last <= N; last++) {
            ll x = SD[last];
            if(last >= i) {
                x = SD[last+1] - nds[i].d;
            }
            if(x <= SC[last]) break;
        }
        catch_day[i] = last;
        // pr(i); prln(catch_day[i]);
    }
    int ans = INF;
    for (int i = 1;  i <= N; i++) {
        // pr(i); prln(solve(i));
        ans = min(ans, solve(i));
    }
    if(ans == INF) ans = -1;
    printf("%d\n", ans);
}
