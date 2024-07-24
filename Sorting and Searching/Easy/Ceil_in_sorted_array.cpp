pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    pair<int,int> ans;
    
    sort(arr,arr+n);
    
    int low = 0;
    int high = n-1;
    int floor_num = -1;
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        if(arr[mid] <= x)
        {
            floor_num = arr[mid];
            low = mid+1;
        }
        else high = mid-1;
    }
    
    low = 0;
    high = n-1;
    int ceil_num = -1;
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        if(arr[mid] >= x)
        {
            ceil_num = arr[mid];
            high = mid-1;
        }
        else low = mid+1;
    }
    
    ans.first = floor_num;
    ans.second = ceil_num;
    
    return ans;
}