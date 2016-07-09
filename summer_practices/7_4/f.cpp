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
const int maxn = 1e5 + 7;
const int maxy = 100 + 5;
int sta[maxy][maxn];
int pos[maxy];
pii task[maxn];
int N, M;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(scanf("%d%d", &N, &M) == 2) {
        memset(pos, 0, sizeof(pos));
        for (int i = 0; i < N; i++) {
            int x, y; scanf("%d%d", &x, &y);
            sta[y][pos[y]++] = x;
        }
        
        for (int i = 0; i < M; i++) {
            int x, y; scanf("%d%d", &x, &y);
            task[i] = pii(x, y);
        }
        for (int i = 0; i < maxy; i++) {
            sort(sta[i], sta[i] + pos[i]);
        }
        sort(task, task + M, greater<pii>() );

        ll num = 0, money = 0;
        for (int i = 0; i < M; i++) {
            int x = task[i].xx, y = task[i].yy;
            for (int j = y; j <= 100; j++) {
                if(pos[j] > 0 && sta[j][pos[j] - 1] >= x) {
                    num++;
                    money += x * 500 + 2 * y;
                    pos[j]--;
                    break;
                }
            }
        }
        cout << num << " " << money << endl;
    }
    return 0;
}

