#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void get_next(const char *str, int *next) {
    int len = strlen(str);
    int i, k;
    next[0] = k = -1;
    for(i = 0; i < len;) {
        if(k == -1 || str[i] == str[k]) {
            k++; i++;
            if(str[k] != str[i]) next[i] = k;
            else next[i] = next[k];
        } else k = next[k];
    }
}
