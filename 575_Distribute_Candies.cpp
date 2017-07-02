/*
Given an integer array with even length, 
where different numbers in this array represent different kinds of candies. 
Each number means one candy of the corresponding kind. 
You need to distribute these candies equally in number to brother and sister. 
Return the maximum number of kinds of candies the sister could gain. 

*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        sort(candies.begin(), candies.end());
        vector<int>::iterator ptr = unique(candies.begin(), candies.end());
        if (ptr - candies.begin() >= candies.size()/2)
            return candies.size()/2;
        else return ptr - candies.begin();
    }
};