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

int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n, h;
    cin >> n >> h;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x > h) ans += 2;
        else ans += 1;
    }
    cout << ans << endl;
    return 0;
}