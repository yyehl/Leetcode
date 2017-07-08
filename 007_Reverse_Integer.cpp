#include <limits.h>

class Solution {
public:
    int reverse(int x) {
        if (x == 0 )  return 0;
        long int ret = 0;
        int input = x;
        bool pos_num = true;
        if (x < 0) 
        {
            pos_num = false;
            input = -1 * x;
        }            
        while (input > 0)
        {
            ret = 10 * ret + (input % 10);
            input = input / 10;
        }
        if (!pos_num)  ret = ret * -1;
        if (ret > INT_MAX || ret < INT_MIN) return 0;
        return ret;
    }
};