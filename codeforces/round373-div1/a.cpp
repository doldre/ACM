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
const int MAXN = 2e5 + 5;
char str[MAXN];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n, t;
    scanf("%d%d", &n, &t);
    scanf("%s", str);
    int p = 0;
    while(str[p] != '.') p++;
    int dot = p;
    if(p < n) p++;
    while(str[p] < '5' && p < n) p++;
    if(p < n) {
        for (int i = p + 1; i < n; i++) str[i] = '\0';
        for (int i = p; str[i] != '.' && t > 0 && i >= 0; i--, t--) {
            if(str[i] >= '5') {
                str[i] = '\0';
                if(str[i-1] == '.') {
                    str[i-1] = '\0';
                    str[i-2]++;
                    break;
                } else {
                    str[i-1]++;
                }
            } else break;
        }
    }
    for (int i = dot - 1; i >= 0; i--) {
        if(str[i] == '9' + 1) {
            str[i] = '0';
            if(i - 1 >= 0) {
                str[i-1]++;
            } else {
                printf("1");
                break;
            }
        } else break;
    }
    puts(str); 
    return 0;
}

