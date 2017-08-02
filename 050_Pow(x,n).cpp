class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return 0;
        if (n == 0) return 1;
        if (x == 1) return 1;
        if (x == -1 && n%2 == 0)    return 1;
        if (x == -1 && n%2 != 0)    return -1;
        if (n == INT_MIN)   return 0;
        if (n < 0)
        {
            x = 1/x;
            n = -n;
        }
        return (n % 2 == 0) ? myPow(x*x, n/2) : x*myPow(x*x, n/2); 
    }
};