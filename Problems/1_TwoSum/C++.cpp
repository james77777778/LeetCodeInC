class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size()-1;i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    vector<int> result(2,0);
                    result[0] = i; result[1] = j;
                    return result;
                }
                     
            }
        }
        
    }
};
