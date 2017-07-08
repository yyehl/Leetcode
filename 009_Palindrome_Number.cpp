class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)   return false;
        
        long long n = 1;
        int num = x;
        while (num)
        {
            num = num / 10;
            n = n * 10;
        }
        n = n / 10;
        while (x)
        {
            if (x / n != x % 10)   return false;
            x = x % n;
            x = x / 10;
            n = n / 100;
        }
        return true;
    }
};