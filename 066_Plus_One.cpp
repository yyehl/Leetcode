class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        if (digits[len-1] != 9)   
        {
            digits[len-1]++;
            return digits;
        }
        int i = len - 1;
        while (i >= 0)
        {
            digits[i] = (digits[i] + 1) % 10;
            if (digits[i] != 0)     break;
            --i;
        }
        if (i == -1)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};