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

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
#ifdef LOCAL
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", 'w', stdout);
#endif
    int T;
    scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        int n;
        scanf("%d", &n);
        int a = 0, suma = 0, b = 0, sumb = 0;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            if(x > 0) {
                a++; suma += x;
            } else {
                b++; sumb += -x;
            }
        }
        int p = suma + sumb;
        int q = n - b;
        printf("Case %d: ", Cas);
        if(q == 0) {
            printf("inf\n");
        } else {
            int g = gcd(p, q);
            printf("%d/%d\n", p / g, q / g);
        }
    }
	return 0;
}
