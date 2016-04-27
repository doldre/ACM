/************************************************
 *Author        :mathon
 *Created Time  :2016年04月20日 星期三 20时46分10秒
 ***********************************************/
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
vector<int> vi;
#define xx first
#define yy second
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int mod = int(1e9) + 7, INF = 0x3f3f3f3f, maxn = 1e5 + 12;

string itos(ll x) {
    string res;
    while(x > 0) {
        ll t = x % 10;
        res.push_back(t);
        x /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

ll stoi(string &str) {
    ll res = 0;
    for (int i = 0; i < (int)str.size(); i++) {
        res = res * 10 + str[i];
    }
    return res;
}
bool contain(ll s, ll t, ll x) {
    if(x > t) return false;
    if(s <= x) return true;
    string ss, sx;
    ss = itos(s);
    sx = itos(x);
    for(int i = ss.size() - sx.size(), j = 0; i < (int)ss.size(); i++, j++) {
        ss[i] = sx[j];
    }
    ll tmp = stoi(ss);
    if(tmp < s) {
        ss[sx.size()-1]++;
        tmp = stoi(ss);
    }
//    printf("s %lld t %lld x %lld tmp %lld\n", s, t, x, tmp);
    return tmp <= t;
}


int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    string str;
    scanf("%d", &T);
    getchar();
    while(T--) {
        ll x;
        for (int i = 0; i < 4; i++) getchar();
        cin >> str;
        getchar();
        x = stoi(str);
 /*jj       ll s = 1989;
        ll l = 1989, r = 1e10;
        while(r - l > 1) {
            ll m = (l + r) >> 1;
            cout << m << endl;
            if(contain(s, m, x)) {
                r = m;
            } else l = m;
        }
        cout << r << endl;
        */
        if(x >= 3000) cout << x << endl;
        if(str.size() == 1 && x >= 0 && x <= 8) cout << 1990 + x << endl;
        if(str.size() == 1 && x == 9) cout << 1989 << endl;
        if(str.size() == 2 && x == 99) cout << 1999 << endl;
        if(str.size() == 2 && x >= 0 && x <= 98) cout << 2000 + x << endl;
        if(str.size() == 3 && x == 99) cout << 2099 << endl;
        if(str.size() == 3 && x >= 100) cout << 2000 +  x << endl;
    }
    return 0;
}
