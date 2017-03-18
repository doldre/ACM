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
int A[MAXN];
double P[MAXN];
int n;
const double eps = 1e-9;
const double C = 0.19;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%lf", &P[i]);
        }
        set<pair<double, int> > st;
        st.insert(make_pair(1, 0));
        for (int i = 1; i <= n; i++) {
            double t = C / (1 - P[i]) + eps;
            auto it = st.upper_bound(make_pair(t, 0));
            vector<pair<double, int> > vec;
            for (; it != st.end(); it++) {
                vec.push_back(make_pair(it->first * (1 - P[i]), it->second + A[i]));
            }
            for (auto x: vec) {
                st.insert(x);
            }
            int tmp = 0;
            for (auto it = --st.end(); it != st.begin();) {
                if(it->second < tmp) it = st.erase(it);
                else tmp = it->second, --it;
            }
        }
        int ans = 0;
        for (auto x: st) {
            ans = max(ans, x.second);
        }
        cout << ans << endl;
    }
    return 0;
}

