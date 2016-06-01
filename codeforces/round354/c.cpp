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
char str[maxn];
int n, k;
int solve(char c) {
    int ans = 0;
    int cnt = 0;
    for (int i = 0, j = 0; i < n; i++) {
        if(str[i] == c) {
            cnt++;
        }
        while(cnt > k) {
            if(str[j] == c) cnt--;
            j++;
        }
        /* pr(i); prln(j); */
        ans = max(ans, i - j + 1);
    }
    return ans;
}

int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &k);
    scanf("%s", str);
    int ans = 0;
    ans = max(solve('a'), solve('b'));
    cout << ans << endl;
    return 0;
}
