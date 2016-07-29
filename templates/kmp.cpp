void get_next(char x[], int m, int next[]) {
    int i, j;
    j = next[0] = -1;
    i = 0;
    while(i < m) {
        while(j != -1 && x[i] != x[j]) j = next[j];
        next[++i] = ++j;
    }
}

/* 优化版本 */
void get_next_o(char x[], int m, int kmpNext[]) {
    int i, j;
    j = kmpNext[0] = -1;
    i = 0;
    while(i < m) {
        while(j != -1 && x[i] != x[j]) j = kmpNext[j];
        if(x[++i] == x[++j]) kmpNext[i] = kmpNext[j];
        else kmpNext[i] = j;
    }
}

int next[10010];
/* x 为模式串， y 为待匹配串 */
int kmp_count(char x[], int m, char y[], int n) {
    int i, j;
    int ans = 0;
    get_next(x, m, next);
    i = j = 0;
    while(i < n) {
        while(j != -1 && y[i] != x[j]) j = next[j];
        i++; j++;
        if(j >= m) {
            ans++;
            j = next[j];
        }
    }
    return ans;
}
