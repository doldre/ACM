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
const int maxn = 1000;
string teams[maxn] = {
    "Cleveland Cavaliers",
    "Golden State Warriors",
    "San Antonio Spurs",
    "Miami Heat",
    "Miami Heat",
    "Dallas Mavericks",
    "L.A. Lakers",
    "L.A. Lakers",
    "Boston Celtics",
    "San Antonio Spurs",
    "Miami Heat",
    "San Antonio Spurs",
    "Detroit Pistons",
    "San Antonio Spurs",
    "L.A. Lakers",
    "L.A. Lakers",
    "L.A. Lakers",
    "San Antonio Spurs",
    "Chicago Bulls",
    "Chicago Bulls",
    "Chicago Bulls",
    "Houston Rockets",
    "Houston Rockets",
    "Chicago Bulls",
    "Chicago Bulls",
    "Chicago Bulls",
    "Detroit Pistons",
    "Detroit Pistons",
    "L.A. Lakers",
    "L.A. Lakers",
    "Boston Celtics",
    "L.A. Lakers",
    "Boston Celtics",
    "Philadelphia 76ers",
    "L.A. Lakers",
    "Boston Celtics",
    "L.A. Lakers",
    "Seattle Sonics",
    "Washington Bullets",
    "Portland Trail Blazers",
    "Boston Celtics",
    "Golden State Warriors",
    "Boston Celtics",
    "New York Knicks",
    "L.A. Lakers",
    "Milwaukee Bucks",
    "New York Knicks",
    "Boston Celtics",
    "Boston Celtics",
    "Philadelphia 76ers",
    "Boston Celtics",
    "Boston Celtics",
    "Boston Celtics",
    "Boston Celtics",
    "Boston Celtics",
    "Boston Celtics",
    "Boston Celtics",
    "Boston Celtics",
    "St. Louis Hawks",
    "Boston Celtics",
    "Philadelphia Warriors",
    "Syracuse Nats",
    "Minneapolis Lakers",
    "Minneapolis Lakers",
    "Minneapolis Lakers",
    "Rochester Royals",
    "Minneapolis Lakers",
    "Minneapolis Lakers",
    "Baltimore Bullets",
    "Philadelphia Warriors",
};

char buf[1000];
int main(void) {
#ifdef MATHON
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    getchar();
    for (int Cas = 1; Cas <= T; Cas++) {
        gets(buf);
        string str(buf);
        // prln(str);
        int cnt = 0;
        for (int i = 0; i < 200; i++) {
            if(str == teams[i]) cnt++;
        }
        printf("Case #%d: %d\n", Cas, cnt);
    }
    return 0;
}

