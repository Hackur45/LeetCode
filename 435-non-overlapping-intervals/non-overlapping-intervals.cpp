class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(),intervals.end(),[](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });
        int cs = 1;
        int endT = intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0] >= endT){
                cs++;
                endT = intervals[i][1];
            }
        }
        return n-cs;
    }
};