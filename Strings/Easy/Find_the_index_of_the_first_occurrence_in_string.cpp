class Solution {
public:
    int strStr(string haystack, string needle) {
        int index = 0;
        for(int i=0;i<haystack.size();i++)
        {
            int sindex = i;
            if(haystack[i] == needle[index])
            {
                while(i<haystack.size() && index < needle.size() &&haystack[i] == needle[index])
                {
                    index++;
                    i++;
                }
                if(index >= needle.size()) return sindex;
            }
            i = sindex;
            index = 0;
        }
        return -1;
    }
};