const static auto fast = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans(2);
        int _xor = 0, last_set = 1;
        for(const int & x : nums) _xor ^= x;
        
        while((_xor & last_set) == 0){
            last_set <<= 1;
        }
        
        for(const int &x : nums){
            if(last_set & x) ans[0] ^= x;
            else ans[1] ^= x;
        }
        return ans;
    }
};