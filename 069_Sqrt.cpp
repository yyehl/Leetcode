class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        long long root = x;
        while (root * root > x)
            root = (x / root + root) / 2;    // 牛顿迭代法
        return root;
    }
};