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
const int maxn = 500 + 5;
int subset[maxn][maxn];
int sum[maxn];
int C[maxn];
int n, K;

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &C[i]);
    }
    sum[0] = 1, subset[0][0] = 1; 
    for (int i = 1; i <= n; i++) {
        int c = C[i];
        for (int j = K; j >= c; j--) {
            if(sum[j-c]) {
                sum[j] = 1;
                for (int k = 0; k <= j - c; k++) {
                    if(subset[j-c][k]) {
                        subset[j][k] = 1;
                        subset[j][k+c] = 1;
                    }
                }
            }
        }
    }
    vector<int> ans;
    for (int i = 0; i <= K; i++) {
        if(subset[K][i]) {
            ans.push_back(i);
        }
    }
    printf("%d\n", (int)ans.size());
    for (auto x: ans) {
        printf("%d ", x);
    }
    return 0;
}

