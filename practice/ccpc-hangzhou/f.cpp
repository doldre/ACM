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

ll cal_left(string s) {
    int len = s.size();
    ll a = convert(s.substr(0, len - 1)) + s[len-1] - '0';
    ll b = convert(s.substr(1, len - 1)) + s[0] - '0';
    return max(a, b);
}

ll cal_right(string s) {
    int len = s.size();
    ll a = (s[0] - '0') * (s[1] - '0');
    return a / convert(s.substr(2, len - 2));
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        cin >> str;
        int len = str.size();
        ll ans = -1e17;
        for (int i = 2; i <= len - 3; i++) {
            ans = max(ans, cal_left(str.substr(0, i)) -
                    cal_right(str.substr(i, len - i)));
        }
        printf("Case #%d: %lld\n", Cas, ans);
    }
    return 0;
}

