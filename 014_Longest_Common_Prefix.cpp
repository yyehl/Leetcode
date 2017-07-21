class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return string("");
        int j = strs[0].size()-1, i;
        string ret;
        for (int k = 1; k < strs.size(); k++)
        {
            i = 0;
            while (i <= j && strs[0][i] == strs[k][i])
                ++i;
            j = i - 1;
        }
        for (int i = 0; i <= j; i++)
            ret.push_back(strs[0][i]);
        return ret;
    }
};