class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty())    return true;
        string str;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
                str.push_back(s[i]);
            else if (s[i] >= 'A' && s[i] <= 'Z')
                str.push_back(s[i]+32);
            else if (s[i] >= '0' && s[i] <= '9')
                str.push_back(s[i]);
            else ;
            
        }
        if (str.empty() || str.size() == 1) return true;
        int left = 0, right = str.size()-1;
        while (left < right)
        {
            if (str[left] != str[right])
                return false;
            else 
            {
                ++left;
                --right;
            }
        }
        return true;
    }
};