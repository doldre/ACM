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
    int T; scanf("%d", &T);
    while(T--) {
        int n; scanf("%d", &n);
        scanf("%s", str);
        stack<char> sta;
        for (int i = 0; i < n; i++) {
            char c = str[i];
            if(c == ')' && !sta.empty() && sta.top() == '(') {
                sta.pop();
            } else {
                sta.push(c);
            }
        }
        if(sta.size() == 2) {
            char a = sta.top(); sta.pop();
            char b = sta.top(); sta.pop();
            if(a != b) {
                puts("Yes");
                continue;
            }
        }
        if(sta.size() == 4) {
            char buf[4];
            for (int i = 0; i < 4; i++) {
                buf[i] = sta.top();
                sta.pop();
            }
            if(buf[0] == buf[1] && buf[0] == '(') {
                if(buf[2] == buf[3] && buf[2] == ')') {
                    puts("Yes");
                    continue;
                }
            }
        }
        if(sta.size() == 0 && n != 2) {
            puts("Yes"); continue;
        }
        puts("No");
    }
    return 0;
}

