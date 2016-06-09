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
int board[maxn][maxn], id[maxn];
int n, m;
struct DanceLink {
    struct Node {
        int left, right, up, down, x, y;
        Node() {}
        Node(int left, int right, int up, int down, int x, int y):
            left(left), right(right), up(up), down(down), x(x), y(y) {}
    }nds[maxn*maxn];

    int column_head[maxn];
    void build() {
        int head = 0;
        nds[head] = Node(head, head, head, head, 0, 0);
        for (int i = 1; i <= m; i++) column_head[i] = i;
        int pre = head;
        for (int i = 1; i <= m; i++) {
            int p = column_head[i];
            nds[p].up = p, nds[p].down = p;
            nds[p].x = 0, nds[p].y = i;
            nds[p].right = nds[pre].right;
            nds[p].left = pre;
            nds[nds[p].right].left = p;
            nds[pre].right = p;
            pre = p;
        }
    }
}dance_link;
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    return 0;
}
