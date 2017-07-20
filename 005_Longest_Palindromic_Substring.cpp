class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return string("");
        int dp[s.size()];
        dp[0] = 1;
        int start = 0, end = 0;
        int odd, even, odd_s, even_s, odd_f, even_f;
        for (int i = 1; i < s.size(); i++)
        {
            if (dp[i-1] % 2)
            {
                odd = dp[i-1] + 2;
                even = dp[i-1] + 1;
            }
            else
            {
                odd = dp[i-1] + 1;
                even = dp[i-1] + 2;
            }
            odd_s = i - odd + 1;
            odd_f = i;
            even_s = i - even + 1;
            even_f = i;
            while (odd_s >= 0 && odd_s < odd_f && s[odd_s] == s[odd_f])
            {
                odd_s++;
                odd_f--;
            }
            while (even_s >= 0 && even_s < even_f && s[even_s] == s[even_f])
            {
                even_s++;
                even_f--;
            }
            if (even_s >= even_f && odd_s >= odd_f) 
                dp[i] = max(odd, even);
            else if (even_s >= even_f)
                dp[i] = even;
            else if (odd_s >= odd_f)
                dp[i] = odd;
            else
                dp[i] = dp[i-1];
            
            if (dp[i] != dp[i-1])
            {
                start = i - dp[i] + 1;
                end = i;
            }
        }
        string ret;
        while (start <= end)
        {
             ret.push_back(s[start++]);
        }
        return ret;
    }
};