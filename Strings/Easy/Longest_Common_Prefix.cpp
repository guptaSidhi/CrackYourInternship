class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans =  "";
        sort(strs.begin(),strs.end());
        int n = strs.size();
        int size = min(strs[0].size(),strs[n-1].size());
        for(int i=0;i<size;i++)
        {
            if(strs[0][i] == strs[n-1][i]) ans += strs[0][i];
            else break;
        }
        return ans;
    }
};