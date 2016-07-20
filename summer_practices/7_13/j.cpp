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
const int maxn = 1000 + 5;
int used[2][maxn];
int n;
bool dfs(int d) {
    if(d < 0) {
        return true;
    }
    for (int i = 1; i <= n; i++) {
        if(!used[0][i]) {
            if(i + d <= n && !used[1][i+d]) {
                used[0][i] = i + d;
                used[1][i+d] = i;
                if(dfs(d - 1)) {
                    return true;
                } else {
                    used[0][i] = 0;
                    used[1][i+d] = 0;
                }
            }
            if(i - d >= 1 && !used[1][i-d]) {
                used[0][i] = i - d;
                used[1][i-d] = i;
                if(dfs(d - 1)) {
                    return true;
                } else {
                    used[0][i] = 0;
                    used[1][i-d] = 0;
                }
            }
        }
    }
    return false;
}


void work(int x) {
    n = x;
    printf("{\n");
    if(n % 4 == 2 || n % 4 == 3) {
        printf("0,\n");
    } else {
        memset(used, 0, sizeof(used));
        bool suc = dfs(n - 1);
        prln(suc);
        for (int i = 1; i <= n; i++) {
            printf("%d,\n", used[0][i]);
        }
    }
    printf("-1\n},\n");
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    for (int i = 1; i <= 1000; i++) {
        work(i);
    }
    return 0;
}

