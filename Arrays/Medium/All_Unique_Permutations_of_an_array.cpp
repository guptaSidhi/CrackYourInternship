class Solution {
  public:
    void solve(int index,vector<int> &arr,set<vector<int>> &ans,int n)
    {
        if(index == n-1)
        {
            ans.insert(arr);
            return;
        }
        
        for(int i=index;i<n;i++)
        {
            swap(arr[index],arr[i]);
            solve(index+1,arr,ans,n);
            swap(arr[index],arr[i]);
        }
    }
    
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        sort(arr.begin(),arr.end());
        set<vector<int>> ans;
        solve(0,arr,ans,n);
        vector<vector<int>> out;
        for(auto it: ans) out.push_back(it);
        return out;
    }
};