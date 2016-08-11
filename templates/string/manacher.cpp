const int MAXN = 1e5 + 5;
struct Manacher {
    char s[MAXN << 1];
    int n, p[MAXN << 1];
    void init(char *a, int len) {
        s[0] = '@'; s[1] = '#'; n = 2;
        for (int i = 0; i < len; i++) {
            s[n++] = a[i];
            s[n++] = '#';
        }
        s[n] = '\0';
    }

    int run() {
        int mx = 0, id = 0, ret = 0;
        for (int i = 1; i < n; i++) {
            p[i] = mx > i ? min(mx - i, p[2 * id - i]) : 1;
            while(s[i - p[i]] == s[i + p[i]]) p[i]++;
            if(i + p[i] > mx) {
                mx = i + p[i];
                id = i;
            }
            ret = max(ret, p[i] - 1);
        }
        return ret;
    }
} manacher;

