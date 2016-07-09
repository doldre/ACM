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
double X1[maxn], Y1[maxn], X2[maxn], Y2[maxn];
int cnt_vx, cnt_vy;
double Vx[2*maxn];
double Vy[2*maxn];
int get_xid(double x) {
    return lower_bound(Vx, Vx + cnt_vx, x) - Vx;
}

int get_yid(double y) {
    return lower_bound(Vy, Vy + cnt_vy, y) - Vy;
}

int N;
short mt[2*maxn][2*maxn];

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &N);
        cnt_vx = cnt_vy = 0;
        for (int i = 0; i < N; i++) {
            scanf("%lf%lf%lf%lf", &X1[i], &Y1[i], &X2[i], &Y2[i]);
            Vx[cnt_vx++] = X1[i];
            Vy[cnt_vy++] = Y1[i];
            Vx[cnt_vx++] = X2[i];
            Vy[cnt_vy++] = Y2[i];
        }
        sort(Vx, Vx + cnt_vx);
        sort(Vy, Vy + cnt_vy);
        memset(mt, 0, sizeof(mt));
        for (int i = 0; i < N; i++) {
            double x1 = X1[i], y1 = Y1[i], x2 = X2[i], y2 = Y2[i];
            int idx1 = get_xid(x1);
            int idy1 = get_yid(y1);
            int idx2 = get_xid(x2);
            int idy2 = get_yid(y2);
            mt[idx1+1][idy1+1]++;
            mt[idx2+1][idy1+1]--;
            mt[idx1+1][idy2+1]--;
            mt[idx2+1][idy2+1]++;
        }
        double ans = 0;
        for (int i = 0; i < cnt_vx; i++) {
            int t = 0;
            for (int j = 0; j < cnt_vy; j++) {
                t += mt[i][j];
                mt[i][j] = t;
                if(i > 0) mt[i][j] += mt[i-1][j];
                if(mt[i][j] > 1) {
                    ans += (Vx[i] - Vx[i-1]) * (Vy[j] - Vy[j-1]);
                }
            }
        }
        printf("%.2f\n", ans);
    }
    return 0;
}

