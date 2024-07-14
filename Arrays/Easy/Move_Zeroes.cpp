class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = -1;
        for(int j=0;j<nums.size();j++)
        {
            if(nums[j] == 0) 
            {
                index = j;
                break;
            }
        }

        if(index == -1) return;

        for(int j=index+1;j<nums.size();j++)
        {
            if(nums[j] != 0)
            {
                swap(nums[index],nums[j]);
                index++;
            }
        }
    }
};