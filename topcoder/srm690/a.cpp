#include <string>
using namespace std;
class DoubleString {
    public:
    string check(string str) {
        int len = str.size();
        bool is = true;
        if(len % 2 == 1) is = false;
        string a = str.substr(0, len / 2);
        string b = str.substr(len / 2, len / 2);
        if(a != b) is = false;
        if(is) {
            return "square";
        } else return "not square";
    }
};

