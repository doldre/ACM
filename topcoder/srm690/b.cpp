#include <cmath>
#include <vector>
using namespace std;

class GerrymanderEasy {
    public:
    double getmax(vector<int> A, vector<int> B, int k) {
        vector<int> suma(A.size() + 1, 0);
        vector<int> sumb(B.size() + 1, 0);
        for (int i = 1; i <= (int)A.size(); i++) {
            suma[i] = suma[i-1] + A[i-1];
            sumb[i] = sumb[i-1] + B[i-1];
        }
        int len = A.size();
        double ans = 0;
        for (int i = 0; i < len; i++) {
            for (int j = i + k - 1; j < len; j++) {
                int a = suma[j+1] - suma[i];
                int b = sumb[j+1] - sumb[i];
                ans = max(ans, (double(a)/double(b)));
            }
        }
        return ans;
    }
};
