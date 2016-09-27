/************************************************
 *Author        :mathon
 *Email         :luoxinchen96@gmail.com
*************************************************/
#include <cstdio>
#include <cctype>
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

const int MAXN = 1e6 + 5000;
const int AC_SIGMA = 26, AC_N = MAXN;
int flag[MAXN];
int n;
struct AC_automaton {
    int next[AC_N][AC_SIGMA], fail[AC_N], length[AC_N];
    int root, L;
    int newnode() {
        for (int i = 0; i < AC_SIGMA; i++) {
            next[L][i] = -1;
        }
        fail[L] = 0;
        length[L] = 0;
        return L++;
    }

    void init() {
        L = 0;
        root = newnode();
    }

    void insert(char buf[]) {
        int len = 0;
        while(buf[len] >= 'a' && buf[len] <= 'z') len++;
        int now = root;
        for (int i = 0; i < len; i++) {
            if(next[now][buf[i] - 'a'] == -1) {
                next[now][buf[i] - 'a'] = newnode();
            }
            now = next[now][buf[i] - 'a'];
        }
        length[now] = len;
    }

    void build() {
        queue<int> Q;
        fail[root] = root;
        for (int i = 0; i < AC_SIGMA; i++) {
            if(next[root][i] == -1) {
                next[root][i] = root;
            } else {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        }
        while(!Q.empty()) {
            int now = Q.front();
            Q.pop();
            for (int i = 0; i < 26; i++) {
                if(next[now][i] == -1) {
                    next[now][i] = next[fail[now]][i];
                } else {
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
            }
        }
    }

    int querry(char buf[]) {
        int len = strlen(buf);
        int now = root;
        int res = 0;
        for (int i = 0; i < len; i++) {
            if(buf[i] >= 'a' && buf[i] <= 'z') now = next[now][buf[i] - 'a'];
            else now = root;
            if(length[now] > 0) {
                flag[i - length[now] + 1]++;
                flag[i+1]--;
            }
        }
        return res;
    }
}ac;

char buf[MAXN];
char src[MAXN], str[MAXN];

int main(void) {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        memset(flag, 0, sizeof(flag));
        scanf("%d", &n);
        gets(buf);
        ac.init();
        for (int i = 0; i < n; i++) {
            gets(buf);
            ac.insert(buf);
        }
        ac.build();
        gets(src);
        int len = strlen(src);
        for (int i = 0; i < len; i++) {
            if(src[i] >= 'A' && src[i] <= 'Z') {
                str[i] = src[i] - 'A' + 'a';
            } else str[i] = src[i];
            // str[i] = tolower(src[i]);
        }
        ac.querry(str);
        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum += flag[i];
            if(sum > 0) {
                src[i] = '*';
            }
        }
        puts(src);
    }
    return 0;
}

