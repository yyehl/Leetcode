class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty() || prices.size() == 1)   return 0;
        int ret = 0, diff;
        for (int i = 1; i < prices.size(); i++)
        {
            diff = prices[i] - prices[i-1];
            if (diff > 0)   ret += diff;
        }
        return ret;
    }
};