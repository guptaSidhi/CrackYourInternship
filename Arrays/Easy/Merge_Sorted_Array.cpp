class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int first = 0;
        int second = 0;
        int third = 0;
        vector<int> res(nums1.begin(),nums1.begin()+m);

        while(first < m && second < n)
        {
            if(res[first] >=  nums2[second])
            {
                nums1[third] = nums2[second];
                second++;
                third++;
            }
            else
            {
                nums1[third] = res[first];
                third++;
                first++;
            }
        }

        while(first < m)
        {
            nums1[third] = res[first];
            third++;
            first++;
        }

        while(second < n)
        {
            nums1[third] = nums2[second];
            second++;
            third++;
        }
    }
};