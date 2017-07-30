class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> set;
        for (int i = 0; i < 9; i++)
        {
            set.clear();
            for (int j = 0; j < 9; j++)
            {
                if (set.find(board[i][j]) == set.end())
                    set.insert(board[i][j]);
                else if (board[i][j] != '.')
                    return false;
            }
        }
        for (int i = 0; i < 9; i++)
        {
            set.clear();
            for (int j = 0; j < 9; j++)
            {
                if (set.find(board[j][i]) == set.end())
                    set.insert(board[j][i]);
                else if (board[j][i] != '.')
                    return false;
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                set.clear();
                for (int k = i*3; k < (i+1)*3; k++)
                {
                    for (int l = j*3; l < (j+1)*3; l++)
                    {
                        if (set.find(board[k][l]) == set.end())
                            set.insert(board[k][l]);
                        else if (board[k][l] != '.')
                            return false;
                    }
                }
            }
        }
        return true;
    }
};