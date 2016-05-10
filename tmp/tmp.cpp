#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class GerrymanderEasy {
    public:
    double getmax(vector<int> A, vector<int> B, int k) {
        int len = A.size();
        vector<int> suma(len + 1, 0), sumb(len + 1, 0);
        for (int i = 0; i < len; i++) {
            suma[i+1] = suma[i] + A[i];
            sumb[i + 1] = sumb[i] + B[i];
        }
        double ans = 0;
        for (int i = 0; i < len; i++) {
            for (int j = i + k - 1; j < len ; j++) {
                ans = max(ans, double(suma[j + 1] - suma[i]) / double(sumb[j + 1] - sumb[i]));
            }
        }
        return ans;
    }
};
int main() {

}
