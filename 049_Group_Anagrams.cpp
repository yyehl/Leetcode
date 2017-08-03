class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> str = strs;
        for (int i = 0; i < str.size(); i++)
            sort(str[i].begin(), str[i].end());
        multimap<string, int> map;
        for (int i = 0; i < str.size(); i++)
            map.insert(pair<string, int>(str[i], i));
        vector<vector<string>> ret;
        for (auto itr = map.begin(); itr != map.end(); )
        {
            vector<string> tmp;
            string s = itr->first;
            tmp.push_back(strs[itr->second]);
            while ((++itr) != map.end() && s == itr->first)   tmp.push_back(strs[itr->second]);
            ret.push_back(tmp);
        }
        return ret;
    }
};