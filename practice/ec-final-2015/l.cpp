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

int toint(char s[]) {
    int len = strlen(s);
    int res = 0;
    for (int i = 0; i < len; i++) {
        res = res * 10 + s[i] - '0';
    }
    return res;
}

const int MAXN = 1e3 + 5;
struct Node {
    int x, r, c;
    Node() {}
    Node(int x, int r, int c):x(x), r(r), c(c) {}
};
int A[MAXN];
int R, C;
char str[MAXN];
vector<Node> V;

bool dfs(int i, int dr, int dc) {
    if(i >= (int)V.size()) return true;
    Node cur = V[i];
    if(cur.x == (cur.r + dr) * (cur.c + dc)) {
        return dfs(i + 1, dr, dc);
    } else return false;
}

int main(void) {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        V.clear();
        scanf("%d%d", &R, &C);
        bool ok = true;
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                scanf("%s", str);
                if(str[0] == '?') A[j] = -1;
                else A[j] = toint(str);
            }
            int last = -1, cnt = 0, c = -1, first = -1;
            for (int j = 1; j <= C; j++) {
                cnt++;
                if(A[j] != -1) {
                    if(first == -1) {
                        first = A[j];
                        V.push_back(Node(A[j], i, j));
                    }
                    if(last != -1) {
                        int t = A[j] - last;
                        if(t % cnt != 0) ok = false;
                        if(c != -1) {
                            if(t / cnt != c) ok = false;
                        }
                        c = t / cnt;
                    }
                    last = A[j];
                    cnt = 0;
                }
            }
        }
        if(ok) {
            bool flag = false;
            if((int)V.size() > 0) {
                int x = V[0].x, r = V[0].r, c = V[0].c;
                for (int i = 1; i * i <= x; i++) {
                    if(x % i == 0) {
                        int j = x / i;
                        if(i >= r && j >= c) {
                            flag |= dfs(0, i - r, j - c);
                        }
                        if(j >= r && i >= c) {
                            flag |= dfs(0, j - r, i - c);
                        }
                    }
                    if(flag) break;
                }
            } else flag = true;
            if(!flag) ok = false;
        }
        printf("Case #%d: ", Cas);
        if(ok) puts("Yes");
        else puts("No");
    }
    return 0;
}

