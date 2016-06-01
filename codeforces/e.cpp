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
#define sa(n) scanf("%d", &(n))
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 100000 + 5;
const int inf = 0x3f3f3f3f;
int A[maxn];
int n, k;
char str[maxn];
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int cnt_quote = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0; i <= n; i++) {
        scanf("%s", str);
        if(str[0] == '?') {
            A[i] = inf;
            cnt_quote++;
        }
        sscanf(str, "%d", &A[i]);
    }
    bool ok = true;
    if(k == 0) {
        if(A[0] == 0) {
            ok = true;
        } else if(A[0] == inf) {
            if((n + 1 - cnt_quote) % 2 == 0) {
                ok = false;
            } else {
                ok = true;
            }
        } else {
            ok = false;
        }
    } else {
        if(cnt_quote > 0) {
            if((n + 1) % 2 == 0) {
                ok = true;
            } else ok = false;
        } else {
            int b = 0;
            for (int i = 0; i < n; i++) {
                if((A[i] - b) % k != 0) ok = false;
                b = (A[i] - b) / (-k);
            }
            if(A[n] - b != 0) ok = false;
        }
    }
    if(ok) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
