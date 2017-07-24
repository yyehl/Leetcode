class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (!n)   return vector<string>();
        vector<string> ret;
        queue<string> qs;
        qs.push("(");
        for (int i = 0; i < 2*n-1; ++i)
        {
            while (qs.front().size() == i+1)
            {
                qs.push(qs.front() + "(");
                qs.push(qs.front() + ")");
                qs.pop();
            }
        }
        while (!qs.empty())
        {
            string str = qs.front();
            qs.pop();
            stack<char> sc;
            for (int i = 0; i < str.size(); i++)
            {
                if (sc.empty()) sc.push(str[i]);
                else if (str[i] == ')' && sc.top() == '(')
                    sc.pop();
                else   sc.push(str[i]);              
            }
            if (sc.empty())   ret.push_back(str);
        }
        return ret;
    }
};


class Solution1 {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        foo(ret, "", n, 0);
        return ret;
    }
    void foo(vector<string>& ret, string str, int n, int m)
    {
        if (m == 0 && n == 0)
        {
            ret.push_back(str);
            return ;
        }
        if (m > 0)   foo(ret, str + ")", n, m-1);
        if (n > 0)   foo(ret, str + "(", n-1, m+1);
    }
};