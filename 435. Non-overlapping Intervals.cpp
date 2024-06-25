const static auto fast = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &left, auto &right) {
            return left[1] < right[1];
        });

        int end = intervals[0][1], res = 1;

        for(int i=1; i<intervals.size(); i++){
            if(end <=intervals[i][0]){
                ++res;
                end = intervals[i][1];
            }
        }

        return intervals.size()-res;
        
    }
};