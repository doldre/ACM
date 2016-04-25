/************************************************
 *Author        :mathon
 *Created Time  :一  4/25 14:05:20 2016
 *Problem class:
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
vector<int> vi;
#define xx first
#define yy second
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++)
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl



int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int t = (n / 3) * 2;
    if(n % 3 != 0) t++;
    cout << t << endl;
    return 0;
}
