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
const int MAXN = 800 + 5;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
char mp[MAXN][MAXN];
int dp[MAXN][MAXN];
bool inque[MAXN][MAXN];
typedef pair<int, pii> Node;
int n, m;

bool inside(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

void solve() {
  queue<Node> que;
  memset(dp, 0x3f, sizeof(dp));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if(mp[i][j] == '0') {
        dp[i][j] = 0;
        que.push(Node(0, pii(i, j)));
        inque[i][j] = true;
      }
    }
  }
  
  while(!que.empty()) {
    Node cur = que.front(); que.pop();
    int d = cur.xx, x = cur.yy.xx, y = cur.yy.yy;
    inque[x][y] = false;
    for (int dir = 0; dir < 4; dir++) {
      int nx = x + dx[dir], ny = y + dy[dir];
      if(!inside(nx, ny)) continue;
      if (d + 1 < dp[nx][ny]) {
        dp[nx][ny] = d + 1;
        if (!inque[nx][ny]) {
          que.push(Node(dp[nx][ny], pii(nx, ny)));
          inque[nx][ny] = true;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", dp[i][j]);
    }
    puts("");
  }
} 

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", mp[i]);
  }
  solve();
    return 0;
}

