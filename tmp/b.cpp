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
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
template<class T> inline T lowbit(T x) { return x & (-x); }
const int inf = 0x3f3f3f3f;
const int MAXN = 500 + 5;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int used[MAXN][MAXN];
struct Node {
    int x1, y1, x2, y2, c;
    Node () {
        x1 = y1 = inf;
        x2 = y2 = -1;
    }
    bool operator < (const Node &b) const {
        if (y1 != b.y1) return y1 < b.y1;
        else return x1 < b.x1;
    }
};

int N, M;
int mat[MAXN][MAXN];

void dfs(int x, int y, int c, Node &node) {
    if (used[x][y]) return;
    used[x][y] = c;
    node.x1 = min(node.x1, x);
    node.x2 = max(node.x2, x);
    node.y1 = min(node.y1, y);
    node.y2 = max(node.y2, y);
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir], ny = y + dy[dir];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (mat[nx][ny] == 1) dfs(nx, ny, c, node);
    }
}

void print(Node node) {
    int x1 = node.x1, y1 = node.y1, x2 = node.x2, y2 = node.y2, c = node.c;
    printf("%d %d\n", (x2 - x1 + 1), (y2 - y1 + 1));
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            if (used[i][j] == c) printf("1");
            else printf("0");
        }
        printf("\n");
    }
}

char str[MAXN];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%s", str);
        for (int j = 0; j < M; j++) {
            mat[i][j] = str[j] - '0';
        }
    }
    memset(used, 0, sizeof(used));
    int color = 0;
    vector<Node> res;
    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++) {
            if (!used[i][j] && mat[i][j] == 1) {
                Node node;
                node.c = ++color;
                dfs(i, j, color, node);
                res.push_back(node);
            }
        }
    }
    for (Node node: res) {
        print(node);
    }
    return 0;
}

