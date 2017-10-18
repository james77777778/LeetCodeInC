class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int sum = 0;
        vector<int> numscopy;
        numscopy.assign(nums.begin(), nums.end());
        sort(numscopy.begin(),numscopy.end());
        
        for(int i=0;i<numscopy.size();i+=2)
            sum += numscopy[i];
        
        return sum;
    }
    
};
