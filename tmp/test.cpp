#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int maxn = 1024 * 1024;
char *p[maxn];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        p[i]  = new char[maxn];
        memset(p[i], -1, maxn);
    }
    while(true) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < maxn; j++) {
                p[i][j] = j;
            }
        }
    }
    getchar(); getchar(); getchar();
    return 0;
}
