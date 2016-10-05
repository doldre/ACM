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

const int MAXN = 100 + 5;
const char vowels[] = "aeiouy";
char str[MAXN];
int n;
int P[MAXN];

bool check(char ch) {
    for (int i = 0; i < 6; i++) {
        if (ch == vowels[i]) return true;
    }
    return false;
}

int count(char s[]) {
    int len = strlen(s);
    int ans = 0;
    for (int i = 0; i < len; i++) {
        ans += check(s[i]);
    }
    return ans;
}

int main(void) {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &P[i]);
    }
    gets(str);
    bool ok = true;
    for (int i = 0; i < n; i++) {
        gets(str);
        if(count(str) != P[i]) {
            ok = false;
        }
    }
    if(ok) puts("YES");
    else puts("NO");
    return 0;
}
