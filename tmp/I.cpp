/************************************************
 *Author        :mathon
 *Created Time  :2016年05月04日 星期三 15时20分38秒
 ***********************************************/
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
vector<int> vi;
#define xx first
#define yy second
#define lowbit(x) (x&-x)
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 2000 + 5;
const double eps = 1e-10;
double A, B, C;
double res[maxn];

void dfs(int curpos, double p, int n) {
    if(p < eps) return;
    res[curpos] += p * C;
    if(curpos > 0 && n > 1) {
        if(p * B * C > eps)
            dfs(curpos - 1, p * B, n - 1);
    } 
    if(curpos == 0) {
        if(p * A * C > eps)
            dfs(n - 1, p * A, n);
    } else {
        if(p * A * C > eps)
            dfs(curpos - 1, p * A, n);
    }
}

int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int N, M, K;
    while(cin >> N >> M >> K) {
        double p1, p2, p3, p4;
        cin >> p1 >> p2 >> p3 >> p4;
        double tot = p2 + p3 + p4;
        if(tot != 0) {
            A = p2 / tot; B = p3 / tot; C = p4 / tot;
        }
        for (int i = 0; i < maxn; i++) res[i] = 0;
        if(tot != 0) 
            dfs(M - 1, 1, N);
        double ans = 0;
        for (int i = 0; i < K; i++) {
            ans += res[i];
        }
        printf("%.5f\n", ans);
    }
    return 0;
}
