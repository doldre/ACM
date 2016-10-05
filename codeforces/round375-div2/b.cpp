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
#include <cctype>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
#define xx first
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
template<class T> inline T lowbit(T x) { return x & (-x); }

const int MAXN = 1000 + 5;
char str[MAXN];
int n;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    scanf("%s", str);
    int a = 0, b = 0;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if(str[i] == '_') continue;
        else if(str[i] == '(') flag = true;
        else if(str[i] == ')') flag = false;
        else {
            int t = 0;
            int j;
            for (j = i; j < n; j++) {
                if(isalpha(str[j])) {
                    t++;
                } else break;
            }
            if(!flag) a = max(a, t);
            else b++;
            i = j - 1;
        }
    }
    printf("%d %d\n", a, b);
    return 0;
}

