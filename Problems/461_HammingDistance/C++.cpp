/******************************
//Hamming Distance
//calculate the total numbers of different bits between two integar
//
//Date  : 2017/10/17
//Author: JamesChiou james77777778@gmail.com
******************************/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int dist = 0;
        //Use XOR to find all difference between two integar
        int n = x^y;
        while(n)
        {
        	//There is one difference so dist++
            if(n&1)
                dist++;
            //Move on
            n>>=1;
        }
        return dist;
    }
};
