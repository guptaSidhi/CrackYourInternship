class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4) return {};
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size()-3;i++)
        {
            if(i != 0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1;j<nums.size()-2;j++)
            {
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                int k = j+1;
                int l = nums.size()-1;
                while(k<l)
                {
                    long long int sum = (long long int)target - nums[i] - nums[j] - nums[k] - nums[l];
                    if(sum == 0) 
                    {
                        vector <int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        temp.push_back(nums[l]);
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(k<l && nums[k] == nums[k-1]) k++;
                        while(k<l && nums[l] == nums[l+1]) l--;
                    }
                    else if(sum > 0) 
                    {
                        k++;
                        while(k<l && nums[k] == nums[k-1]) k++;
                    }
                    else
                    {
                        l--;
                        while(k<l && nums[l] == nums[l+1]) l--;
                    }
                }
            }
        }
        return ans;
    }
};