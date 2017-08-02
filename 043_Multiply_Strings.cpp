class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.empty() || num2.empty())   return string();
        if (num1[0] == '0' || num2[0] == '0')  return string(1, '0');
        int sz1 = num1.size(), sz2 = num2.size();
        string ret(sz1 + sz2, '0');
        for (int i = sz1 - 1; i >= 0; i--)
        {
            int carry = 0;
            for (int j = sz2 - 1; j >= 0; j--)
            {
                int tmp = ret[i+j+1]-'0' + (num1[i]-'0') * (num2[j]-'0') + carry;
                ret[i+j+1] = tmp % 10 + '0';
                carry = tmp / 10;
            }
            ret[i] += carry;
        }
        int i = 0;
        while (ret.front() == '0')   ret.erase(ret.begin());
        return ret;
    }
};