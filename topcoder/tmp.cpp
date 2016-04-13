#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1000;
class ExploringNumbers {
public:
    bool isprime(int x) {
        for (int i = 2; i * i <= x; i++) {
            if(x % i == 0) return false;
        }
        return true;
    }
    int next(int n) {
        int res = 0;
        while(n > 0) {
            int t = n % 10;
            res += t * t;
            n /= 10;
        }
        return res;

    }
    int numberOfSteps(int n) {
        int res = 1;
        while(true) {
            if(n == 1) return -1;
            if(isprime(n)) return res;
            res++;
            n = next(n);
        }
        return res;
    }
};
