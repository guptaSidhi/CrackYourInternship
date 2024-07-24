class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
        int low = 0;
        int high = low+1;
        while(high<n)
        {
            if(low == high) high++;
            int diff = abs(arr[high]-arr[low]);
            if(diff == x) return 1;
            else if(diff < x) high++;
            else low++;
        }
        return -1;
    }
};