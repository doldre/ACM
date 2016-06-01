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
int A[maxn];
char str[maxn];
const int inf = 0x3f3f3f3f;
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    memset(A, 0x3f, sizeof(A));
    for (int i = 0; i <= n; i++) {
        scanf("%s", str);
        if(str[0] == '?') {
            cnt++;
            continue;
        }
        sscanf(str, "%d", &A[i]);
    }
    if(k == 0) {
        if(A[0] == 0) {
            printf("Yes\n");
            return 0;
        } else if (A[0] != inf){
            printf("No\n");
            return 0;
        }
    }
    if(cnt > 0) {
        if(A[0] == inf && k == 0) {
            if((n - cnt) % 2 == 0) {
                printf("Yes\n");
                return 0;
            } else {
                printf("No\n");
                return 0;
            }
        }
    }
    if(cnt > 0 && n % 2 == 0) {
        printf("No\n");
    } else if(cnt > 0 && n % 2 == 1){
        if(A[0] == inf && k == 0) {
            if((n - cnt) % 2 == 1) {
                printf("Yes\n");
                return 0;
            } else {
                printf("No\n");
                return 0;
            }
        }
        printf("Yes\n");
    } else if(cnt == 0) {
        bool ok = true;
        if(k != 0) {
            double b = double(A[0]) / (-k);
            for (int i = 1; i <= n - 1; i++) {
                b = (A[i] - b) / (-k);
            }
            if(abs(b - A[n]) > 1e-9) ok = false;
        } else if(k == 0){
            if(A[0] != 0) {
                ok = false;
            }
            int t = false;
            for (int i = 0; i <= n; i++) {
                if(A[i] != 0) t = true;
            }
            if(!t) ok = false;
        }
        if(ok) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
