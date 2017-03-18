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

const int MAXN = 1000 + 5;

struct Node {
    int v, cnt;
}nds[50];

bool cmp(const Node &a, const Node &b) {
    if(a.cnt != b.cnt) return a.cnt > b.cnt;
    else {
        if(a.v == 7) return true;
        else return a.v < b.v;
    }
}

int cnt[50];

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 6; j++) {
                int x; scanf("%d", &x);
                cnt[x]++;
            }
        }
        for (int i = 1; i <= 49; i++) {
            nds[i].v = i;
            nds[i].cnt = cnt[i];
        }
        sort(nds + 1, nds + 50, cmp);
        vector<int> ans;
        for (int i = 1; i <= 6; i++) {
            ans.push_back(nds[i].v);
        }
        sort(ans.begin(), ans.end());
        for (auto x: ans) {
            printf("%d ", x);
        }
        puts("");
    }
    return 0;
}

