#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        vector<string> ret;
        ret.push_back("1");
        int j, k, sz;
        char c;
        string str, last_str;
        for (int i = 1; i < n; ++i)
        {
            j = 0;
            k = 1;
            str = "";
            last_str = ret.back();
            sz = last_str.size();
            c = last_str[j];
            while (j < sz-1)
            {
                if (c == last_str[j+1])
                {
                    ++j;
                    ++k;
                }
                else 
                {
                    str = str + to_string(k) + c;
                    k = 1;
                    ++j;
                    c = last_str[j];
                }
            }
            str = str + to_string(k) + c;
            ret.push_back(str);
        }
        return ret[n-1];
    }
};

int main()
{
    Solution s;
    cout << s.countAndSay(2) << endl << s.countAndSay(3) << endl << s.countAndSay(4) << endl;
    return 0;
}

