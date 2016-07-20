const int AC_SIGMA = 26, AC_N = 210;
struct AC_automaton {
    int next[AC_N][AC_SIGMA], fail[AC_N], end[AC_N];
    int root, L;
    int newnode() {
        for (int i = 0; i < AC_SIGMA; i++) {
            next[L][i] = -1;
        }
        end[L] = 0;
        return L++;
    }

    void init() {
        L = 0;
        root = newnode();
    }

    void insert(char buf[]) {
        int len = strlen(buf);
        int now = root;
        for (int i = 0; i < len; i++) {
            if(next[now][buf[i] - 'a'] == -1) {
                next[now][buf[i] - 'a'] = newnode();
            }
            now = next[now][buf[i] - 'a'];
        }
        end[now] ++;
    }

    void build() {
        queue<int> Q;
        fail[root] = root;
        for (int i = 0; i < AC_SIGMA; i++) {
            if(next[root][i] == -1) {
                next[root][i] = root;
            } else {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        }
        while(!Q.empty()) {
            int now = Q.front();
            Q.pop();
            for (int i = 0; i < 26; i++) {
                if(next[now][i] == -1) {
                    next[now][i] = next[fail[now]][i];
                } else {
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
            }
        }
    }

    int querry(char buf[]) {
        int len = strlen(buf);
        int now = root;
        int res = 0;
        for (int i = 0; i < len; i++) {
            now = next[now][buf[i] - 'a'];
            int temp = now;
            while(temp != root) {
                res += end[temp];
                end[temp] = 0;
                temp = fail[temp];
            }
        }
        return res;
    }
}ac_automaton;


