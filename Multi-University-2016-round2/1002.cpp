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
const int maxn = 1<<17;
int n;
string opt;
ll A[maxn];
vector<int> G[maxn];
ll f[maxn];
void dfs(int u, int fa) {
    ll t = 0;
    if(fa != -1) {
        t = f[fa] - A[fa];
    }
    if(opt == "AND") {
        t += A[fa] & A[u];
    }
    if(opt == "OR") {
        t += A[fa] | A[u];
    }
    if(opt == "XOR") {
        t += A[fa] ^ A[u];
    }
    t += A[fa];
    f[u] = t;
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];



int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--) {
       scanf("%d", &n);
       for (int i = 0; i <= n; i++) G[i].clear();
       cin >> opt;
       for (int i = 1; i <= n; i++) {
           scanf("%lld", &A[i]);
       }
       for (int i = 2; i <= n; i++) {
           int f; scanf("%d", &f);
           G[f].push_back(i);
       }
       
    }
    return 0;
}

