/************************************************
 *Author        :mathon
 *Created Time  :四  4/21 20:18:36 2016
 *Problem class:
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
vector<int> vi;
#define xx first
#define yy second
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++)
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl

const int maxn = 1000;
ll stoi(char *s) {
    int len = strlen(s);
    ll res = 0;
    for (int i = 0; i < len; i++) {
        res = res * 10 + s[i] - '0';
    }
    return res;
}

char str[maxn];
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    while(T--) {
        cin >> str;
        int len = strlen(str + 4);
        ll x = stoi(str + 4);
        ll F = 0, tenpow = 10;
        for (int i = 0; i < len - 1; i++) {
            F += tenpow;
            tenpow *= 10;
        }
        while(x < 1989 + F) x += tenpow;
        cout << x << endl;
    }
    return 0;
}
