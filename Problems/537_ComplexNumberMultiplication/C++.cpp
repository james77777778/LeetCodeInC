/******************************
//Recursive version
//Date  : 2017/10/18
//Author: JamesChiou james77777778@gmail.com
//Ref   :https://discuss.leetcode.com/topic/84382/c-using-stringstream
******************************/
//Use stringstream is very well to parse string
//String form = a+bi          ex:-100+-100i

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int ra, ia, rb, ib;
        char buff;
        stringstream ssa(a), ssb(b), ans;
        //ra = a ; buff = '+' ; ia = b
        ssa >> ra >> buff >> ia;
        //rb = a ; buff = '+' ; ib = b
        ssb >> rb >> buff >> ib;
        
        ans << ra*rb - ia*ib << "+" << ra*ib + rb*ia << "i";
        return ans.str();
    }
};
