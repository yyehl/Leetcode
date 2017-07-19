class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty() || prices.size() == 1)   return 0;
        
        vector<int> diff(prices.size());
        diff[0] = 0;
        for (int i = 1; i < diff.size(); i++)
            diff[i] = prices[i] - prices[i-1];
        
        int max_prof = 0;
        int sum = 0;
        for (int i = 0; i < diff.size(); i++)
        {
            sum += diff[i];
            if (sum < 0)    sum = 0;
            else    max_prof = max(max_prof, sum);
        }
        return max_prof;
    }
};