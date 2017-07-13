class Solution {
public:
    int romanToInt(string s) {
        int ret = 0;
        int value, last_value = 0;
        int len = s.size()-1;
        for (int i = len; i >= 0; --i)
        {
            switch (s[i])
            {
                case 'M':
                    value = 1000;
                    break;
                case 'D':
                    value = 500;
                    break;
                case 'C':
                    value = 100;
                    break;
                case 'L':
                    value = 50;    
                    break;
                case 'X':
                    value = 10;
                    break;
                case 'V':
                    value = 5;
                    break;
                case 'I':
                    value = 1;
                    break;
                default:
                    return -1;
            }
            if (value < last_value)
                ret -= value;
            else 
                ret += value;
            last_value = value;
        }
        return ret;
    }
};