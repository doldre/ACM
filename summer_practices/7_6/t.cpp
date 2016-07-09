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
const int maxn = 200;
struct Block {
    int x, y, z;
    Block(int x, int y, int z):x(x), y(y), z(z) {}
    Block() {}
    bool operator < (const Block &b) const {
        return x < b.x || (x == b.x && y < b.y) ||
            (x == b.x && y == b.y && z < b.z);
    }
    bool greater(const Block &b) const {
        return x > b.x && y > b.y;
    }
}blocks[maxn];

int dp[maxn];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n;
    int Cas = 0;
    while(scanf("%d", &n) == 1 && n) {
        int cnt = 0;
        blocks[cnt++] = Block(0, 0, 0);
        for (int i = 0; i < n; i++) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            blocks[cnt++] = Block(x, y, z);
            blocks[cnt++] = Block(x, z, y);
            blocks[cnt++] = Block(y, x, z);
            blocks[cnt++] = Block(y, z, x);
            blocks[cnt++] = Block(z, x, y);
            blocks[cnt++] = Block(z, y, x);
        }
        sort(blocks, blocks + cnt);
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        for (int i = 0; i < cnt; i++) {
            for (int j = 0; j < i; j++) {
                if(blocks[i].greater(blocks[j])) {
                    dp[i] = max(dp[i], dp[j] + blocks[i].z);
                    ans = max(ans, dp[i]);
                }
            }
        }
        printf("Case %d: maximum height = %d\n", ++Cas, ans);
    }
    return 0;
}

