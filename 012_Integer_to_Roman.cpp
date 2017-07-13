class Solution {
public:
    string intToRoman(int num) {
        vector<string> s1 = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        vector<string> s2 = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        vector<string> s3 = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        vector<string> s4 = {"","M","MM","MMM"};
        
        string ret("");
        ret = ret + s4[num/1000];
        num = num % 1000;
        ret = ret + s3[num/100];
        num = num % 100;
        ret = ret + s2[num/10];
        num = num % 10;
        ret = ret + s1[num];
        
        return ret;
     }
};