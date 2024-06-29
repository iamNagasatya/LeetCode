class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.length() > num2.length()) swap(num1, num2);
    
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        string res = "";
        int carry = 0;
        
        for(int i=0; i<num1.length(); i++){
            int d1 = num1[i]-'0';
            int d2 = num2[i]-'0';
            int sum = d1+d2+carry;
            carry = sum/10;
            res += ('0'+ sum%10);   
        }
        
        for(int i=num1.length(); i<num2.length(); i++){
            int d2 = num2[i]-'0';
            int sum = d2+carry;
            carry = sum/10;
            res += ('0'+ sum%10);
        }
        if(carry) res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};