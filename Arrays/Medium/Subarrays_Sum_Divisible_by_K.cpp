class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0;
        int count = 0;
        unordered_map <int,int> mp;
        mp[0] = 1;
        
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            int mod = sum%k;
            if(mod < 0) mod += k;

            if(mp.find(mod) != mp.end())
            {
                count += mp[mod];
                mp[mod]++;
            }
            else mp[mod] = 1;
        }

        return count;
    }
};