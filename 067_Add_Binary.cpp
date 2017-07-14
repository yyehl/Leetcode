class Solution {
public:
    string addBinary(string a, string b) {
        if (a.empty() && b.empty())   return string("");
        else if (!a.empty() && b.empty())   return a;
        else if (!b.empty() && a.empty())   return b;
        else  ;
        
        string ret = "";
        int i = a.size()-1, j = b.size()-1;
        bool add_one = false;                
        while (i >= 0 && j >= 0)
        {
            if (add_one == false)
            {
                if (a[i] == '0' && b[j] == '0')
                    ret += '0';
                else if ((a[i] == '0' && b[j] == '1') || (a[i] == '1' && b[j] == '0'))
                    ret += '1';
                else
                {
                    ret += '0';
                    add_one = true;
                }
            }
            else
            {
                if (a[i] == '0' && b[j] == '0')
                {
                    ret += '1';
                    add_one  = false;
                }
                else if ((a[i] =='0' && b[j] == '1') || (a[i] == '1' && b[j] == '0'))
                    ret += '0';
                else
                    ret += '1';
            }
            --i;
            --j;
        }
        if (i == -1)
        {
            if (add_one == true)
            {
                while (j >= 0)
                {
                    if (b[j] == '1' && add_one == true)
                        ret += '0';
                    else if (b[j] == '0' && add_one == true)
                    {
                        ret += '1';
                        add_one = false;
                    }
                    else if (b[j] == '1')
                        ret += '1';
                    else 
                        ret += '0';
                    --j;
                }
                if (add_one == true)    ret += '1';
            }
            else 
            {
                while (j >= 0)
                    ret += b[j--];
            }
        }
        else    // j == -1
        {
            if (add_one == true)
            {
                while (i >= 0)
                {
                    if (a[i] == '1' && add_one == true)
                        ret += '0';
                    else if (a[i] == '0' && add_one == true)
                    {
                        ret += '1';
                        add_one = false;
                    }
                    else if (a[i] == '1')
                        ret += '1';
                    else
                        ret += '0';
                    --i;
                }
                if (add_one == true)       ret += '1';
            }
            else 
            {
                while (i >= 0)
                    ret += a[i--];
            }
        }
        string tmp = ret;
        int jj = 0;
        for (int i = tmp.size()-1; i >= 0; --i)     ret[jj++] = tmp[i];
        return ret;
    }
};