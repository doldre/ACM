/************************************************
 *Author        :mathon
 *Created Time  :2016年05月04日 星期三 14时30分33秒
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
const int mod = int(1e9) + 7, INF = 0x3f3f3f3f, maxn = 1e5 + 12;
int n;
int node[20][2], cnt;
int  tri[maxn][3];

bool ok(int i, int j, int k) {
    int ax, ay, bx, by;
    ax = node[j][0] - node[i][0];
    ay = node[j][1] - node[i][1];
    bx = node[k][0] - node[i][0];
    by = node[k][1] - node[i][1];
    return !(ax * by == ay * bx);
}

int  dis(int i, int j) {
    return (node[i][0] - node[j][0]) * (node[i][0] - node[j][0]) + (node[i][1] - node[j][1]) * (node[i][1] - node[j][1]);
}
bool judge(int i, int j)
{
    int  A[3], B[3];
    A[0] = dis(tri[i][0], tri[i][1]), A[1] = dis(tri[i][0], tri[i][2]), A[2] = dis(tri[i][1], tri[i][2]);
    i = j;
    B[0] = dis(tri[i][0], tri[i][1]), B[1] = dis(tri[i][0], tri[i][2]), B[2] = dis(tri[i][1], tri[i][2]);
    sort(A, A + 3); sort(B, B + 3);
    return (A[0] * B[1] == A[1] * B[0]) && (A[1] * B[2] == B[1] * A[2]);
}

    


int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while (sa(n), n) {
        cnt = 0;
        int nn = n;
        n = 0;
        rep (i, 0, nn) {
            int t1, t2; sa(t1), sa(t2);
            bool ok = false;
            rep (j, 0, n) {
                if (node[j][0] == t1 && node[j][1] == t2) ok = true;
            }
            if (!ok) {
                node[n][0] = t1, node[n][1] = t2;
                n++;
            } 
        }
        rep (i, 0, n) {
            rep (j, i + 1, n) {
                rep (k, j + 1, n) {
                    if (ok(i, j, k)) {
                        tri[cnt][0] = i, tri[cnt][1] = j, tri[cnt][2] = k;
                        cnt++;
                    }
                }
            }
        }
        int ans = 0, temp ;
        rep (i, 0, cnt) {
            temp = 0;
            rep (j, 0, cnt) {
                if (judge(i, j)) temp++;
            }
            ans = max(ans, temp);
        }
        printf("%d\n", ans);
    }
    return 0;
} 





    
