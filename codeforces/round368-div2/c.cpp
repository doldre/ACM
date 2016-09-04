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

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    ll n;
    cin >> n;
    if(n <= 2) puts("-1");
    else {
        ll a, b;
        if(n & 1) {
            a = (n * n - 1) / 2, b = (n * n + 1) / 2;
        } else {
            a = n * n / 4 - 1, b = n * n / 4 + 1;
        }
        cout << a << " " << b << endl;
    }
    return 0;
}

