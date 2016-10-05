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

int _minus(char a[], int n, char b[], int m) {
    int flag = 0;
    for (int i = 0; i < n; i++) {
        int c = flag + a[i];
        flag = 0;
        if(i < m) c -= b[i];
        if(c < 0) {
            c += 10; flag = -1;
        }
        a[i] = c;
    }
    int i;
    for (i = n - 1; i >= 0 && a[i] == 0; i--);
    return i + 1;
}

const int MAXN = 1e3 + 5;
int construct(char buf[], char str[], int len) {
    memcpy(buf, str, MAXN * sizeof(char));
    if(len >= 2) {
        int flag = -1;
        for (int i = len / 2; i < len; i++) {
            int c = buf[i] + flag;
            flag = 0;
            if(c < 0) {
                c += 10;
                flag = -1;
            }
            buf[i] = c;
        }
    }
    int i;
    for (i = len - 1; i >= 0 && buf[i] == 0; i--);
    i++;
    int n = i;
    if(n == 0) {
        buf[0] = 1;
        n = 1;
    }
    for (int i = (n - 1) / 2, j = n / 2; i >= 0; i--, j++) {
        buf[i] = buf[j];
    }
    return n;
}
char str[MAXN], buf[MAXN];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        memset(str, 0, sizeof(str));
        scanf("%s", str);
        printf("Case #%d:\n", Cas);
        int len = strlen(str);
        for (int i = 0 ; i < len; i++) {
            str[i] = str[i] - '0';
        }
        reverse(str, str + len);
        vector<string> ans;
        while(len > 0) {
            memset(buf, 0, sizeof(buf));
            int m = construct(buf, str, len);
            // prln(m);
            len = _minus(str, len, buf, len);
            // prln(len);
            // for (int i = len - 1; i >= 0; i--) {
                // printf("%d", str[i]);
            // }
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

