class Solution {
public:
    string addBinary(string a, string b) {
        int index1 = a.size()-1, index2 = b.size()-1;
        string ans = "";
        int carry = 0;
        while(index1 >= 0 && index2 >= 0)
        {
            int val1 = a[index1]-'0';
            int val2 = b[index2]-'0';
            int sum = val1 + val2 + carry;
            if(sum == 0) ans += '0';
            else if(sum == 1) ans += '1';
            else if(sum == 2) ans += '0';
            else if(sum == 3) ans += '1';
            carry = sum/2;
            index1--;
            index2--;
        }

        while(index1 >= 0)
        {
            int val1 = a[index1]-'0';
            int sum = val1 + carry;
            if(sum == 0) ans += '0';
            else if(sum == 1) ans += '1';
            else if(sum == 2) ans += '0';
            else if(sum == 3) ans += '1';
            carry = sum/2;
            index1--;
        }

        while(index2 >= 0)
        {
            int val2 = b[index2]-'0';
            int sum = val2 + carry;
            if(sum == 0) ans += '0';
            else if(sum == 1) ans += '1';
            else if(sum == 2) ans += '0';
            else if(sum == 3) ans += '1';
            carry = sum/2;
            index2--;
        }

        while(carry != 0)
        {
            int sum = carry;
            ans += (sum+'0');
            carry = sum/2;
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};