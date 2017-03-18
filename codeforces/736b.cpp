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

int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    bool is_prime = true;
    for (int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            is_prime = false;
            break;
        }
    }
    if(is_prime) {
        puts("1");
        return 0;
    } else {
        if(n % 2 == 0) {
            puts("2");
            return 0;
        } else {
            is_prime = true;
            for (int i = 2; i * i <= n - 2; i++) {
                if((n - 2) % i == 0) {
                    is_prime = false;
                    break;
                }
            }
            if(is_prime) {
                puts("2");
            } else {
                puts("3");
            }
        }
    }
    return 0;
}

