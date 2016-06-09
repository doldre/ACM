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

int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
	int l = 1, r = 1000000 + 1;
	while(l < r - 1) {
		int m = (l + r) >> 1;
		printf("%d\n", m);
		fflush(stdout);

		char response[3];
		scanf("%s", response);
		if(strcmp(response, "<") == 0) {
			r = m;
		} else {
			l = m;
		}
	}
	printf("! %d\n", l);
	fflush(stdout);
    return 0;
}
