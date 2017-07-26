class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0)   return INT_MAX;
        if (dividend == INT_MIN && divisor == -1)   return INT_MAX;
        
        int is_pos = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0) ? 1 : -1;
        long long dend = labs(dividend), dsor = labs(divisor);
        long long ret = 0;
        while (dend >= dsor)
        {
            long long first = dsor << 1, second = dsor;
            long long n = 1;
            while (first < dend)
            {
                second = first;
                first <<= 1;
                n <<= 1;
            }
            ret += n;
            dend = dend - second;
        }
        return ret * is_pos;
    }
};