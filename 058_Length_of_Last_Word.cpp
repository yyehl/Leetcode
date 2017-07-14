class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty())  return 0;
        int ret = 0;
        int last_len = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == ' ' && last_len != 0)
            {
                ret = last_len;
                last_len = 0;
            }
            else if (s[i] ==' ')    ;
            else 
                ++last_len;
        }
        if (last_len)   ret = last_len;
        return ret;
    }
};