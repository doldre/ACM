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
const double eps = 1e-9;
const int maxn = 1e5 + 5;
struct Node {
    int v, w, num;
    double x;
    Node() {}
}A[maxn];

bool cmp(const Node &a, const Node &b) {
    return a.x > b.x;
}

int n, k;
bool judge(double x) {
    for (int i = 0; i < n; i++) {
        A[i].x = A[i].v - x * A[i].w;
    }
    sort(A, A + n, cmp);
    double res = 0;
    for (int i = 0; i < k; i++) {
        res += A[i].x;
    }
    return res >= 0;
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while(scanf("%d%d", &n, &k) == 2) {
        double l = 0, r = 1e9;
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &A[i].v, &A[i].w);
            A[i].num = i;
        }
        while(r - l > eps) {
            double m = (l + r) / 2;
            if(judge(m)) {
                l = m + eps;
            } else {
                r = m - eps;
            }
        }
        judge(l);
        for (int i = 0; i < k; i++) {
            printf("%d%c", A[i].num + 1, i == k - 1 ? '\n' : ' ');
        }
    }
    return 0;
}

