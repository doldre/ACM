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
#define lowbit(x) (x&-x)
#define yy second
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int maxn = 10;
int A[maxn];
int n;
bool judge(int s) {
    // pr(s);
    int dx = (s - 1) / 3 - (A[0] - 1) / 3;
    int dy = (s - 1) % 3 - (A[0] - 1) % 3;
    // pr(dx); prln(dy);
    for (int i = 0; i < n; i++) {
        int x = (A[i] -1) / 3, y = (A[i] - 1) % 3;
        if(x + dx > 3 || x + dx < 0 ||
           y + dy > 2 || y + dy < 0 ||
           (x + dx == 3 && y + dy == 0) ||
           (x + dx == 3 && y + dy == 2)) {
            return false;
        }
    }
    return true;
}

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char ch;
        cin >> ch;
        A[i] = ch - '0';
        if(A[i] == 0) A[i] = 11;
    }
    
    bool ok = true;
    for (int s =1; s <= 11; s++) {
        if(s == A[0] || s == 10) continue;
        if(judge(s)) {
            ok = false;
            break;
        }
    }
    if(ok) printf("YES\n");
    else printf("NO\n");
    return 0;
}

