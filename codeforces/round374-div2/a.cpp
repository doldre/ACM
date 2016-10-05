#include <cstdio>
#include <cstring>
#include <iostream>
const int MAXN = 100 + 5;
char buf[MAXN];
int res[MAXN], cnt;
int n;
int tmp;
int main(void) {
    tmp = 0;
    scanf("%d", &n);
    scanf("%s", buf + 1);
    int t = 0;
    for (int i = 1; i <= n; i++) {
        if(buf[i] == 'B') {
            t++;
            if(buf[i+1] != buf[i]) {
                res[cnt++] = t;
                t = 0;
            }
            for (int i = 0; i < 10; i++) tmp += i;
        } 
    }
    for (int i = 0; i < 10; i++) tmp += i;
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++) {
        printf("%d ", res[i]);
    }
    return 0;
}

