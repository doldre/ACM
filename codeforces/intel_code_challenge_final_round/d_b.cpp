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
vector<int> v[27];
int m;
char p[MAXN], cnt;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &m);
    scanf("%s", str + 1);
    int len = strlen(str + 1);
    for (int i = 1; i <= len; i++) {
        v[str[i] - 'a'].push_back(i);
    }
    set<int> st;
    for (int i = 0; i <= 26; i++) {
        for (int j = 0; j < (int)v[i].size(); j++) {
            st.insert(v[i][j]);
            // prln(v[i][j]);
            break;
        }
        if(st.size() > 0) break;
    }
    st.insert(0); st.insert(len+1);
    char c = 'a';
    for (int i = 0; i <= 26; i++) {
        for (int j = 0; j < (int)v[i].size(); j++) {
            int x = v[i][j];
            auto p = st.upper_bound(x);
            int p1 = *p, p2 = *--p;
            if(p1 - p2 > m) {
                // prln(x);
                st.insert(x);
                c = max(c, str[x]);
            }
            p = st.lower_bound(x);
            p1 = *--p;
            p2 = 0;
            if(p != st.begin()) p2 = *--p;
            if((p1 != 0 && str[x] == str[p1]) && x - p2 <= m) {
                // prln(x);
                st.insert(x);
                c = max(c, str[x]);
                if(p1 != 0) st.erase(p1);
            }
        }
    }
    string ans;
    for (int i = 1; i <= len; i++) {
        if(str[i] < c) st.insert(i);
    }
    for (auto x: st) {
        // prln(x);
        if(x != 0 && x != len + 1) {
            ans.push_back(str[x]);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}
