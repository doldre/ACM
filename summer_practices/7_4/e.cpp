
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
#define pr(x) cout << #x << " = " << x << " " 
#define prln(x) cout << #x << " = " << x << endl
typedef pair<int, int> pii;
typedef long long ll;
int main() {
#ifdef LOCAL
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", 'w', stdout);
#endif
    string s1, s2;
    while(cin >> s1 >> s2) {
        int len1 = (int)s1.size(), len2 = (int)s2.size();
        if(len1 > len2) {
            int d = len1 - len2;
            for (int i = 0; i < d; i++) {
                printf("d %c\n", s1[i]);
            }
            for (int i = 0; i < len2; i++) {
                printf("m %c\n", s2[i]);
            }
        } else {
            int d = len2 - len1;
            for (int i = 0; i < d; i++) {
                printf("a %c\n", s2[i]);
            }
            for (int i = d; i < len2; i++) {
                printf("m %c\n", s2[i]);
            }
        }
    }
	return 0;
}
