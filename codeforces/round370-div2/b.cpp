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

const int MAXN = 1e5 + 5;
char str[MAXN];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%s", str);
    int len = strlen(str);
    if(len % 2) {
        printf("-1\n");
    } else {
        map<char, int> cnt;
        for (int i = 0; i < len; i++) {
            cnt[str[i]]++;
        }
        int d1 = abs(cnt['U'] - cnt['D']);
        int d2 = abs(cnt['R'] - cnt['L']);
        printf("%d\n", (d1 + d2) / 2);
    }
    return 0;
}

