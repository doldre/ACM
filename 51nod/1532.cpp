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
#include <bitset>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
#define xx first
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
template<class T> inline T lowbit(T x) { return x & (-x); }

const int MAXM = 2e6 + 5, MAXN = 500 + 5;
char str[MAXM];
int n;
char words[MAXN][63];
int len[MAXN];

bitset<MAXN> masks[250];
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    gets(str);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &len[i]);
        scanf("%s", words[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < len[i]; j++) {
            masks[(int)words[i][j]][i] = 1;
        }
    }
    int m = strlen(str);
    bitset<MAXN> B;
    vector<int> ans;
    for (int i = 0; i < m; i++) {
        B <<= 1;
        B[0] = 1;
        B &= masks[(int)str[i]];
        if(B[n - 1]) ans.push_back(i - n + 2);
    }
    if(ans.size() == 0) {
        puts("NULL");
    } else {
        for (auto x: ans) {
            printf("%d\n", x);
        } 
    }
    return 0;
}

