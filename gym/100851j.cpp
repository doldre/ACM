#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <ctime>
using namespace std;

const int MAXN = 1000 + 5;
char str[MAXN];
char ans[MAXN];
int n;
bool ok(int i, int j) {
    int res = true;
    str[i] = !(str[i] - '0') + '0';
    printf("%s\n", str);
    fflush(stdout);
    int t; scanf("%d", &t); res &= t == 0;
    if(t == n) exit(0);
    str[i] = !(str[i] - '0') + '0';
    str[j] = !(str[j] - '0') + '0';
    printf("%s\n", str);
    fflush(stdout);
    scanf("%d", &t); res &= t == 0;
    if(t == n) exit(0);
    str[i] = !(str[i] - '0') + '0';
    printf("%s\n", str);
    fflush(stdout);
    scanf("%d", &t); res &= t == 0;
    if(t == n) exit(0);
    str[i] = !(str[i] - '0') + '0';
    str[j] = !(str[j] - '0') + '0';
    return res;
}

int main() {
    scanf("%d", &n);
    srand(time(NULL)); 
    while(true) {
        for (int i = 0; i < n; i++) {
            str[i] = rand() % 2 + '0';
        }
        printf("%s\n", str);
        fflush(stdout);
        int res; scanf("%d", &res);
        if(res == n) return 0;
        if(res > 0) break;
    }
    int a, b;
    while(true) {
        a = rand() % n, b = rand() % n;
        if(ok(a, b)) break;
    }
    ans[a] = str[a];
    str[a] = !(str[a] - '0') + '0';
    for (int i = 0; i < n; i++) {
        if(i == a) continue;
        str[i] = !(str[i] - '0') + '0';
        printf("%s\n", str);
        fflush(stdout);
        int t; scanf("%d", &t);
        if(t > 0) ans[i] = str[i];
        else ans[i] = !(str[i] - '0') + '0';
        str[i] = !(str[i] - '0') + '0';
    }
    printf("%s\n", ans);
    fflush(stdout);
    int t; scanf("%d", &t);
    if(t == 0) {
        for (int i = 0; i < n; i++) {
            printf("%c", !(ans[i] - '0') + '0');
        }
        printf("\n");
        fflush(stdout);
    }
    return 0;
}

