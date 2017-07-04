// O(n^2)
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        for (int i = 0; i < nums.size(); ++i)
            for (int j = i+1; j < nums.size(); ++j)
            {
                if (nums[i] + nums[j] == target)
                {
                    ret.push_back(i);
                    ret.push_back(j);
                    return ret;
                }
            }
        return ret;
    }
};

// O(nlogn)
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> numap;
        vector<int> ret(2);
        for (int i = 0; i < nums.size(); ++i)
        {
            int x = target - nums[i];
            map<int, int>::iterator iter = numap.find(x);
            if (iter != numap.end())
            {
                ret[0] = iter->second;
                ret[1] = i;
                return ret;
            }
            numap[nums[i]] = i;
        }
        return ret;
    }
};

// O(n)   hashmap
class Solution3 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        unordered_map<int, int> hash;
        
        for (int i = 0; i < nums.size(); i++)
        {
            int x = target - nums[i];
            if (hash.find(x) != hash.end())
            {
                ret.push_back(hash.find(x)->second);
                ret.push_back(i);
                break;
            }
            hash.insert(pair<int, int>(nums[i], i));
        }
        return ret;
    }
};




