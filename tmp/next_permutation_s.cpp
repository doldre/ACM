#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

const int MAXN = 10;
int A[MAXN], n;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) 
    {
        A[i] = i;
    }
    do 
    {
        for (int i = 1; i <= n; i++) 
        {
            printf("%5d", A[i]);
        }
        printf("\n");
    } while(next_permutation(A + 1, A + n + 1));
    return 0;
}
