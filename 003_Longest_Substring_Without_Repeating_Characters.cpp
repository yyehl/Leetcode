// O(n^2)
class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())  return 0;
        int len = s.size();
        int dp[len];
        dp[0] = 1;
        int ret = 1, j;
        for (int i = 1; i < len; ++i)
        {
            j = 1;
            while (j <= dp[i-1] && s[i] != s[i-j])
                ++j;
            dp[i] = j;
            ret = max(ret, j);
        }
        return ret;
    }
};

// O(n)

class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())  return 0;
        unordered_map<char, int> tb;
        int ret = 1, start = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (tb.find(s[i]) != tb.end())
                start = max(start, tb[s[i]] + 1);
            tb[s[i]] = i;
            ret = max(ret, i - start + 1);
        }
        return ret;
    }
};




