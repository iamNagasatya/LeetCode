const static auto fast = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for( const int & x : nums) ans ^= x;
        return ans;
    }
};