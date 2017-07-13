class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() == 0 && needle.size() == 0)  return 0;
        else if (needle.size() == 0)  return 0;
        else if (haystack.size() == 0)  return -1;
        else if (haystack.size() < needle.size())  return -1;
        else ;
        
        for (int i = 0; i < haystack.size() - needle.size() + 1; i++)
        {
            int j = 0;
            while (j < needle.size() && haystack[i+j] == needle[j])
                ++j;
            if (j == needle.size())
                return i;
        }
        return -1;
    }
};