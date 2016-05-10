/************************************************
 *Author        :mathon
 *Created Time  :日  5/ 8 17:48:40 2016
 *Problem class:
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
#define lowbit(x) (x&-x)
#define yy second
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++)
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl

const int maxn = 100 + 5;
int mat[maxn][maxn];
int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T;
    sa(T);
    for (int Cas = 1; Cas <= T; Cas++) {
        ll B, M;
        cin >> B >> M;
        memset(mat, 0, sizeof(mat));
        for (int i = 1; i < B - 1; i++) {
            for (int j = i + 1; j <= B - 1; j++) {
                mat[i][j] = 1;
            }
        }
        printf("Case #%d: ", Cas);
        if(M > (1ll << (B - 2))) {
            printf("IMPOSSIBLE\n");
        } else {
            int t = 2;
            ll m = M;
            if(M == (1ll << (B - 2))) {
                for (int i = 1; i < B; i++) {
                    mat[i][B] = 1;
                }
            }
            else {
                while(m > 0) {
                    if(m & 1) {
                        mat[t][B] = 1;
                    }
                    t++;
                    m >>= 1;
                }
            }
            printf("POSSIBLE\n");
            for (int i = 1; i <= B; i++) {
                for (int j = 1; j <= B; j++) {
                    printf("%d", mat[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
