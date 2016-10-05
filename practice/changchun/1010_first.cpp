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

int _minus(char a[], int n, const char b[], int m) {
    int flag = 0;
    for (int i = 0; i < n; i++) {
        int c = a[i] + flag;
        flag = 0;
        if(i < m) c -= b[i];
        if(c < 0) c += 10, flag = -1;
        a[i] = c;
    }
    int i;
    for (i = n - 1; i >= 0 && a[i] == 0; i--);
    return i + 1;
}

int comp(char a[], int n, char b[], int m) {
    if(n < m) return -1;
    for (int i = n - 1; i >= 0; i--) {
        if(a[i] > b[i]) return 1;
        else if(a[i] < b[i]) return -1;
    }
    return 0;
}
const int MAXN = 1000 + 5;
int construct(char buf[], char str[], int n) {
    int m = (n + 1) / 2;
    memset(buf, 0, MAXN);
    for (int i = 0; i < m; i++) {
        buf[i] = str[n-i-1];
    }
    for (int i = 0; i < n / 2; i++) {
        buf[i+m] = buf[m-i-1-(n%2)];
    }
    reverse(buf, buf + n);
    if(comp(buf, n, str, n) == 1) {
        memset(buf, 0, MAXN);
        for (int i = 0; i < m; i++) {
            buf[i] = str[n-i-1];
        }
        reverse(buf, buf + m);
        int t = _minus(buf, m, "\1", 1);
        if(t < m) n--;
        m = (n + 1) / 2;
        reverse(buf, buf + t);
        if(t < m) buf[m-1] = buf[m-2];
        for (int i = 0; i < n / 2; i++) {
            buf[i+m] = buf[m-i-1-(n%2)];
        }
        reverse(buf, buf + n);
        // prln("fuck");
        // for (int i = 0; i < n; i++) printf("%d", buf[i]);
        // puts("");
        // prln("fuck");
    }
    bool flag = false;
    for (int i = n - 1; i >= 0; i--) if(buf[i] != 0) flag = true;
    if(!flag) {
        buf[0] = 9;
        return 1;
    }
    return n;
}

char str[MAXN];
char buf[MAXN], tmp[MAXN];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        scanf("%s", str);
        printf("Case #%d:\n", Cas);
        int len = strlen(str); 
        for (int i = 0; i < len; i++) {
            str[i] = str[i] - '0';
        }
        reverse(str, str + len);
        vector<string> ans;
        while(len > 0) {
            int m = construct(buf, str, len);
            len = _minus(str, len, buf, m);
            // pr(m); prln(len);
            // prln("str");
            // for (int i = len - 1; i >= 0; i--) printf("%d", str[i]);
            // puts("");
            string tmp;
            for (int i = m - 1; i >= 0; i--) {
                tmp.push_back(buf[i] + '0');
                // printf("%d", buf[i]);
            }
            ans.push_back(tmp);
            // puts("");
            // getchar();
        }
        printf("%d\n", (int)ans.size());
        for (int i = 0; i < (int)ans.size(); i++) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
