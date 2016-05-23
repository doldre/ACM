#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define prln(x) cout << #x << " = " << x << endl
#define pr(x) cout << #x << " = " << x << " "
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 5; //最大的点数
//边的结构体
struct Edge {
    int to, c;
    Edge() {}
    Edge(int to, int c): to(to), c(c) {}
};

//vector 模拟临接表
vector<Edge> G[maxn];

int dp[maxn];

int main() {
    freopen("in.txt", "r", stdin);
    int n, m;
    //输入n个点，m条边
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v, c;
        //输入一条有向边，u->v,权值为c
        //为了简单，输入按照所在段，编号从小到大
        scanf("%d%d%d", &u, &v, &c);
        G[u].push_back(Edge(v, c));
    }
    //将dp所有项初始化为inf
    memset(dp, 0x3f, sizeof(dp));
    dp[1] = 0;
    //为了简单我们默认1为源点s，n为汇点t
    for (int i = 1; i < n; i++) {
        for (auto e: G[i]) {
            //更新dp[e.to]
            //因为编号按照段的大小，从小到大给出
            //所以更新dp[e.to]时，dp[i]一定是s 到i点的最小值
            dp[e.to] = min(dp[i] + e.c, dp[e.to]);
            //debug
            /* pr(i); */
            /* pr(e.to); */
            /* prln(dp[e.to]); */
        }
    }
    //输出s 到t的最小距离
    printf("%d\n", dp[n]);
    /*---------
     *
12 21
1 2 9
1 3 7
1 4 3
1 5 2
2 6 4
2 7 2
2 8 1
3 6 2
3 7 7
4 8 11
5 7 11
5 8 8
6 9 6
6 10 5
7 9 4
7 10 3
8 10 5
8 11 6
9 12 4
10 12 2
11 12 5
*/
}
