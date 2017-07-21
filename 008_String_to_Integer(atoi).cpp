class Solution {
public:
    int myAtoi(string str) {
        if (str.empty())    return 0;
        int j = 0;
        while (j < str.size() && str[j] == ' ')  ++j;
        if (str[j] != '-' && str[j] != '+' && !isdigit(str[j]))  return 0;
        int k = str[j] == '-' ? -1 : 1;
        j = isdigit(str[j]) ? j : j+1;
        int i;
        long long ret = 0;
        while (j < str.size())
        {
            if (!isdigit(str[j]))  break;
            else 
            {
                i = str[j] - '0';
                ret = ret * 10 + i;
                if (ret > INT_MAX)  break;
            }
            j++;
        }
        ret = ret * k;
        ret = ret > INT_MAX ? INT_MAX : ret;
        ret = ret < INT_MIN ? INT_MIN : ret;
        return ret;
    }
};