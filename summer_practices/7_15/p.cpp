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

string str;
int main(void) {
#ifdef MATHON
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin >> str;
    int len = (int)str.size();
    int start = 0, point = len;
    while(start < len && (str[start] == '0' || 
            str[start] == '.')) start++;
    for (int i = 0; i < len; i++) {
        if(str[i] == '.') {
            point = i;
        }
    }
    int end_int = start;
    for (int i = start; i < len; i++) {
        if(str[i] > '0' && str[i] <= '9') {
            end_int = i;
        }
    }
    if(start == len) {
        printf("0\n");
    } else {
        printf("%c", str[start]);
        if(end_int > start) {
            printf(".");
            for (int i = start + 1; i <= end_int; i++) {
                if(str[i] != '.') {
                    printf("%c", str[i]);
                }
            }
        }
        if(start != point - 1) {
            if(point > start) printf("E%d\n", point - start - 1);
            else printf("E%d\n", point - start);
        } else puts("");
    }
    return 0;
}

