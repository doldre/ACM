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

string str;

ll convert(string s) {
    ll res = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        res = res * 10 + s[i] - '0';
    }
    return res;
}

ll solve1() {
    int len = (int)str.size();
    ll a = convert(str.substr(0, len - 4)),
           b = convert(str.substr(1, len - 4));
    ll pre = max(a + str[len-4] - '0', b + str[0] - '0');
    return pre - (int)(str[len-3] - '0') * (str[len-2] - '0') / 
        (str[len-1] - '0');
}

ll solve2() {
    int len = (int)str.size();
    ll a = convert(str.substr(0, len - 5)),
           b = convert(str.substr(1, len - 5));
    ll pre = max(a + str[len - 5] - '0', b + str[0] - '0');
    return pre - (int)(str[len-4] - '0') * (str[len-3] - '0') / 
        ((int)(str[len-2] - '0') * 10 + (str[len-1] - '0'));
}
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        cin >> str;
        ll ans = solve1();
        if(str.size() > 5) {
            ans = max(ans, solve2());
        }
        printf("Case #%d: %lld\n", Cas, ans);
    }
    return 0;
}
