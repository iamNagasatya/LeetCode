const static auto fast = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](auto &left, auto &right) {
            return left[1] < right[1];
        });

        int res = 1;
        int x = points[0][0], y = points[0][1];

        for(int i=1; i<points.size(); i++){
            if(y>=points[i][0]){
                x = max(x, points[i][0]);
                y = min(y, points[i][1]);
            }
            else{
                x = points[i][0];
                y = points[i][1];
                ++res;
            }
        }
        return res;
    }
};