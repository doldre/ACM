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
const int maxn = 20 + 5;
double P[maxn];
double not_cache[maxn];
int n, k;
int A[maxn], cnt;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &P[i]);
    }
    for (int mask = 0; mask < (1<<n); mask++) {
        if(__builtin_popcount(mask) == k) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if((mask >> i) & 1) {
                    A[cnt++] = i;
                }
            }
            double base = 1 / ((double)pow(2.0, k) * k);
            for (int i = 0; i < k; i++) {
                int a = A[i];
                not_cache[a] += base * P[a];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%.9f ", 1 - not_cache[i]);
    }
    return 0;
}

