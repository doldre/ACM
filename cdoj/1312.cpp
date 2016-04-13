/************************************************
 *Author        :mathon
 *Created Time  :三  4/13 09:13:45 2016
 *题目类型:
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
vector<int> vi;
#define xx first
#define yy second
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++)
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int mod = int(1e9) + 7, inf = 0x3f3f3f3f, maxn = 1000 + 5;
int A[maxn][maxn];
int H[maxn][maxn];
int n, m;
typedef pair<int, pair<int, int> > Node;
void solve() {
    priority_queue<Node, vector<Node>, greater<Node> > que;
    for (int i = 0; i < n; i++) {
        H[i][0] = A[i][0];
        que.push(Node(A[i][0], pii(i, 0)));
        H[i][m-1] = A[i][m-1];
        que.push(Node(A[i][m-1], pii(i, m-1)));
    }
    for (int j = 1; j < m - 1; j++) {
        H[0][j] = A[0][j];
        que.push(Node(A[0][j], pii(0, j)));
        H[n-1][j] = A[n-1][j];
        que.push(Node(A[n-1][j], pii(n-1, j)));
    }

}
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            H[i][j] = inf;
        }
    }
    return 0;
}
