class Solution {
public:
    string convert(string s, int numRows) {
        if (s.empty() || s.size() == 1 || numRows == 1) return s;
        else if (numRows == 0)  return string("");
        else if (numRows == 2)
        {
            string ret;
            for (int i = 0; i < s.size(); i += 2)
                ret.push_back(s[i]);
            for (int j = 1; j < s.size(); j += 2)
                ret.push_back(s[j]);
            return ret;
        }
        else ;
        
        vector<vector<char>> C(numRows, vector<char>(s.size(), ' '));
        int i = 0, j = 0, k = 0;
        while (i < s.size())
        {
            if (k % 2)  // odd
            {
                j = numRows - 2;
                while (i < s.size() && j >= 1)
                    C[j--][k] = s[i++];
            }
            else   // even
            {
                j = 0;
                while (i < s.size() && j < numRows)
                    C[j++][k] = s[i++];
            }
            k++;
        }
        string ret;
        for (int i = 0; i < numRows; i++)
            for (int j = 0; j < k; j++)
                if (C[i][j] != ' ')
                    ret.push_back(C[i][j]);
        return ret;
    }
};