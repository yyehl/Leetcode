/*
    Write a function that takes a string as input and returns the string reversed.
*/

#include <string>
using namespace std;

class Solution1 {
public:
    string reverseString(string s) {
        string ret;
        for (int i = s.size()-1; i >= 0; --i)
            ret.push_back(s[i]);
        return ret;
    }
};

class Solution2 {
public:
    string reverseString(string s) {
        int len = s.size();
        char p[len+1];
        for (int i = len-1; i >= 0; --i)
            p[len-i-1] = s[i];
        p[len] = '\0';
        string str(p);
        return str;
    }
};