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

const int MAXN = 50 + 5;
int A[MAXN], n;
bool L[MAXN][MAXN][MAXN][100]; 
// L[i][j][k][l] 不选i，前j个数，选k个，l能否凑出
bool R[MAXN][MAXN][MAXN][100];

void DP() {
    for (int i = 1; i <= n; i++) {
        memset(L[i][0], 0, sizeof(L[i][0]));
        L[i][0][0][0] = 1;
        for (int j = 1; j <= n; j++) {
            for (int k = 10; k >= 0; k--) {
                for (int l = 87; l >= 0; l--) {
                    L[i][j][k][l] = L[i][j-1][k][l];
                }
            }
            if(j == i) {
                continue;
            }
            for (int k = 10; k > 0; k--) {
                for (int l = 87; l >= A[j]; l--) {
                    L[i][j][k][l] |= L[i][j-1][k-1][l-A[j]];
                }
            }
        }
    }
    for (int i = n; i >= 1; i--) {
        memset(R[i][n+1], 0, sizeof(R[i][n+1]));
        R[i][n+1][0][0] = 1;
        for (int j = n; j >= 1; j--) {
            for (int k = 10; k >= 0; k--) {
                for (int l = 87; l >= 0; l--) {
                    R[i][j][k][l] = R[i][j+1][k][l];
                }
            }
            if(j == i) {
                continue;
            }
            for (int k = 10; k > 0; k--) {
                for (int l = 87; l >= A[j]; l--) {
                    R[i][j][k][l] |= R[i][j+1][k-1][l-A[j]];
                }
            }
        }
    }
}

        

int main() {
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
        }
        DP();
        int Q; scanf("%d", &Q);
        while(Q--) {
            int x[3];
            scanf("%d%d%d", &x[0], &x[1], &x[2]);
            sort(x, x + 3);
            bool ans = false;
            for (int i = 0; i <= 10; i++) {
                for (int j = 0; j <= 87; j++) {
                    ans |= L[x[0]][x[1]-1][i][j] && R[x[2]][x[1]+1][10-i][87-j];
                    if(ans) break;
                }
            }
            if(ans) printf("Yes\n");
            else printf("No\n");
        }
    }
}
