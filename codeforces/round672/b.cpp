
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

const int maxn = 1e5 + 5;
char str[maxn];

int cnt[30];
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n;
    sa(n);
    scanf("%s", str);
    if(n > 26) {
        printf("-1\n");
    } else {
        for (int i = 0; i < n; i++) {
            cnt[str[i] - 'a']++;
        }
        int res = 0;
        for (int i = 0; i < 26; i++) {
            res += max(cnt[i] - 1, 0);
        }
        printf("%d\n", res);
    }
    return 0;
}
