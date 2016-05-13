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
#define sa(n) scanf("%d", &(n))
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl

string itos(int x) {
    string res;
    while(x > 0) {
        res.push_back(x % 10 + '0');
        x /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    string str;
    int i = 0;
    while(str.size() < 1100) {
        i++;
        string t = itos(i);
        for (int i = 0; i < t.size(); i++) {
            str.push_back(t[i]);
        }
    }
    int n;
    sa(n);
    printf("%c\n", str[n-1]);
    return 0;
}
