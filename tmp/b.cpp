#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;
int main() {
    map<vector<int>, int> mp;
    vector<int> v1,v2;
    v1.push_back(3), v2.push_back(2);
    v1.push_back(3);
    if(v1 > v2) {
        printf(">");
    } else printf("<=");
    return 0;
}
