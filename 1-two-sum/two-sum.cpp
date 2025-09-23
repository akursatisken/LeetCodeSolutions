class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int>result;
        for(int i=0;i<nums.size();i++)
        {

            for(int x=i+1;x<nums.size();x++)
            {
                if(nums[i]+nums[x]==target)
                {
                    result.push_back(i);
                    result.push_back(x);
                    return result;                    
                }                    
            } 
        } 
        return result;       
    }
};