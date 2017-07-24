class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())  return vector<string>();
        vector<string> ret;
        vector<string> alpha = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<int> index(digits.size());
        for (int i = 0; i < digits.size(); i++)
            index[i] = digits[i] - '0';
        for (int i = 0; i < index.size(); i++)
        {
            string s = alpha[index[i]];
            if (ret.empty())
                for (int j = 0; j < s.size(); j++)  ret.push_back(string(1, s[j]));
            else
            {
                vector<string> tmp;
                for (int j = 0; j < ret.size(); j++)
                    for (int k = 0; k < s.size(); k++)
                        tmp.push_back(ret[j] + s[k]);
                ret = tmp;
            }
        }
        return ret;
    }
};