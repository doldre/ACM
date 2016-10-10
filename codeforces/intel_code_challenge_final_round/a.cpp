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

int M[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string W[] = { "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

int convert(string s) {
    for (int i = 0; i <= 6; i++) {
        if(W[i] == s) return i;
    }
}

string s1, s2;
int a, b;

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin >> s1 >> s2;
    a = convert(s1); b = convert(s2);
    bool flag = false;
    for (int i = 0; i <= 11; i++) {
        if(M[i] % 7 == (b - a + 7) % 7) {
            flag = true;
        }
    }
    if(flag) puts("YES");
    else puts("NO");
    return 0;
}

