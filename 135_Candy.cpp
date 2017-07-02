#include <vector>
using namespace std;

// O(n^2)  没有通过leetcode   通过了牛客
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candy(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); ++i)
            if (ratings[i] > ratings[i-1])
                candy[i] = candy[i-1] + 1;
            else if (ratings[i] < ratings[i-1])
                for (int j = i; j > 0 && ratings[j] < ratings[j-1] && candy[j] >= candy[j-1]; j--)
                    candy[j-1] = candy[j] + 1;
            else ;
        
        int ret = 0;
        for (int i = 0; i < candy.size(); i++)
            ret += candy[i];
        return ret; 
    }
};

// O(n)
class Solution1 {
public:
    int candy(vector<int>& ratings) {
        vector<int> candy(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); ++i)
            if (ratings[i] > ratings[i-1])
                candy[i] = candy[i-1] + 1;
        
        for (int i = ratings.size()-1; i > 0; --i)
            if (ratings[i] < ratings[i-1] && candy[i] >= candy[i-1])
                candy[i-1] = candy[i] + 1;
        
        int ret = 0;
        for (int i = 0; i < candy.size(); i++)
            ret += candy[i];
        return ret; 
    }
};